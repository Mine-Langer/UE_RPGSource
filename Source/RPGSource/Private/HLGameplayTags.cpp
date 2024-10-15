#include "HLGameplayTags.h"

#include "GameplayTagsManager.h"

FHLGameplayTags FHLGameplayTags::Instance;

const FHLGameplayTags& FHLGameplayTags::Get()
{
	return Instance;
}

void FHLGameplayTags::InitializeGameplayTags()
{
	Instance.DataDamage = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Data.Damage"), FString("Data for Damage."));


	Instance.EffectDamageCanHeadShot = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Effect.Damage.CanHeadShot"), FString("Data for Damage."));
	Instance.EffectDamageHeadShot = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Effect.Damage.HeadShot"));
	
	// ability input tag
	Instance.InputTag_Sprint = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.Sprite"), FString("InputTag for Sprint"));
	Instance.InputTag_Jump = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.Jump"), FString("InputTag for Jump"));
	Instance.InputTag_Fire = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.Fire"), FString("InputTag for Fire"));
}
