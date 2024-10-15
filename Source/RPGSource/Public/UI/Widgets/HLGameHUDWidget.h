// copyright  By Langer -- libing044@gmail.com

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HLGameHUDWidget.generated.h"

/**
 * 
 */
UCLASS()
class RPGSOURCE_API UHLGameHUDWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void UpdateStateWidget(float Health, float Mana);

protected:
	virtual bool Initialize() override;

private:
	class UProgressBar* ProgressBarHealth;
	class UProgressBar* ProgressBarMana;
	class UProgressBar* ProgressBarStamina;
};
