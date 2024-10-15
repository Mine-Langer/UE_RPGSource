// copyright  By Langer -- libing044@gmail.com


#include "UI/HUD/HLGameHUD.h"

#include "GamePlay/HLGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Player/HLPlayerState.h"
#include "UI/Widgets/HLGameHUDWidget.h"

AHLGameHUD::AHLGameHUD()
{
	
}

void AHLGameHUD::BeginPlay()
{
	Super::BeginPlay();
	
	if (GEngine && GEngine->GameViewport)
	{
		GameHUD = CreateWidget<UHLGameHUDWidget>(GetWorld()->GetGameInstance(), GameHUDWidget);
		if (GameHUD)
		{
			GameHUD->AddToViewport();
		}
	}

	AHLGameMode* GM = Cast<AHLGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if (!GM)
		return;

	GM->InitGameplayModule();

	GM->SPState->UpdateStateWidget.BindUObject(GameHUD, &UHLGameHUDWidget::UpdateStateWidget);
}
