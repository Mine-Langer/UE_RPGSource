// copyright  By Langer -- libing044@gmail.com

#pragma once

#include "CoreMinimal.h"
#include "RPGSource/Public/Characters/HLCharacterBase.h"
#include "HLHeroCharacter.generated.h"

UCLASS()
class RPGSOURCE_API AHLHeroCharacter : public AHLCharacterBase
{
	GENERATED_BODY()

public:
	AHLHeroCharacter();

protected:
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
protected:
	void MoveForward(float Value);
	void MoveRight(float Value);
	void Turn(float Value);
	void LookUp(float Value);
	void TurnRate(float Value);
	void LookUpRate(float Value);
};
