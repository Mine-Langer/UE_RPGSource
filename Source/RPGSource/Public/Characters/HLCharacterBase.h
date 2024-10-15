// copyright  By Langer -- libing044@gmail.com

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "HLCharacterBase.generated.h"

class UGameplayEffect;
class UHLGameplayAbility;
class UHLAttributeSet;
class UHLAbilitySystemComponent;

UCLASS()
class RPGSOURCE_API AHLCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AHLCharacterBase();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	int32 GetCharacterLevel() const;
	float GetHealth() const;
	float GetMaxHealth() const;
	float GetMana() const;
	float GetMaxMana() const;
	float GetStamina() const;
	float GetMaxStamina() const;
	float GetMoveSpeed() const;
	
	
protected:
	virtual void BeginPlay() override;

	virtual void AddCharacterAbilities();
	virtual void InitializeAttributes();
	virtual void AddStartupEffects();
	virtual void ShowDamageNumber();


	virtual void SetHealth(float Health);
	virtual void SetMana(float Mana);
	virtual void SetStamina(float Stamina);
	
protected:
	UHLAbilitySystemComponent* AbilitySystemComponent = nullptr;

	UHLAttributeSet* HeroAttributes = nullptr;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="RPGSource|Abilities")
	TArray<TSubclassOf<UHLGameplayAbility>> CharacterAbilities;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="RPGSource|Abilities")
	TSubclassOf<UGameplayEffect> DefaultAttributes;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="RPGSource|Abilities")
	TArray<TSubclassOf<UGameplayEffect>> StartupEffects;
};
