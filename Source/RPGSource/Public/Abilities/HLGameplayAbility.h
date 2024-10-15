// copyright  By Langer -- libing044@gmail.com

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "RPGSource/RPGSource.h"
#include "HLGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class RPGSOURCE_API UHLGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
public:
	UHLGameplayAbility();

protected:
	// If an ability is marked as 'ActivateAbilityOnGranted', activate them immediately when given here
	// Epic's comment: Projects may want to initiate passives or do other "BeginPlay" type of logic here.
	virtual void OnAvatarSet(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;

	virtual bool CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags, const FGameplayTagContainer* TargetTags, FGameplayTagContainer* OptionalRelevantTags) const override;

	virtual bool CheckCost(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, FGameplayTagContainer* OptionalRelevantTags) const override;

	virtual void ApplyCost(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo) const override;
	
public:
	FGameplayTag		StartupTag;
	EHLAbilityInputID	AbilityInputID = EHLAbilityInputID::None;
	EHLAbilityInputID	AbilityID = EHLAbilityInputID::None;

	bool bActiveOnInput = true;
};
