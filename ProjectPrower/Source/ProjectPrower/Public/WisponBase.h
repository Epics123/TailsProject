// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponBase.h"
#include "WeaponData.h"
#include "WisponBase.generated.h"

UENUM(BlueprintType)
enum class EWisponType
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
	TEnumAsByte<EWisponType> GetWisponType() { return CurrentWisponType; }

	UFUNCTION(BlueprintCallable)
	void SetWisponType(TEnumAsByte<EWisponType> Type) { CurrentWisponType = Type; }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	UWeaponData* GetCurrentWeaponData() { return WeaponDataMap[CurrentWisponType]; }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool IsInAltFire() { return bIsAltFireActive; }

	UFUNCTION(BlueprintCallable)
	void SetAltFire(bool IsActive) { bIsAltFireActive = IsActive; }

	virtual void FireWeapon(bool bIsAltFire = false) override;

	virtual void PostFireWeapon() override;

	void FireLaser(const bool bIsAltFire);


public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	EWisponType DefaultWisponType = EWisponType::LASER;

	UPROPERTY(EditDefaultsOnly)
	TMap<TEnumAsByte<EWisponType>, TObjectPtr<UWeaponData>> WeaponDataMap;

private:
	EWisponType CurrentWisponType;

	bool bIsAltFireActive = false;
};
