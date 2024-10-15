// copyright  By Langer -- libing044@gmail.com

#pragma once

#include "CoreMinimal.h"
#include "Abilities/HLGameplayAbility.h"
#include "HLGA_AttackFire.generated.h"

class AHLWeapon;
/**
 * 
 */
UCLASS()
class RPGSOURCE_API UHLGA_AttackFire : public UHLGameplayAbility
{
	GENERATED_BODY()

public:
	UHLGA_AttackFire();

protected:
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	// 初始化控件
	bool Initialize();
	
private:
	AHLWeapon* SourceWeapon = nullptr;
	
};
