// copyright  By Langer -- libing044@gmail.com


#include "UI/HUD/HLGameHUD.h"
#include "UI/Widgets/HLGameHUDWidget.h"

AHLGameHUD::AHLGameHUD()
{
	
}

void AHLGameHUD::BeginPlay()
{
	Super::BeginPlay();
	
	if (GEngine && GEngine->GameViewport)
	{
		UHLGameHUDWidget* GameHUD = CreateWidget<UHLGameHUDWidget>(GetWorld()->GetGameInstance(), GameHUDWidget);
		if (GameHUD)
		{
			GameHUD->AddToViewport();
		}
	}
}
