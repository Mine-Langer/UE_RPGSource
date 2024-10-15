// copyright  By Langer -- libing044@gmail.com

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HLDamageObject.generated.h"

class UGameplayEffect;

UCLASS()
class RPGSOURCE_API AHLDamageObject : public AActor
{
	GENERATED_BODY()

public:
	AHLDamageObject();

protected:
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;

	void OnTest();
	
private:
	class USceneComponent* RootScene = nullptr;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="RPGSource", meta=(AllowPrivateAccess=true))
	class UBoxComponent* BoxCollision;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="RPGSource", meta=(AllowPrivateAccess=true))
	TSubclassOf<UGameplayEffect> DamageEffect;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="RPGSource", meta=(AllowPrivateAccess=true))
	float Damage;

	FTimerHandle TimerHandle;
};
