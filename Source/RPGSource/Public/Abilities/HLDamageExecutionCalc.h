// copyright  By Langer -- libing044@gmail.com

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "HLDamageExecutionCalc.generated.h"

/**
 * 
 */
UCLASS()
class RPGSOURCE_API UHLDamageExecutionCalc : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()

public:
	UHLDamageExecutionCalc();

	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;

protected:
	float HeadShotMultiplier;
};
