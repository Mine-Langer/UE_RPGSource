// copyright  By Langer -- libing044@gmail.com


#include "Abilities/AbilityInst/HLGA_AttackFire.h"

#include "Weapons/HLWeapon.h"

UHLGA_AttackFire::UHLGA_AttackFire()
{
	AbilityInputID = EHLAbilityInputID::Fire;
	AbilityID = EHLAbilityInputID::Fire;
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
}

void UHLGA_AttackFire::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                       const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                       const FGameplayEventData* TriggerEventData)
{
	Initialize();
	
}

bool UHLGA_AttackFire::Initialize()
{
	if (!SourceWeapon)
		SourceWeapon = Cast<AHLWeapon>(GetCurrentSourceObject());


	return true;
}
