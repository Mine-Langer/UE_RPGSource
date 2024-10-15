// copyright  By Langer -- libing044@gmail.com

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "Abilities/AttributeSets/HLAttributeSet.h"
#include "GameFramework/PlayerState.h"
#include "HLPlayerState.generated.h"

DECLARE_DELEGATE_TwoParams(FUpdateState, float, float);

class UHLAttributeSet;
class UHLAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class RPGSOURCE_API AHLPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AHLPlayerState();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UHLAttributeSet* GetAttributeSet() const;

	float GetHealth() const;
	float GetMaxHealth() const;
	float GetMana() const;
	float GetMaxMana() const;
	float GetStamina() const;
	float GetMaxStamina() const;
	float GetMoveSpeed() const;
	int32 GetCharacterLevel() const;
	int32 GetXP() const;
	int32 GetGold() const;
	
	// 更新状态的代理
	FUpdateState	UpdateStateWidget;
	
protected:
	virtual void BeginPlay() override;

	
	virtual void HealthChanged(const FOnAttributeChangeData& Data);
	
protected:
	UHLAbilitySystemComponent* AbilitySystemComponent;
	UHLAttributeSet* AttributeSet;


};
