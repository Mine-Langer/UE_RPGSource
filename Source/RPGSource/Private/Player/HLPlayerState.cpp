// copyright  By Langer -- libing044@gmail.com


#include "Player/HLPlayerState.h"

#include "Abilities/HLAbilitySystemComponent.h"

AHLPlayerState::AHLPlayerState()
{
	NetUpdateFrequency = 100.f;

	AbilitySystemComponent = CreateDefaultSubobject<UHLAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
}

UAbilitySystemComponent* AHLPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
