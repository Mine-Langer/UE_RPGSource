// copyright  By Langer -- libing044@gmail.com

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/EngineSubsystem.h"
#include "HLEngineSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class RPGSOURCE_API UHLEngineSubsystem : public UEngineSubsystem
{
	GENERATED_BODY()
public:
	UHLEngineSubsystem();

protected:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
};
