// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponBase.h"
#include "WeaponData.h"
#include "WisponBase.generated.h"

static TAutoConsoleVariable<int32> CVarDebugWeaponTraces(
	TEXT("Weapon.DebugWeaponTraces"),
	0,
	TEXT("Set to 1 to show weapon debug traces, 0 otherwise"));

UENUM(BlueprintType)
enum class EWisponType : uint8
{
	LASER = 0	UMETA(DisplayName = "Laser"),
	BURST = 1	UMETA(DisplayName = "Burst"),
	SPIKE = 2	UMETA(DisplayName = "Spike"),
	CUBE = 3	UMETA(DisplayName = "Cube"),
	VOID = 4	UMETA(DisplayName = "Void"),
	HOVER = 5	UMETA(DisplayName = "Hover")
};

/**
 * 
 */
UCLASS()
class PROJECTPROWER_API AWisponBase : public AWeaponBase
{
	GENERATED_BODY()
	
public:
	AWisponBase();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	EWisponType GetWisponType() { return CurrentWisponType; }

	UFUNCTION(BlueprintCallable)
	void SetWisponType(EWisponType Type) { CurrentWisponType = Type; }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	UWeaponData* GetCurrentWeaponData() { return WeaponDataMap[CurrentWisponType]; }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool IsInAltFire() { return bIsAltFireActive; }

	UFUNCTION(BlueprintPure)
	bool ShouldShowDebugTraces() const { return CVarDebugWeaponTraces.GetValueOnGameThread() > 0; }

	UFUNCTION(BlueprintCallable)
	void SetAltFire(bool IsActive) { bIsAltFireActive = IsActive; }

	UFUNCTION(BlueprintImplementableEvent)
	void OnWisponFired(EWisponType WisponType, bool bAltFire);

	virtual void FireWeapon(bool bIsAltFire = false) override;

	virtual void PostFireWeapon() override;


public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	EWisponType DefaultWisponType = EWisponType::LASER;

	UPROPERTY(EditDefaultsOnly)
	TMap<EWisponType, TObjectPtr<UWeaponData>> WeaponDataMap;

private:
	EWisponType CurrentWisponType;

	bool bIsAltFireActive = false;
};
