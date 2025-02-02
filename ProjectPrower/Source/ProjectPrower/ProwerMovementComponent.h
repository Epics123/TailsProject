// Fill out your copyright notice in the Description page of Project Settings.

/** 
* Movement component taken/modified from DashEngine 1.3
* See https://github.com/YakuzaBalooza/Dash-Engine-1.3/tree/main
*/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/NavMovementComponent.h"
#include "ProwerMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTPROWER_API UProwerMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()
	
public:
	UProwerMovementComponent(const FObjectInitializer& ObjectInitializer);

	FVector GetCustomGravityDir() const { return CustomGravityDirection; }
	void SetCustomGravityDir(const FVector& Dir);

	const FVector GetCurrentSurfaceNormal() const { return CurrentNormal; }

protected:
	virtual void PhysWalking(float DeltaTime, int32 Iterations) override;
	virtual void PhysFalling(float DeltaTime, int32 Iterations) override;

	virtual void StartFalling(int32 Iterations, float RemainingTime, float TimeTick, const FVector& Delta, const FVector& SubLoc) override;

	virtual bool IsWalkable(const FHitResult& Hit) const override;

	virtual bool IsMovingOnGround() const override;

	virtual void FindFloor(const FVector& CapsuleLocation, FFindFloorResult& OutFloorResult, bool bCanUseCachedLocation, const FHitResult* DownwardSweepResult = NULL) const override;

	virtual void ProcessLanded(const FHitResult& Hit, float remainingTime, int32 Iterations) override;

	virtual bool IsValidLandingSpot(const FVector& CapsuleLocation, const FHitResult& Hit) const override;

private:
	void UpdateOwnerRotation(const FVector& SurfaceNormal, float DeltaTime);
	void CalculateTangentVelocity(const FVector& SurfaceNormal, float DeltaTime);

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Movement")
	float CustomGravityStrength = 50.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Movement")
	float GroundTraceDistance = 75.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Movement")
	float NormalSmoothingSpeed = 5.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Movement | Rotation")
	float RotationSmoothingSpeed = 5.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Movement | Rotation")
	TObjectPtr<UCurveFloat> RotateToVelocityCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Movement | Rotation")
	float RotateToVelocityThreshold = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Movement")
	float TangentVelocityScale = 1.0f;

private:
	FVector CustomGravityDirection = FVector(0, 0, -1);
	FHitResult CustomFloorHit;

	FVector CurrentNormal;
	FVector PreviousNormal = FVector(0, 0, 1);
};
