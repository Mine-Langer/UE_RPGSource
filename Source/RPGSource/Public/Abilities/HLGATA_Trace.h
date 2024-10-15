// copyright  By Langer -- libing044@gmail.com

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbilityTargetActor.h"
#include "Kismet/KismetSystemLibrary.h"
#include "HLGATA_Trace.generated.h"

UCLASS()
class RPGSOURCE_API AHLGATA_Trace : public AGameplayAbilityTargetActor
{
	GENERATED_BODY()

public:
	AHLGATA_Trace();

	virtual void ResetSpread();

	virtual float GetCurrentSpread() const;

	virtual void SetShouldProduceTargetDataOnServer(bool bInShouldProduceTargetDataOnServer);

	virtual void LineTraceWithFilter(TArray<FHitResult>& OutHits, const UWorld* World, const FGameplayTargetDataFilterHandle FilterHandle,
		const FVector& Start, const FVector& End, FName ProfileName, const FCollisionQueryParams& TraceParams);

	virtual void AimWithPlayerController(const AActor* InSourceActor, FCollisionQueryParams Params, const FVector& TraceStart, FVector& OutTraceEnd, bool bIgnorePitch=false);

	virtual bool ClipCameraRayToAbilityRange(FVector CameraLocation, FVector CameraDirection, FVector AbilityCenter, float AbilityRange, FVector& ClippedPosition);

	virtual void StopTargeting();
	
	void SetStartLocation(const FGameplayAbilityTargetingLocationInfo& InStartLocation);

	void SetDestroyOnConfirmation(bool bInDestroyOnConfirmation = false);
	
protected:
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
	virtual void Tick(float DeltaTime) override;

	virtual void StartTargeting(UGameplayAbility* Ability) override;

	virtual void ConfirmTargetingAndContinue() override;

	virtual void CancelTargeting() override;

	virtual FGameplayAbilityTargetDataHandle MakeTargetData(const TArray<FHitResult>& HitResults) const;
	virtual TArray<FHitResult> PerformTrace(AActor* InSourceActor);
	virtual void DoTrace(TArray<FHitResult>& HitResults, const UWorld* World, const FGameplayTargetDataFilterHandle FilterHandle,
		const FVector& Start, const FVector& End, FName ProfileName, const FCollisionQueryParams Params) PURE_VIRTUAL(AHLGATA_Trace,return;);
	virtual void ShowDebugTrace(TArray<FHitResult>& HitResults, EDrawDebugTrace::Type DrawDebugType, float Duration=2.f) PURE_VIRTUAL(AHLGATA_Trace,return;);
	virtual AGameplayAbilityWorldReticle* SpawnReticleActor(FVector Location, FRotator Rotation);
	virtual void DestroyReticleActors();
	
protected:
	float BaseSpread = 0.f;
	float AimingSpreadMod = 0.f;
	float TargetingSpreadIncrement = 0.f;
	float TargetingSpreadMax = 0.f;
	float CurrentTargetingSpread = 0.f;
	bool bUseAimingSpreadMod = false;
	FGameplayTag AimingTag;
	FGameplayTag AimingRemovalTag;
	float MaxRange = 999999.f;
	FCollisionProfileName TraceProfile;
	bool bTraceAffectsAimPitch = true;
	int32 MaxHitResultsPerTrace = 1;
	int32 NumberOfTraces = 1;
	bool bIgnoreBlockingHits = false;
	bool bTraceFromPlayerViewPoint = false;
	bool bUsePersistentHitResults = false;

	FVector CurrentTraceEnd;
	TArray<TWeakObjectPtr<AGameplayAbilityWorldReticle>> ReticleActors;
	TArray<FHitResult> PersistentHitResults;
};
