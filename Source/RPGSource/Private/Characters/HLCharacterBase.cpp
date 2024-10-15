// copyright  By Langer -- libing044@gmail.com


#include "Characters/HLCharacterBase.h"
#include "Abilities/HLGameplayAbility.h"
#include "Abilities/HLAbilitySystemComponent.h"
#include "Abilities/AttributeSets/HLAttributeSet.h"


AHLCharacterBase::AHLCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
}

UAbilitySystemComponent* AHLCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

int32 AHLCharacterBase::GetCharacterLevel() const
{
	if (IsValid(HeroAttributes))
	{
		return HeroAttributes->GetLevel();
	}
	return 0;
}

float AHLCharacterBase::GetHealth() const
{
	if (IsValid(HeroAttributes))
	{
		return HeroAttributes->GetHealth();
	}
	return 0;
}

float AHLCharacterBase::GetMaxHealth() const
{
	if (IsValid(HeroAttributes))
	{
		return HeroAttributes->GetMaxHealth();
	}
	return 0;
}

float AHLCharacterBase::GetMana() const
{
	if (IsValid(HeroAttributes))
	{
		return HeroAttributes->GetMana();
	}
	return 0;
}

float AHLCharacterBase::GetMaxMana() const
{
	if (IsValid(HeroAttributes))
	{
		return HeroAttributes->GetMaxMana();
	}
	return 0;
}

float AHLCharacterBase::GetStamina() const
{
	if (IsValid(HeroAttributes))
	{
		return HeroAttributes->GetStamina();
	}
	return 0;
}

float AHLCharacterBase::GetMaxStamina() const
{
	if (IsValid(HeroAttributes))
	{
		return HeroAttributes->GetMaxStamina();
	}
	return 0;
}

float AHLCharacterBase::GetMoveSpeed() const
{
	if (IsValid(HeroAttributes))
	{
		return HeroAttributes->GetSpeed();
	}
	return 0;
}

void AHLCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AHLCharacterBase::AddCharacterAbilities()
{
	if (GetLocalRole()!=ROLE_Authority || !IsValid(AbilitySystemComponent) || AbilitySystemComponent->bCharacterAbilitiesGiven)
		return;

	for (TSubclassOf<UHLGameplayAbility>& Ability : CharacterAbilities)
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(Ability, 1, static_cast<int32>(Ability.GetDefaultObject()->AbilityInputID), this);
		if (const UHLGameplayAbility* ability = Cast<UHLGameplayAbility>(AbilitySpec.Ability))
		{
			AbilitySpec.DynamicAbilityTags.AddTag(ability->StartupTag);
			AbilitySystemComponent->GiveAbility(AbilitySpec);
		}
	}
	AbilitySystemComponent->bCharacterAbilitiesGiven = true;
}

void AHLCharacterBase::InitializeAttributes()
{
	if (!IsValid(AbilitySystemComponent))
		return;

	if (!DefaultAttributes)
	{
		UE_LOG(LogTemp, Error, TEXT("%s() Missing DefaultAttributes for %s. please fill in the character's blueprint."), *FString(__FUNCTION__), *GetName());
		return;
	}

	FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
	EffectContext.AddSourceObject(this);
	FGameplayEffectSpecHandle EffectSpecHandle = AbilitySystemComponent->MakeOutgoingSpec(DefaultAttributes, 1, EffectContext);
	if (EffectSpecHandle.IsValid())
	{
		AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
	}
}

void AHLCharacterBase::AddStartupEffects()
{
	if (GetLocalRole()!=ROLE_Authority || !IsValid(AbilitySystemComponent) || AbilitySystemComponent->bStartupEffectApplied)
		return;

	FGameplayEffectContextHandle EffectContextHandle = AbilitySystemComponent->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);

	for (TSubclassOf<UGameplayEffect> StartupEffect : StartupEffects)
	{
		FGameplayEffectSpecHandle EffectSpecHandle = AbilitySystemComponent->MakeOutgoingSpec(StartupEffect, 1, EffectContextHandle);
		if (EffectSpecHandle.IsValid())
		{
			AbilitySystemComponent->ApplyGameplayEffectSpecToTarget(*EffectSpecHandle.Data.Get(), AbilitySystemComponent);
		}
	}
	AbilitySystemComponent->bStartupEffectApplied = true;
}

void AHLCharacterBase::ShowDamageNumber()
{
}

void AHLCharacterBase::SetHealth(float Health)
{
	if (IsValid(HeroAttributes))
	{
		HeroAttributes->SetHealth(Health);
	}
}

void AHLCharacterBase::SetMana(float Mana)
{
	if (IsValid(HeroAttributes))
	{
		HeroAttributes->SetMana(Mana);
	}
}

void AHLCharacterBase::SetStamina(float Stamina)
{
	if (IsValid(HeroAttributes))
	{
		HeroAttributes->SetStamina(Stamina);
	}
}


