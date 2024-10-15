// copyright  By Langer -- libing044@gmail.com


#include "UI/Widgets/HLGameHUDWidget.h"

#include "Components/ProgressBar.h"
#include "Player/HLPlayerState.h"

bool UHLGameHUDWidget::Initialize()
{
	Super::Initialize();

	ProgressBarHealth = Cast<UProgressBar>(GetWidgetFromName(FName("ProgressBar_Health")));
	ProgressBarMana = Cast<UProgressBar>(GetWidgetFromName(FName("ProgressBar_Mana")));
	ProgressBarStamina = Cast<UProgressBar>(GetWidgetFromName(FName("ProgressBar_Stamina")));

	
	return true;
}

void UHLGameHUDWidget::UpdateStateWidget(float Health, float Mana)
{
	AHLPlayerState* PS = Cast<AHLPlayerState>(GetOwningPlayer()->PlayerState);
	
	ProgressBarHealth->SetPercent(PS->GetHealth() / PS->GetMaxHealth());
}
