// copyright  By Langer -- libing044@gmail.com


#include "GamePlay/HLGameMode.h"

#include "Characters/HLCharacterBase.h"
#include "Kismet/GameplayStatics.h"
#include "Player/HLPlayerController.h"
#include "Player/HLPlayerState.h"

AHLGameMode::AHLGameMode()
{
}

void AHLGameMode::BeginPlay()
{
	Super::BeginPlay();

	if (!SPController)
	{
		InitGameplayModule();
	}
}

void AHLGameMode::InitGameplayModule()
{
	SPController = Cast<AHLPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	SPCharacter = Cast<AHLCharacterBase>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	SPState = Cast<AHLPlayerState>(SPController->PlayerState);

	// FHLGameplayTags::InitializeGameplayTags();
}

void AHLGameMode::SaveGame()
{
}
