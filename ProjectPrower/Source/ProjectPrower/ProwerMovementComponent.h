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

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFlightExhaustedDelegate);

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

	void ResetGravity();

	void UpdateFlightTime(float DeltaTime);

	void ResetFlightTime()
	{
		CurrentFlightTime = MaxFlightTime;
	}

	/** Calculates the distance between the character's current location and the maximum flight location, normalized to [0, 1] */
	UFUNCTION(BlueprintCallable, BlueprintPure)
	float CalculateVerticalDirection() const;

protected:
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void PhysWalking(float DeltaTime, int32 Iterations) override;
	virtual void PhysFalling(float DeltaTime, int32 Iterations) override;
	virtual void PhysFlying(float DeltaTime, int32 Iterations) override;

	virtual void StartFalling(int32 Iterations, float RemainingTime, float TimeTick, const FVector& Delta, const FVector& SubLoc) override;

	virtual bool IsWalkable(const FHitResult& Hit) const override;

	virtual bool IsMovingOnGround() const override;

	virtual void FindFloor(const FVector& CapsuleLocation, FFindFloorResult& OutFloorResult, bool bCanUseCachedLocation, const FHitResult* DownwardSweepResult = NULL) const override;

	virtual void ProcessLanded(const FHitResult& Hit, float remainingTime, int32 Iterations) override;

	virtual bool IsValidLandingSpot(const FVector& CapsuleLocation, const FHitResult& Hit) const override;

	virtual bool DoJump(bool bReplayingMoves) override;

	virtual void ApplyVelocityBraking(float DeltaTime, float Friction, float BrakingDeceleration);

private:
	void UpdateOwnerRotation(const FVector& SurfaceNormal, float DeltaTime);
	void UpdateOwnerRotationFalling(float DeltaTime);
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

	/** Minimum speed needed to not fall off of surfaces at extreme angles (over 90 degrees) like loops */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Movement | General")
	float MinSlopeFallSpeed = 1500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Movement | Rotation")
	float RotationSmoothingSpeed = 5.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Movement | Rotation")
	float AirRotationSmoothingSpeed = 5.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Movement | Rotation")
	TObjectPtr<UCurveFloat> RotateToVelocityCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Movement | Rotation")
	float RotateToVelocityThreshold = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Movement | Gravity")
	float CustomGravityStrength = 50.0f;

	/** Maximum height this character can fly to. Calculated when flying starts */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Movement | Flying")
	float MaxFlightZ;

	/** Maximum distance this character can fly vertically */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Movement | Flying")
	float MaxVerticalFlyDistance = 300.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Movement | Flying")
	float MaxFlightTime = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Movement | Flying")
	float VerticalFlightSpeed = 150.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Movement | Flying")
	float MaxFlightHeightSmoothSpeed = 50.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Custom Movement | Flying")
	bool bFlightExhausted = false;
	UPROPERTY(BlueprintReadWrite, Category = "Custom Movement | Flying")
	bool bHasFlightReset = true;
	UPROPERTY(BlueprintReadWrite, Category = "Custom Movement | Flying")
	bool bFlightInputHeld = false;

	float CurrentFlightTime;

	FOnFlightExhaustedDelegate OnFlightExhauseted;

private:
	FVector CustomGravityDirection = FVector(0, 0, -1);
	FHitResult CustomFloorHit;

	FVector CurrentNormal;
	FVector PreviousNormal = FVector(0, 0, 1);
};
