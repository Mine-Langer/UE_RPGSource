// copyright  By Langer -- libing044@gmail.com

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "HLGameHUD.generated.h"

class UHLGameHUDWidget;

/**
 * 
 */
UCLASS()
class RPGSOURCE_API AHLGameHUD : public AHUD
{
	GENERATED_BODY()

public:
	AHLGameHUD();

protected:
	virtual void BeginPlay() override;

private:
	// 游戏界面
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = UI, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UUserWidget> GameHUDWidget;

	UHLGameHUDWidget* GameHUD = nullptr;
};
