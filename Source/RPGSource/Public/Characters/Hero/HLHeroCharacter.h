// copyright  By Langer -- libing044@gmail.com

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "RPGSource/Public/Characters/HLCharacterBase.h"
#include "Weapons/HLWeapon.h"
#include "HLHeroCharacter.generated.h"

class AHLWeapon;

USTRUCT()
struct RPGSOURCE_API FHLHeroInventory
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	TArray<AHLWeapon*> Weapons;

	// 启动属性
};

UCLASS()
class RPGSOURCE_API AHLHeroCharacter : public AHLCharacterBase
{
	GENERATED_BODY()

public:
	AHLHeroCharacter();

	FName GetWeaponAttchPoint() const;
	
	void EquipWeapon(AHLWeapon* NewWeapon);
	
protected:
	virtual void BeginPlay() override;

	virtual void PossessedBy(AController* NewController) override;

	virtual void OnRep_PlayerState() override;
	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void PostInitializeComponents() override;
	
protected:
	void MoveForward(float Value);
	void MoveRight(float Value);
	void Turn(float Value);
	void LookUp(float Value);
	void TurnRate(float Value);
	void LookUpRate(float Value);

	void InitAbilityActorInfo();
	void BindASCInput();

	// 生成默认装备
	void SpawnDefaultInventory();

	bool AddWeaponToInventory(AHLWeapon* NewWeapon, bool bEquipWeapon = false);

	void SetCurrentWeapon(AHLWeapon* NewWeapon, AHLWeapon* LastWeapon);

	void UnEquipWeapon(AHLWeapon* WeaponToUnEquip);
	
public:
	FGameplayTag CurrentWeaponTag;
	
private:
	bool bASCInputBound = false;
	
	UPROPERTY(BlueprintReadOnly, Category="RPGSOURCE|Camera", meta=(AllowPrivateAccess="true"))
	class USpringArmComponent* CameraBoom;

	UPROPERTY(BlueprintReadOnly, Category="RPGSOURCE|Camera", meta=(AllowPrivateAccess="true"))
	class UCameraComponent* Camera;

	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category="RPGSOURCE|UI", meta=(AllowPrivateAccess="true"))
	class UWidgetComponent* UIFloatingStatusBarComponent;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="RPGSOURCE|HeroCharacter", meta=(AllowPrivateAccess="true"))
	FName WeaponAttachPoint;
	
	// 装备栏
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="RPGSOURCE|Inventory", meta=(AllowPrivateAccess="true"))
	TArray<TSubclassOf<AHLWeapon>> DefaultInventoryWeapons;

	
	AHLWeapon* CurrentWeapon = nullptr;

	FHLHeroInventory Inventory;
};
