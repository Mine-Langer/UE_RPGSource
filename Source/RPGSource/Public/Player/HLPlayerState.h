// copyright  By Langer -- libing044@gmail.com

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "HLPlayerState.generated.h"

class UHLAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class RPGSOURCE_API AHLPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AHLPlayerState();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	UHLAbilitySystemComponent* AbilitySystemComponent;
};
