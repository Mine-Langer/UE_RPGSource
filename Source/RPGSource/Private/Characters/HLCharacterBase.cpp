// copyright  By Langer -- libing044@gmail.com


#include "Characters/HLCharacterBase.h"

#include "Abilities/HLAbilitySystemComponent.h"


AHLCharacterBase::AHLCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
}

UAbilitySystemComponent* AHLCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AHLCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}


