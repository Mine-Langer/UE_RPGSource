// copyright  By Langer -- libing044@gmail.com

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "HLAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class RPGSOURCE_API UHLAssetManager : public UAssetManager
{
	GENERATED_BODY()

public:
	static UHLAssetManager& Get();

protected:
	virtual void StartInitialLoading() override;
};
