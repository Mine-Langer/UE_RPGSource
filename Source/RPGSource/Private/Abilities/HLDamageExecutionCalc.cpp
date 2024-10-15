// copyright  By Langer -- libing044@gmail.com


#include "Abilities/HLDamageExecutionCalc.h"

#include "AbilitySystemComponent.h"
#include "HLGameplayTags.h"
#include "Abilities/AttributeSets/HLAttributeSet.h"

struct HLDamageStatics
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(Armor);
	DECLARE_ATTRIBUTE_CAPTUREDEF(Damage);

	HLDamageStatics()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UHLAttributeSet, Damage, Source, true);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UHLAttributeSet, Armor, Target, false);
	}
};

static const HLDamageStatics& DamageStatics()
{
	static HLDamageStatics DamageStatics;
	return DamageStatics;
}

UHLDamageExecutionCalc::UHLDamageExecutionCalc()
{
	HeadShotMultiplier = 1.5f;
	
	RelevantAttributesToCapture.Add(DamageStatics().DamageDef);
	RelevantAttributesToCapture.Add(DamageStatics().ArmorDef);
}

void UHLDamageExecutionCalc::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams,
	FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	Super::Execute_Implementation(ExecutionParams, OutExecutionOutput);

	UAbilitySystemComponent* TargetASC = ExecutionParams.GetTargetAbilitySystemComponent();
	UAbilitySystemComponent* SourceASC = ExecutionParams.GetSourceAbilitySystemComponent();

	AActor* SourceActor = SourceASC ? SourceASC->GetAvatarActor() : nullptr;
	AActor* TargetActor = TargetASC ? TargetASC->GetAvatarActor() : nullptr;

	const FGameplayEffectSpec& Spec = ExecutionParams.GetOwningSpec();
	FGameplayTagContainer AssetTags;
	Spec.GetAllAssetTags(AssetTags);

	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvaluateParams;
	EvaluateParams.SourceTags = SourceTags;
	EvaluateParams.TargetTags = TargetTags;

	float Armor = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().ArmorDef, EvaluateParams, Armor);
	Armor = FMath::Max<float>(Armor, 0.f);

	float Damage = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().DamageDef, EvaluateParams, Damage);
	Damage += FMath::Max<float>(Spec.GetSetByCallerMagnitude(FHLGameplayTags::Get().DataDamage, false, -1.0f), 0.f);

	float UnmitigatedDamage = Damage;

	const FHitResult* Hit = Spec.GetContext().GetHitResult();
	if(AssetTags.HasTagExact(FHLGameplayTags::Get().EffectDamageCanHeadShot) && Hit && Hit->BoneName == "b_head")
	{
		UnmitigatedDamage *= HeadShotMultiplier;
		FGameplayEffectSpec* MutableSpec = ExecutionParams.GetOwningSpecForPreExecuteMod();
		MutableSpec->DynamicAssetTags.AddTag(FHLGameplayTags::Get().EffectDamageHeadShot);
	}

	float MitigatedDamage = UnmitigatedDamage * (100 /(100+Armor));
	if (MitigatedDamage > 0.f)
	{
		OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(DamageStatics().DamageProperty, EGameplayModOp::Additive, MitigatedDamage));
	}	
}
