// copyright  By Langer -- libing044@gmail.com


#include "Player/HLPlayerState.h"

#include "Abilities/HLAbilitySystemComponent.h"
#include "Abilities/AttributeSets/HLAttributeSet.h"
#include "Characters/Hero/HLHeroCharacter.h"

AHLPlayerState::AHLPlayerState()
{
	NetUpdateFrequency = 100.f;

	AbilitySystemComponent = CreateDefaultSubobject<UHLAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UHLAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* AHLPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UHLAttributeSet* AHLPlayerState::GetAttributeSet() const
{
	return AttributeSet;
}

float AHLPlayerState::GetHealth() const
{
	return AttributeSet->GetHealth();
}

float AHLPlayerState::GetMaxHealth() const
{
	return AttributeSet->GetMaxHealth();
}

float AHLPlayerState::GetMana() const
{
	return AttributeSet->GetMana();
}

float AHLPlayerState::GetMaxMana() const
{
	return AttributeSet->GetMaxMana();
}

float AHLPlayerState::GetStamina() const
{
	return AttributeSet->GetStamina();
}

float AHLPlayerState::GetMaxStamina() const
{
	return AttributeSet->GetMaxStamina();
}

float AHLPlayerState::GetMoveSpeed() const
{
	return AttributeSet->GetSpeed();
}

int32 AHLPlayerState::GetCharacterLevel() const
{
	return AttributeSet->GetLevel();
}

int32 AHLPlayerState::GetXP() const
{
	return AttributeSet->GetXP();
}

int32 AHLPlayerState::GetGold() const
{
	return AttributeSet->GetGold();
}

void AHLPlayerState::BeginPlay()
{
	Super::BeginPlay();

	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetHealthAttribute()).AddUObject(this, &AHLPlayerState::HealthChanged);
	}
}

void AHLPlayerState::HealthChanged(const FOnAttributeChangeData& Data)
{
	AHLHeroCharacter* Hero = Cast<AHLHeroCharacter>(GetPawn());

	UpdateStateWidget.ExecuteIfBound(Data.NewValue, Data.NewValue);
}
