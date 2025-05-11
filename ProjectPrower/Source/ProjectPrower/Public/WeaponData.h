// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "WeaponData.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTPROWER_API UWeaponData : public UDataAsset
{
	GENERATED_BODY()

public:
	
	/* Maximum distance a projectile can travel */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxProjectileDistance;

	/* Time between shots. A value of 0 will result in firing as fast as the trigger can be pulled */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxTimeBetweenShots = 0.0f;

	/* Initial speed of the projectile when fired, used to "fake" projectile visuals if hitscan */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float InitialProjectileSpeed = 0.0f;

	/* Time needed for hitscan vfx to move to target */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float HitscanVFXTime = 0.2f;

	/* The class of the projectile this weapon will spawn */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class AProjectileBase> Projectile;

	/* Niagara system used to represent the projectile if it is hitscan */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<class UNiagaraSystem> ProjecileSystem;

	/* Niagara system to spawn when something is hit by this weapon */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<class UNiagaraSystem> HitImpactEffect;

	/* Niagara system to spawn at the muzzle of the weapon. Leave null for melee weapons. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<class UNiagaraSystem> MuzzleFlashEffect;
};
