// copyright  By Langer -- libing044@gmail.com

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "HLGameMode.generated.h"

/**
 * 
 */
UCLASS()
class RPGSOURCE_API AHLGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AHLGameMode();

	void InitGameplayModule();

	void SaveGame();

protected:
	virtual void BeginPlay() override;

	
public:
	class AHLCharacterBase*		SPCharacter = nullptr;
	class AHLPlayerController*	SPController = nullptr;
	class AHLPlayerState*		SPState = nullptr;
};
