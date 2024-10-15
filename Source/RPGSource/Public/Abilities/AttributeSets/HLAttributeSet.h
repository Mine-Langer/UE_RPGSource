// copyright  By Langer -- libing044@gmail.com

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "HLAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class RPGSOURCE_API UHLAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UHLAttributeSet();

	UPROPERTY(BlueprintReadOnly, Category="Health", ReplicatedUsing=OnRep_Health)
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UHLAttributeSet, Health);

	UPROPERTY(BlueprintReadOnly, Category="Health", ReplicatedUsing=OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UHLAttributeSet, MaxHealth);

	UPROPERTY(BlueprintReadOnly, Category="Health", ReplicatedUsing=OnRep_HealthRegenRate)
	FGameplayAttributeData HealthRegenRate;
	ATTRIBUTE_ACCESSORS(UHLAttributeSet, HealthRegenRate);

	UPROPERTY(BlueprintReadOnly, Category="Mana", ReplicatedUsing=OnRep_Mana)
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UHLAttributeSet, Mana);

	UPROPERTY(BlueprintReadOnly, Category="Mana", ReplicatedUsing=OnRep_MaxMana)
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UHLAttributeSet, MaxMana);

	UPROPERTY(BlueprintReadOnly, Category="Mana", ReplicatedUsing=OnRep_ManaRegenRate)
	FGameplayAttributeData ManaRegenRate;
	ATTRIBUTE_ACCESSORS(UHLAttributeSet, ManaRegenRate);

	UPROPERTY(BlueprintReadOnly, Category="Stamina", ReplicatedUsing=OnRep_Stamina)
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(UHLAttributeSet, Stamina);

	UPROPERTY(BlueprintReadOnly, Category="Stamina", ReplicatedUsing=OnRep_MaxStamina)
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS(UHLAttributeSet, MaxStamina);
	
	UPROPERTY(BlueprintReadOnly, Category="Stamina", ReplicatedUsing=OnRep_StaminaRegenRate)
	FGameplayAttributeData StaminaRegenRate;
	ATTRIBUTE_ACCESSORS(UHLAttributeSet, StaminaRegenRate);
	

	UPROPERTY(BlueprintReadOnly, Category="Damage")
	FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS(UHLAttributeSet, Damage);

	UPROPERTY(BlueprintReadOnly, Category="Armor")
	FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS(UHLAttributeSet, Armor);

	UPROPERTY(BlueprintReadOnly, Category="Speed", ReplicatedUsing=OnRep_Speed)
	FGameplayAttributeData Speed;
	ATTRIBUTE_ACCESSORS(UHLAttributeSet, Speed);

	UPROPERTY(BlueprintReadOnly, Category="Level", ReplicatedUsing=OnRep_Level)
	FGameplayAttributeData Level;
	ATTRIBUTE_ACCESSORS(UHLAttributeSet, Level);

	UPROPERTY(BlueprintReadOnly, Category="XP", ReplicatedUsing=OnRep_XP)
	FGameplayAttributeData XP;
	ATTRIBUTE_ACCESSORS(UHLAttributeSet, XP);

	UPROPERTY(BlueprintReadOnly, Category="Gold", ReplicatedUsing=OnRep_Gold)
	FGameplayAttributeData Gold;
	ATTRIBUTE_ACCESSORS(UHLAttributeSet, Gold);
	
protected:
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION()
	virtual void OnRep_Health(const FGameplayAttributeData& OldHealth);

	UFUNCTION()
	virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth);

	UFUNCTION()
	virtual void OnRep_HealthRegenRate(const FGameplayAttributeData& OldHealthRegenRate);
	
	UFUNCTION()
	virtual void OnRep_Mana(const FGameplayAttributeData& OldMana);

	UFUNCTION()
	virtual void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana);

	UFUNCTION()
	virtual void OnRep_ManaRegenRate(const FGameplayAttributeData& OldManaRegenRate);

	UFUNCTION()
	virtual void OnRep_Stamina(const FGameplayAttributeData& OldStamina);

	UFUNCTION()
	virtual void OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina);

	UFUNCTION()
	virtual void OnRep_StaminaRegenRate(const FGameplayAttributeData& OldStaminaRegenRate);

	UFUNCTION()
	virtual  void OnRep_Speed(const FGameplayAttributeData& OldSpeed);
	
	UFUNCTION()
	virtual void OnRep_Level(const FGameplayAttributeData& OldLevel);

	UFUNCTION()
	virtual void OnRep_XP(const FGameplayAttributeData& OldXP);

	UFUNCTION()
	virtual void OnRep_Gold(const FGameplayAttributeData& OldGold);
};
