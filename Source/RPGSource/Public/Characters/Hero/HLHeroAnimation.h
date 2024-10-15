// copyright  By Langer -- libing044@gmail.com

#pragma once

#include "CoreMinimal.h"
#include "Characters/HLAnimationBase.h"
#include "HLHeroAnimation.generated.h"

/**
 * 
 */
UCLASS()
class RPGSOURCE_API UHLHeroAnimation : public UHLAnimationBase
{
	GENERATED_BODY()
public:
	UHLHeroAnimation();

protected:
	virtual void UpdateParameter() override;

private:
	UPROPERTY(BlueprintReadOnly, Category="Animation", meta=(AllowPrivateAccess=true))
	bool bInAir;
};


