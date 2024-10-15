// copyright  By Langer -- libing044@gmail.com


#include "Weapons/HLWeapon.h"

#include "Abilities/HLAbilitySystemComponent.h"
#include "Abilities/HLGameplayAbility.h"
#include "Characters/Hero/HLHeroCharacter.h"
#include "Components/CapsuleComponent.h"

AHLWeapon::AHLWeapon()
{
	PrimaryActorTick.bCanEverTick = true;

	CollisionComponent = CreateDefaultSubobject<UCapsuleComponent>("CollisionComponent");
	CollisionComponent->InitCapsuleSize(50,50);
	CollisionComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	CollisionComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	CollisionComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	RootComponent = CollisionComponent;

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("WeaponMesh");
	WeaponMesh->SetupAttachment(RootComponent);
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	WeaponMesh->CastShadow = true;
	WeaponMesh->SetVisibility(true, true);
	WeaponMesh->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::AlwaysTickPose;
}

void AHLWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

void AHLWeapon::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void AHLWeapon::PreReplication(IRepChangedPropertyTracker& ChangedPropertyTracker)
{
	Super::PreReplication(ChangedPropertyTracker);
}

void AHLWeapon::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}


void AHLWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UAbilitySystemComponent* AHLWeapon::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}


void AHLWeapon::Equip()
{
	if (!HeroCharacter)
		return;

	FName AttachPoint = HeroCharacter->GetWeaponAttchPoint();
	
	if (WeaponMesh)
	{
		WeaponMesh->AttachToComponent(HeroCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, AttachPoint);
		WeaponMesh->CastShadow = true;
		WeaponMesh->bCastHiddenShadow = true;
		WeaponMesh->SetVisibility(true, true);
	}
}

void AHLWeapon::UnEquip()
{
	if (!HeroCharacter)
		return;

	WeaponMesh->DetachFromComponent(FDetachmentTransformRules::KeepRelativeTransform);
	WeaponMesh->CastShadow = false;
	WeaponMesh->bCastHiddenShadow = false;
	WeaponMesh->SetVisibility(false, true);
}

void AHLWeapon::AddAbilities()
{
	if (!IsValid(HeroCharacter) || !IsValid(HeroCharacter->GetAbilitySystemComponent()))
		return;

	UHLAbilitySystemComponent* ASC = Cast<UHLAbilitySystemComponent>(HeroCharacter->GetAbilitySystemComponent());
	if (!ASC)
		return;

	// 给与能力，必须运行在服务端
	if (GetLocalRole() != ROLE_Authority)
		return;

	for (TSubclassOf<UHLGameplayAbility>& Ability : Abilities)
	{
		FGameplayAbilitySpec abilitySpec = FGameplayAbilitySpec(Ability, 1, static_cast<int32>(Ability.GetDefaultObject()->AbilityInputID), this);
		FGameplayAbilitySpecHandle AbilitySpecHandle = ASC->GiveAbility(abilitySpec);
		AbilitySpecHandles.Add(AbilitySpecHandle);
	}
}

void AHLWeapon::RemoveAbilities()
{
	if (!IsValid(HeroCharacter) || !IsValid(HeroCharacter->GetAbilitySystemComponent()))
		return;

	UHLAbilitySystemComponent* ASC = Cast<UHLAbilitySystemComponent>(HeroCharacter->GetAbilitySystemComponent());
	if (!ASC)
		return;

	// 给与能力，必须运行在服务端
	if (GetLocalRole() != ROLE_Authority)
		return;

	for (FGameplayAbilitySpecHandle& AbilitySpecHandle : AbilitySpecHandles)
	{
		ASC->ClearAbility(AbilitySpecHandle);
	}
}

void AHLWeapon::ResetWeapon()
{
}

void AHLWeapon::SetOwningCharacter(AHLHeroCharacter* _OwningCharacter)
{
	HeroCharacter = _OwningCharacter;
	if (HeroCharacter)
	{
		AbilitySystemComponent = Cast<UHLAbilitySystemComponent>(HeroCharacter->GetAbilitySystemComponent());
		SetOwner(HeroCharacter);
		AttachToComponent(HeroCharacter->GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
		CollisionComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
	else
	{
		
	}
}
