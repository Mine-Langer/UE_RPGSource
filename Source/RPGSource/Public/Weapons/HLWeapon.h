// copyright  By Langer -- libing044@gmail.com

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameplayAbilitySpec.h"
#include "GameFramework/Actor.h"
#include "HLWeapon.generated.h"

class UHLGameplayAbility;
class AHLHeroCharacter;
class UHLAbilitySystemComponent;

UCLASS()
class RPGSOURCE_API AHLWeapon : public AActor, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:	
	AHLWeapon();

	virtual void Equip();

	virtual void UnEquip();

	virtual void AddAbilities();

	virtual void RemoveAbilities();

	virtual void ResetWeapon();

	void SetOwningCharacter(AHLHeroCharacter* _OwningCharacter);
	
protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	virtual void Tick(float DeltaTime) override;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	virtual void PreReplication(IRepChangedPropertyTracker& ChangedPropertyTracker) override;

	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	
protected:
	UHLAbilitySystemComponent* AbilitySystemComponent = nullptr;

	class UCapsuleComponent* CollisionComponent = nullptr;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="RPGSource|Weapon", meta=(AllowPrivateAccess=true))
	class USkeletalMeshComponent* WeaponMesh = nullptr;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="RPGSource|Weapon", meta=(AllowPrivateAccess=true))
	TArray<TSubclassOf<UHLGameplayAbility>> Abilities;
	
	FVector WeaponMeshEquippedRelativeLocation;

	AHLHeroCharacter* HeroCharacter = nullptr;


	TArray<FGameplayAbilitySpecHandle> AbilitySpecHandles;
};
