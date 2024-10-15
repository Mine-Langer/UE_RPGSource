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

	FGameplayTag DataDamage;


	FGameplayTag EffectDamageCanHeadShot;
	FGameplayTag EffectDamageHeadShot;
	
private:
	static FHLGameplayTags Instance;
};
