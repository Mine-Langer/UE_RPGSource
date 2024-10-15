// copyright  By Langer -- libing044@gmail.com


#include "Abilities/AttributeSets/HLAttributeSet.h"

#include "Net/UnrealNetwork.h"

UHLAttributeSet::UHLAttributeSet()
{
	InitHealth(80.f);
}

void UHLAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, GetMaxHealth());
	}
	else if (Attribute == GetManaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, GetMaxMana());
	}
	else if (Attribute == GetStaminaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, GetStamina());
	}
}

void UHLAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

void UHLAttributeSet::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UHLAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UHLAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UHLAttributeSet, HealthRegenRate, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UHLAttributeSet, Stamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UHLAttributeSet, MaxStamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UHLAttributeSet, StaminaRegenRate, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UHLAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UHLAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UHLAttributeSet, ManaRegenRate, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UHLAttributeSet, Speed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UHLAttributeSet, XP, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UHLAttributeSet, Level, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UHLAttributeSet, Gold, COND_None, REPNOTIFY_Always);
}

void UHLAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHLAttributeSet, Health, OldHealth);
}

void UHLAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHLAttributeSet, MaxHealth, OldMaxHealth);
}

void UHLAttributeSet::OnRep_HealthRegenRate(const FGameplayAttributeData& OldHealthRegenRate)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHLAttributeSet, HealthRegenRate, OldHealthRegenRate);
}

void UHLAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHLAttributeSet, Mana, OldMana);
}

void UHLAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHLAttributeSet, MaxMana, OldMaxMana);
}

void UHLAttributeSet::OnRep_ManaRegenRate(const FGameplayAttributeData& OldManaRegenRate)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHLAttributeSet, ManaRegenRate, OldManaRegenRate);
}

void UHLAttributeSet::OnRep_Stamina(const FGameplayAttributeData& OldStamina)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHLAttributeSet, Stamina, OldStamina);
}

void UHLAttributeSet::OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHLAttributeSet, MaxStamina, OldMaxStamina);
}

void UHLAttributeSet::OnRep_StaminaRegenRate(const FGameplayAttributeData& OldStaminaRegenRate)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHLAttributeSet, StaminaRegenRate, OldStaminaRegenRate);
}

void UHLAttributeSet::OnRep_Speed(const FGameplayAttributeData& OldSpeed)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHLAttributeSet, Speed, OldSpeed);
}

void UHLAttributeSet::OnRep_Level(const FGameplayAttributeData& OldLevel)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHLAttributeSet, Level, OldLevel);
}

void UHLAttributeSet::OnRep_XP(const FGameplayAttributeData& OldXP)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHLAttributeSet, XP, OldXP);
}

void UHLAttributeSet::OnRep_Gold(const FGameplayAttributeData& OldGold)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHLAttributeSet, Gold, OldGold);
}
