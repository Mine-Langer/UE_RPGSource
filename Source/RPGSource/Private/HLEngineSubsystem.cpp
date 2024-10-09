// copyright  By Langer -- libing044@gmail.com


#include "HLEngineSubsystem.h"

#include "AbilitySystemGlobals.h"
#include "HLGameplayTags.h"

UHLEngineSubsystem::UHLEngineSubsystem()
{
}

void UHLEngineSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	FHLGameplayTags::InitializeGameplayTags();
	
	UAbilitySystemGlobals::Get().InitGlobalData();
}
