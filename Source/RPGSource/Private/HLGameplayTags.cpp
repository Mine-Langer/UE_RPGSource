#include "HLGameplayTags.h"

#include "GameplayTagsManager.h"

FHLGameplayTags FHLGameplayTags::Instance;

const FHLGameplayTags& FHLGameplayTags::Get()
{
	return Instance;
}

void FHLGameplayTags::InitializeGameplayTags()
{
	// ability input tag
	Instance.InputTag_Sprint = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.Sprite"), FString("InputTag for Sprint"));
	Instance.InputTag_Jump = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.Jump"), FString("InputTag for Jump"));
	Instance.InputTag_Fire = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.Fire"), FString("InputTag for Fire"));
}
