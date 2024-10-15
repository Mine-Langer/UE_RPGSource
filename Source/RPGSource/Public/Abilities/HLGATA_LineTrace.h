// copyright  By Langer -- libing044@gmail.com

#pragma once

#include "CoreMinimal.h"
#include "HLGATA_Trace.h"
#include "HLGATA_LineTrace.generated.h"

UCLASS()
class RPGSOURCE_API AHLGATA_LineTrace : public AHLGATA_Trace
{
	GENERATED_BODY()

public:
	AHLGATA_LineTrace();

protected:
	virtual void DoTrace(TArray<FHitResult>& HitResults, const UWorld* World, const FGameplayTargetDataFilterHandle FilterHandle, const FVector& Start, const FVector& End, FName ProfileName, const FCollisionQueryParams Params) override;
	virtual void ShowDebugTrace(TArray<FHitResult>& HitResults, EDrawDebugTrace::Type DrawDebugType, float Duration) override;

	void DrawDebugLineTraceMulti(const UWorld* World, const FVector& Start, const FVector& End, EDrawDebugTrace::Type DrawDebugType, bool bHit, const TArray<FHitResult>& OutHits, FLinearColor TraceColor, FLinearColor TraceHitColor, float DrawTime);
};
