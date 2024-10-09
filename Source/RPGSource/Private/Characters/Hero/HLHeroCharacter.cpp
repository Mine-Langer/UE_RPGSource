// copyright  By Langer -- libing044@gmail.com


#include "Characters/Hero/HLHeroCharacter.h"


AHLHeroCharacter::AHLHeroCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AHLHeroCharacter::BeginPlay()
{
	Super::BeginPlay();
	
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

