// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

#include "PlayerInputData.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTPROWER_API UPlayerInputData : public UDataAsset
{
	GENERATED_BODY()

public:
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Mapping)
	UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Actions)
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Actions)
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Actions)
	UInputAction* LookAction;

	/** Weapon Equip/Unequip Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Actions)
	UInputAction* WeaponEquipAction;

	/** Weapon Aim Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Actions)
	UInputAction* WeaponAimAction;

	/** Weapon Aim End Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Actions)
	UInputAction* WeaponAimEndAction;

	/** Fly Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Actions)
	UInputAction* FlyAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Actions)
	UInputAction* WeaponFireAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Actions)
	UInputAction* WeaponAltFireAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Actions)
	UInputAction* AltFireEquipAction;
};
