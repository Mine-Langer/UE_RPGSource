// copyright  By Langer -- libing044@gmail.com


#include "HLAssetManager.h"

#include "HLGameplayTags.h"

UHLAssetManager& UHLAssetManager::Get()
{
	UHLAssetManager* HLAssetManager = Cast<UHLAssetManager>(GEngine->AssetManager);
	return *HLAssetManager;
}

void UHLAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	FHLGameplayTags::InitializeGameplayTags();
}
