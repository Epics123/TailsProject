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

static TAutoConsoleVariable<int32> CVar_DrawMovementDebug
(
	TEXT("Movement.Debug.Draw"),
	0,
	TEXT("Draw movement debug information")
);

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

	bool ShouldDrawMovementDebug() const
	{
		return CVar_DrawMovementDebug.GetValueOnGameThread() != 0;
	}

protected:
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

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
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Movement | General")
	float GroundTraceDistance = 75.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Movement | General")
	float NormalSmoothingSpeed = 5.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Movement | General")
	float TangentVelocityScale = 1.0f;

	/** The maximum angle we allow our input to be relative to the camera. 
		If the surface angle is past this threshold, the character's local vectors will be used.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Movement | General", meta=(ClampMin = -1, ClampMax = 1, UIMin = -1, UIMax = 1))
	float MaxCameraVectorAngle = 0.25f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Movement | General")
	bool bForceCharacterVectors = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Movement | Rotation")
	float RotationSmoothingSpeed = 5.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Movement | Rotation")
	TObjectPtr<UCurveFloat> RotateToVelocityCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Movement | Rotation")
	float RotateToVelocityThreshold = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Movement | Gravity")
	float CustomGravityStrength = 50.0f;

private:
	FVector CustomGravityDirection = FVector(0, 0, -1);
	FHitResult CustomFloorHit;

	FVector CurrentNormal;
	FVector PreviousNormal = FVector(0, 0, 1);
};
