// copyright  By Langer -- libing044@gmail.com


#include "Characters/HLAnimationBase.h"

#include "Characters/HLCharacterBase.h"

UHLAnimationBase::UHLAnimationBase()
{
}

void UHLAnimationBase::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);

	if (!SPCharacter)
		SPCharacter = Cast<AHLCharacterBase>(TryGetPawnOwner());
	
	UpdateParameter();
}

void UHLAnimationBase::UpdateParameter()
{
	if (!SPCharacter)
		return;

	Speed = SPCharacter->GetVelocity().Size();
}
