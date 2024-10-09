// copyright  By Langer -- libing044@gmail.com

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "HLCharacterBase.generated.h"

class UHLAbilitySystemComponent;

UCLASS()
class RPGSOURCE_API AHLCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AHLCharacterBase();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
protected:
	virtual void BeginPlay() override;


protected:
	UHLAbilitySystemComponent* AbilitySystemComponent;
};
