// copyright  By Langer -- libing044@gmail.com


#include "Abilities/HLGATA_LineTrace.h"

#include "DrawDebugHelpers.h"


// Sets default values
AHLGATA_LineTrace::AHLGATA_LineTrace()
{
	
}

void AHLGATA_LineTrace::DoTrace(TArray<FHitResult>& HitResults, const UWorld* World,
	const FGameplayTargetDataFilterHandle FilterHandle, const FVector& Start, const FVector& End, FName ProfileName,
	const FCollisionQueryParams Params)
{
	LineTraceWithFilter(HitResults, World, FilterHandle, Start, End, ProfileName, Params);
}

void AHLGATA_LineTrace::ShowDebugTrace(TArray<FHitResult>& HitResults, EDrawDebugTrace::Type DrawDebugType,
	float Duration)
{
	if (bDebug)
	{
		FVector ViewStart = StartLocation.GetTargetingTransform().GetLocation();
		FRotator ViewRot;
		if (MasterPC && bTraceFromPlayerViewPoint)
		{
			MasterPC->GetPlayerViewPoint(ViewStart, ViewRot);
		}

		FVector TraceEnd = HitResults[0].TraceEnd;
		if (NumberOfTraces > 1 || bUsePersistentHitResults)
		{
			TraceEnd = CurrentTraceEnd;
		}

		DrawDebugLineTraceMulti(GetWorld(), ViewStart, TraceEnd, DrawDebugType, true, HitResults, FLinearColor::Green, FLinearColor::Red, Duration);
	}
}

void AHLGATA_LineTrace::DrawDebugLineTraceMulti(const UWorld* World, const FVector& Start, const FVector& End,
	EDrawDebugTrace::Type DrawDebugType, bool bHit, const TArray<FHitResult>& OutHits, FLinearColor TraceColor,
	FLinearColor TraceHitColor, float DrawTime)
{
	if (DrawDebugType != EDrawDebugTrace::None)
	{
		bool bPersistent = DrawDebugType == EDrawDebugTrace::Persistent;
		float LifeTime = (DrawDebugType == EDrawDebugTrace::ForDuration) ? DrawTime : 0.f;

		// @fixme, draw line with thickness = 2.f?
		if (bHit && OutHits.Last().bBlockingHit)
		{
			// Red up to the blocking hit, green thereafter
			FVector const BlockingHitPoint = OutHits.Last().ImpactPoint;
			::DrawDebugLine(World, Start, BlockingHitPoint, TraceColor.ToFColor(true), bPersistent, LifeTime);
			::DrawDebugLine(World, BlockingHitPoint, End, TraceHitColor.ToFColor(true), bPersistent, LifeTime);
		}
		else
		{
			// no hit means all red
			::DrawDebugLine(World, Start, End, TraceColor.ToFColor(true), bPersistent, LifeTime);
		}

		// draw hits
		for (int32 HitIdx = 0; HitIdx < OutHits.Num(); ++HitIdx)
		{
			FHitResult const& Hit = OutHits[HitIdx];
			::DrawDebugPoint(World, Hit.ImpactPoint, 16.0f, (Hit.bBlockingHit ? TraceColor.ToFColor(true) : TraceHitColor.ToFColor(true)), bPersistent, LifeTime);
		}
	}
}

