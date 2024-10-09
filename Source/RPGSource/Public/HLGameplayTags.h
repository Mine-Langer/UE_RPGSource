#pragma once
#include "GameplayTagContainer.h"

struct FHLGameplayTags
{
public:
	static const FHLGameplayTags& Get();
	static void InitializeGameplayTags();

	// ability
	FGameplayTag InputTag_Sprint;
	FGameplayTag InputTag_Jump;
	FGameplayTag InputTag_Fire;
	
private:
	static FHLGameplayTags Instance;
};
