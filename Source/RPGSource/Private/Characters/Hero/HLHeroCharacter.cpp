// copyright  By Langer -- libing044@gmail.com


#include "Characters/Hero/HLHeroCharacter.h"

#include "Abilities/HLAbilitySystemComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Player/HLPlayerState.h"
#include "Weapons/HLWeapon.h"


AHLHeroCharacter::AHLHeroCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
	
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->bUsePawnControlRotation = true;
	CameraBoom->TargetArmLength = 400.f;
	CameraBoom->TargetOffset = FVector(0, 0, 450);
	CameraBoom->SetRelativeLocation(FVector(0, 50, 78));
	
	Camera = CreateDefaultSubobject<UCameraComponent>(FName("CameraComponent"));
	Camera->SetupAttachment(CameraBoom);
	Camera->FieldOfView = 80.f;
}

FName AHLHeroCharacter::GetWeaponAttchPoint() const
{
	return WeaponAttachPoint;
}

void AHLHeroCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AHLHeroCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	InitAbilityActorInfo();
}

void AHLHeroCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	InitAbilityActorInfo();
}

void AHLHeroCharacter::InitAbilityActorInfo()
{
	AHLPlayerState* PS = GetPlayerState<AHLPlayerState>();
	if (PS)
	{
		AbilitySystemComponent = Cast<UHLAbilitySystemComponent>(PS->GetAbilitySystemComponent());

		PS->GetAbilitySystemComponent()->InitAbilityActorInfo(PS, this);

		HeroAttributes = PS->GetAttributeSet();

		InitializeAttributes();

		AddStartupEffects();

		AddCharacterAbilities();

		SetHealth(50);
		SetMana(60);
		SetStamina(GetMaxStamina());
	}
}

void AHLHeroCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AHLHeroCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(FName("MoveForward"), this, &AHLHeroCharacter::MoveForward);
	PlayerInputComponent->BindAxis(FName("MoveRight"), this, &AHLHeroCharacter::MoveRight);
	PlayerInputComponent->BindAxis(FName("Lookup"), this, &AHLHeroCharacter::LookUp);
	PlayerInputComponent->BindAxis(FName("Turn"), this, &AHLHeroCharacter::Turn);
	PlayerInputComponent->BindAxis(FName("LookupRate"), this, &AHLHeroCharacter::LookUpRate);
	PlayerInputComponent->BindAxis(FName("TurnRate"), this, &AHLHeroCharacter::TurnRate);

	BindASCInput();
}

void AHLHeroCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	GetWorldTimerManager().SetTimerForNextTick(this, &AHLHeroCharacter::SpawnDefaultInventory);
}

void AHLHeroCharacter::BindASCInput()
{
	if (!bASCInputBound && IsValid(AbilitySystemComponent) && IsValid(InputComponent))
	{
		FGameplayAbilityInputBinds InputBinds = FGameplayAbilityInputBinds("Confirm", "Cancel", "EHLAbilityInputID");
		AbilitySystemComponent->BindAbilityActivationToInputComponent(InputComponent, InputBinds);
	}
}

void AHLHeroCharacter::SpawnDefaultInventory()
{
	if (GetLocalRole() < ROLE_Authority)
		return;

	int32 NumWeaponClasses = DefaultInventoryWeapons.Num();
	for (int32 i=0; i<NumWeaponClasses; i++)
	{
		if (!DefaultInventoryWeapons[i])
			return;

		AHLWeapon* NewWeapon = GetWorld()->SpawnActorDeferred<AHLWeapon>(DefaultInventoryWeapons[i], FTransform::Identity, this, this, ESpawnActorCollisionHandlingMethod::AlwaysSpawn);

		AddWeaponToInventory(NewWeapon, i==0);
	}
}

bool AHLHeroCharacter::AddWeaponToInventory(AHLWeapon* NewWeapon, bool bEquipWeapon)
{
	if (GetLocalRole() < ROLE_Authority)
		return false;

	Inventory.Weapons.Add(NewWeapon);
	NewWeapon->SetOwningCharacter(this);
	NewWeapon->AddAbilities();
	
	if (bEquipWeapon)
	{
		EquipWeapon(NewWeapon);
	}

	return true;
}

void AHLHeroCharacter::EquipWeapon(AHLWeapon* NewWeapon)
{
	SetCurrentWeapon(NewWeapon, CurrentWeapon);
}

void AHLHeroCharacter::SetCurrentWeapon(AHLWeapon* NewWeapon, AHLWeapon* LastWeapon)
{
	if (NewWeapon == LastWeapon)
		return;

	UnEquipWeapon(LastWeapon);

	if (NewWeapon)
	{
		CurrentWeapon = NewWeapon;
		CurrentWeapon->SetOwningCharacter(this);
		CurrentWeapon->Equip();
	}
}

void AHLHeroCharacter::UnEquipWeapon(AHLWeapon* WeaponToUnEquip)
{
	if (WeaponToUnEquip)
	{
		WeaponToUnEquip->UnEquip();
	}
}

void AHLHeroCharacter::MoveForward(float Value)
{
	if (Controller && Value!=0)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AHLHeroCharacter::MoveRight(float Value)
{
	if (Controller && Value!=0)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}

void AHLHeroCharacter::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void AHLHeroCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

void AHLHeroCharacter::TurnRate(float Value)
{
	const float BaseTurnRate = 45.f;
	AddControllerYawInput(Value * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AHLHeroCharacter::LookUpRate(float Value)
{
	const float BaseLookupRate = 45.f;
	AddControllerPitchInput(Value * BaseLookupRate * GetWorld()->GetDeltaSeconds());
}

