// copyright  By Langer -- libing044@gmail.com


#include "Abilities/AttributeSets/HLAttributeSet.h"

UHLAttributeSet::UHLAttributeSet()
{
}

void UHLAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);
}

void UHLAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

void UHLAttributeSet::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}

void UHLAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
}

void UHLAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
}

void UHLAttributeSet::OnRep_HealthRegenRate(const FGameplayAttributeData& OldHealthRegenRate)
{
}

void UHLAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana)
{
}

void UHLAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana)
{
}

void UHLAttributeSet::OnRep_ManaRegenRate(const FGameplayAttributeData& OldManaRegenRate)
{
}

void UHLAttributeSet::OnRep_Stamina(const FGameplayAttributeData& OldStamina)
{
}

void UHLAttributeSet::OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina)
{
}

void UHLAttributeSet::OnRep_StaminaRegenRate(const FGameplayAttributeData& OldStaminaRegenRate)
{
}

void UHLAttributeSet::OnRep_Speed(const FGameplayAttributeData& OldSpeed)
{
}

void UHLAttributeSet::OnRep_Level(const FGameplayAttributeData& OldLevel)
{
}

void UHLAttributeSet::OnRep_XP(const FGameplayAttributeData& OldXP)
{
}

void UHLAttributeSet::OnRep_Gold(const FGameplayAttributeData& OldGold)
{
}
