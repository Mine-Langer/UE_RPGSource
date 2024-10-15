// copyright  By Langer -- libing044@gmail.com


#include "Characters/Hero/HLHeroAnimation.h"

#include "Characters/HLCharacterBase.h"
#include "GameFramework/PawnMovementComponent.h"

inline UHLHeroAnimation::UHLHeroAnimation()
{
}

inline void UHLHeroAnimation::UpdateParameter()
{
	Super::UpdateParameter();
	
	if (!SPCharacter)
		return;
	
	bInAir = SPCharacter->GetMovementComponent()->IsFalling();

	float PreDir = SPCharacter->GetVelocity().ToOrientationRotator().Yaw - SPCharacter->GetActorRotation().Yaw;
	if (PreDir > 180.f) PreDir-=360.f;
	if (PreDir < -180.f) PreDir+=360.f;
	Direction = PreDir;
}