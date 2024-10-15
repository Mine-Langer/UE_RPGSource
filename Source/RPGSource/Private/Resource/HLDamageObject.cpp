// copyright  By Langer -- libing044@gmail.com


#include "Resource/HLDamageObject.h"

#include "HLGameplayTags.h"
#include "Abilities/HLAbilitySystemComponent.h"
#include "Characters/HLCharacterBase.h"
#include "Characters/Hero/HLHeroCharacter.h"
#include "Components/BoxComponent.h"


// Sets default values
AHLDamageObject::AHLDamageObject()
{
	PrimaryActorTick.bCanEverTick = true;
	
	RootScene = CreateDefaultSubobject<USceneComponent>("RootComponent");
	RootComponent = RootScene;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
	BoxCollision->SetupAttachment(RootComponent);
}

void AHLDamageObject::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(TimerHandle, this, &AHLDamageObject::OnTest, 1.0f, true);
}

void AHLDamageObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// OnTest();
}

void AHLDamageObject::OnTest()
{
	if (HasAuthority())
	{
		TArray<AActor*> OverlappingActors;
		BoxCollision->GetOverlappingActors(OverlappingActors, AHLCharacterBase::StaticClass());

		for (AActor* OverlappingActor : OverlappingActors)
		{
			AHLHeroCharacter* Hero = Cast<AHLHeroCharacter>(OverlappingActor);
			UHLAbilitySystemComponent* ASC = Cast<UHLAbilitySystemComponent>(Hero->GetAbilitySystemComponent());

			FGameplayEffectContextHandle hEffectContext = ASC->MakeEffectContext();
			FGameplayEffectSpecHandle hEffectSpec = ASC->MakeOutgoingSpec(DamageEffect, 1, hEffectContext);
			hEffectSpec.Data->SetSetByCallerMagnitude(FHLGameplayTags::Get().DataDamage, Damage);
			ASC->ApplyGameplayEffectSpecToSelf(*hEffectSpec.Data.Get());
		}
	}
}

