// copyright  By Langer -- libing044@gmail.com


#include "Abilities/AbilityInst/HLGA_CharacterJump.h"
#include "HLGameplayTags.h"
#include "GameFramework/Character.h"

UHLGA_CharacterJump::UHLGA_CharacterJump()
{
	AbilityInputID = EHLAbilityInputID::Jump;
	AbilityID = EHLAbilityInputID::Jump;
	StartupTag = FHLGameplayTags::Get().InputTag_Jump;
	InstancingPolicy = EGameplayAbilityInstancingPolicy::NonInstanced;
}

void UHLGA_CharacterJump::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	if (!CommitAbility(Handle, ActorInfo, ActivationInfo))
	{
		EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, true);
	}

	ACharacter* Character = Cast<ACharacter>(ActorInfo->AvatarActor.Get());
	Character->Jump();
}

bool UHLGA_CharacterJump::CanActivateAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags,
	const FGameplayTagContainer* TargetTags, FGameplayTagContainer* OptionalRelevantTags) const
{
	return Super::CanActivateAbility(Handle, ActorInfo, SourceTags, TargetTags, OptionalRelevantTags);
}

void UHLGA_CharacterJump::InputReleased(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo)
{
	if (ActorInfo!=nullptr && ActorInfo->AvatarActor!=nullptr)
	{
		CancelAbility(Handle, ActorInfo, ActivationInfo, true);
	}
}

void UHLGA_CharacterJump::CancelAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	bool bReplicateCancelAbility)
{
	Super::CancelAbility(Handle, ActorInfo, ActivationInfo, bReplicateCancelAbility);

	ACharacter* Character = Cast<ACharacter>(ActorInfo->AvatarActor.Get());
	Character->StopJumping();
}
