// copyright  By Langer -- libing044@gmail.com

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "HLAbilitySystemComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class RPGSOURCE_API UHLAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	UHLAbilitySystemComponent();

protected:
	virtual void BeginPlay() override;

	virtual void AbilityLocalInputPressed(int32 InputID) override;
	
public:
	bool bCharacterAbilitiesGiven = false;
	bool bStartupEffectApplied = false;
};
