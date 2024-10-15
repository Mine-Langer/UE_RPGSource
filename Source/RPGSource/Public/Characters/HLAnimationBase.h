// copyright  By Langer -- libing044@gmail.com

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "HLAnimationBase.generated.h"

/**
 * 
 */
UCLASS()
class RPGSOURCE_API UHLAnimationBase : public UAnimInstance
{
	GENERATED_BODY()

public:
	UHLAnimationBase();

protected:
	virtual void NativeUpdateAnimation(float DeltaTime) override;

	virtual void UpdateParameter();
	
protected:
	UPROPERTY(BlueprintReadOnly, Category="Animation", meta=(AllowPrivateAccess=true))
	float Direction;

	UPROPERTY(BlueprintReadOnly, Category="Animation", meta=(AllowPrivateAccess=true))
	float Speed;

	class AHLCharacterBase* SPCharacter = nullptr;
};
