// Fill out your copyright notice in the Description page of Project Settings.

#include "ProwerMovementComponent.h"

#include "GameFramework/Character.h"
#include "GameFramework/GameNetworkManager.h"

#include "Components/CapsuleComponent.h"
#include "Components/BrushComponent.h"
#include "CharacterMovementComponentAsync.h"

#include "GameFramework/PhysicsVolume.h"

// Debug
#include "DrawDebugHelpers.h"
#include "Engine/Canvas.h"

UProwerMovementComponent::UProwerMovementComponent(const FObjectInitializer& ObjectInitializer)
:Super(ObjectInitializer)
{
	bConstrainToPlane = false;
	bOrientRotationToMovement = false;
	bMaintainHorizontalGroundVelocity = false;
}

void UProwerMovementComponent::SetCustomGravityDir(const FVector& Dir)
{
	CustomGravityDirection = Dir.GetSafeNormal();
}

void UProwerMovementComponent::ResetGravity()
{
	PreviousNormal = FVector(0.0f, 0.0f, 1.0f);
	CustomGravityDirection = FVector(0.0f, 0.0f, -1.0f);
	SetGravityDirection(CustomGravityDirection); // TODO: Handle overriding gravity (i.e. if we want to force character to fall in a certain direction)
}

void UProwerMovementComponent::UpdateFlightTime(float DeltaTime)
{
	CurrentFlightTime -= DeltaTime;
}

void UProwerMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (ShouldDrawMovementDebug())
	{
		const FVector Start = CharacterOwner->GetActorLocation();

		DrawDebugDirectionalArrow(GetWorld(), Start, Start + CharacterOwner->GetActorForwardVector() * 50.0f, 1.0f, FColor::Red, false, -1.0f, 0, 1.0f);
		DrawDebugDirectionalArrow(GetWorld(), Start, Start + CharacterOwner->GetActorRightVector() * 50.0f, 1.0f, FColor::Green, false, -1.0f, 0, 1.0f);

		const FVector VelocityDir = Velocity.GetSafeNormal();
		DrawDebugDirectionalArrow(GetWorld(), Start, Start + VelocityDir * 75.0f, 1.0f, FColor::Blue, false, -1.0f, 0, 1.0f);

		if(MovementMode == MOVE_Flying)
		{
			const FVector MaxFlightLocation = FVector(Start.X, Start.Y, MaxFlightZ);
			DrawDebugSphere(GetWorld(), MaxFlightLocation, 5.0f, 16.0f, FColor::Purple);

			DrawDebugLine(GetWorld(), Start, MaxFlightLocation, FColor::Purple);
		}
	}
}

void UProwerMovementComponent::PhysWalking(float DeltaTime, int32 Iterations)
{
	if (!CharacterOwner || !CharacterOwner->Controller)
	{
		return;
	}

	const FVector Start = CharacterOwner->GetActorLocation();
	const FVector End = Start + CustomGravityDirection * GroundTraceDistance;

	if (GetWorld()->LineTraceSingleByChannel(CustomFloorHit, Start, End, ECC_Visibility))
	{
		CustomGravityDirection = -CustomFloorHit.Normal;
		CurrentNormal = CustomFloorHit.Normal;
		SetGravityDirection(CustomGravityDirection);
	}

	const FVector SmoothedNormal = FMath::VInterpTo(PreviousNormal, CurrentNormal, DeltaTime, NormalSmoothingSpeed);
	PreviousNormal = SmoothedNormal;

	UpdateOwnerRotation(SmoothedNormal, DeltaTime);
	CalculateTangentVelocity(SmoothedNormal, DeltaTime);

	if(FMath::Abs(Velocity.Size()) < MinSlopeFallSpeed && (SmoothedNormal | FVector(0.0f, 0.0f, 1.0f)) <= 0.0f)
	{
		PreviousNormal = FVector(0.0f, 0.0f, 1.0f);
		CustomGravityDirection = FVector(0.0f, 0.0f, -1.0f);
		SetGravityDirection(CustomGravityDirection);

		SetMovementMode(MOVE_Falling);
		Velocity += CustomGravityDirection * 200.0f;

		return;
	}

	Super::PhysWalking(DeltaTime, Iterations);
}

void UProwerMovementComponent::PhysFalling(float DeltaTime, int32 Iterations)
{
	if (DeltaTime < SMALL_NUMBER)
	{
		return;
	}

	const FVector CustomGravityForce = CustomGravityDirection * CustomGravityStrength;
	Velocity += CustomGravityForce * DeltaTime;

	if(!GetLastInputVector().IsNearlyZero())
	{
		UpdateOwnerRotationFalling(DeltaTime);
	}

	Super::PhysFalling(DeltaTime, Iterations);
}

void UProwerMovementComponent::PhysFlying(float DeltaTime, int32 Iterations)
{
	Super::PhysFlying(DeltaTime, Iterations);

	if (bFlightInputHeld && !bFlightExhausted)
	{
		const FVector FlightDir = FVector(GetLastInputVector().X, GetLastInputVector().Y, 1.0f).GetSafeNormal();
		Velocity += (FlightDir * VerticalFlightSpeed) * DeltaTime;

		if (CharacterOwner->GetActorLocation().Z > MaxFlightZ)
		{
			Velocity.Z = 0.0f;

			// Smoothly interpolate to the correct height if our velocity takes us past it.
			const FVector CurrentLocation = CharacterOwner->GetActorLocation();
			FVector UpdatedLocation = FMath::VInterpTo(CurrentLocation, FVector(CurrentLocation.X, CurrentLocation.Y, MaxFlightZ), DeltaTime, MaxFlightHeightSmoothSpeed);
			CharacterOwner->SetActorLocation(UpdatedLocation);
		}

		if (!GetLastInputVector().IsNearlyZero())
		{
			UpdateOwnerRotationFalling(DeltaTime);
		}

		CurrentFlightTime -= DeltaTime;
		if (CurrentFlightTime <= 0.0f)
		{
			bFlightExhausted = true;
			CurrentFlightTime = 0.0f;
			OnFlightExhauseted.Broadcast();
		}
	}
}

void UProwerMovementComponent::StartFalling(int32 Iterations, float RemainingTime, float TimeTick, const FVector& Delta, const FVector& SubLoc)
{
	ResetGravity();

	Super::StartFalling(Iterations, RemainingTime, TimeTick, Delta, SubLoc);
}

bool UProwerMovementComponent::IsWalkable(const FHitResult& Hit) const
{
	//return Super::IsWalkable(Hit);
	return true;
}

bool UProwerMovementComponent::IsMovingOnGround() const
{
	return CustomFloorHit.bBlockingHit && IsWalkable(CustomFloorHit) && UpdatedComponent;
}

void UProwerMovementComponent::FindFloor(const FVector& CapsuleLocation, FFindFloorResult& OutFloorResult, bool bCanUseCachedLocation, const FHitResult* DownwardSweepResult) const
{
	const FVector Start = CapsuleLocation;
	const FVector End = Start + CustomGravityDirection * GroundTraceDistance;

	if (ShouldDrawMovementDebug())
	{
		DrawDebugLine(GetWorld(), Start, End, FColor::Emerald);
	}

	FHitResult FloorHit;
	if (GetWorld()->LineTraceSingleByChannel(FloorHit, Start, End, ECC_Visibility))
	{
		OutFloorResult.bBlockingHit = true;
		OutFloorResult.bWalkableFloor = true;
		OutFloorResult.FloorDist = FloorHit.Distance;
		OutFloorResult.HitResult = FloorHit;
	}
	else
	{
		OutFloorResult.Clear();
	}
}

void UProwerMovementComponent::ProcessLanded(const FHitResult& Hit, float remainingTime, int32 Iterations)
{
	Super::ProcessLanded(Hit, remainingTime, Iterations);
}

bool UProwerMovementComponent::IsValidLandingSpot(const FVector& CapsuleLocation, const FHitResult& Hit) const
{
	return Super::IsValidLandingSpot(CapsuleLocation, Hit);
}

bool UProwerMovementComponent::DoJump(bool bReplayingMoves)
{
	if (CharacterOwner && CharacterOwner->CanJump())
	{
		const FVector JumpDirection = GetCurrentSurfaceNormal();
		const FVector TangentVelocity = Velocity - (Velocity | GetCurrentSurfaceNormal()) * GetCurrentSurfaceNormal();

		Velocity = TangentVelocity + (JumpDirection * JumpZVelocity);

		ResetGravity();

		if(MovementMode != MOVE_Flying)
		{
			SetMovementMode(MOVE_Falling);
		}

		return true;
	}

	return false;
}

void UProwerMovementComponent::ApplyVelocityBraking(float DeltaTime, float Friction, float BrakingDeceleration)
{
	if (Velocity.IsZero() || !HasValidData() || HasAnimRootMotion() || DeltaTime < MIN_TICK_TIME)
	{
		return;
	}

	const float FrictionFactor = FMath::Max(0.f, BrakingFrictionFactor);
	Friction = FMath::Max(0.f, Friction * FrictionFactor);
	BrakingDeceleration = FMath::Max(0.f, BrakingDeceleration);
	const bool bZeroFriction = (Friction == 0.f);
	const bool bZeroBraking = (BrakingDeceleration == 0.f);

	if (bZeroFriction && bZeroBraking)
	{
		return;
	}

	const bool bIgnoreZ = MovementMode == MOVE_Flying;

	const FVector OldVel = Velocity;

	// subdivide braking to get reasonably consistent results at lower frame rates
	// (important for packet loss situations w/ networking)
	float RemainingTime = DeltaTime;
	const float MaxTimeStep = FMath::Clamp(BrakingSubStepTime, 1.0f / 75.0f, 1.0f / 20.0f);

	// Decelerate to brake to a stop
	const FVector RevAccel = (bZeroBraking ? FVector::ZeroVector : (-BrakingDeceleration * Velocity.GetSafeNormal()));
	while (RemainingTime >= MIN_TICK_TIME)
	{
		// Zero friction uses constant deceleration, so no need for iteration.
		const float dt = ((RemainingTime > MaxTimeStep && !bZeroFriction) ? FMath::Min(MaxTimeStep, RemainingTime * 0.5f) : RemainingTime);
		RemainingTime -= dt;

		// apply friction and braking
		Velocity = Velocity + ((-Friction) * Velocity + RevAccel) * dt;
		if(bIgnoreZ)
		{
			Velocity.Z = OldVel.Z;
		}

		// Don't reverse direction
		if ((Velocity | OldVel) <= 0.f)
		{
			Velocity = FVector::ZeroVector;
			return;
		}
	}

	const FVector LateralVelocity = FVector(Velocity.X, Velocity.Y, 0.0f);
	const float LateralVSizeSq = LateralVelocity.SizeSquared();
	if(bIgnoreZ && (LateralVSizeSq <= UE_KINDA_SMALL_NUMBER || (!bZeroBraking && LateralVSizeSq <= FMath::Square(BRAKE_TO_STOP_VELOCITY))))
	{
		Velocity = FVector(0.0f, 0.0f, Velocity.Z);
	}

	// Clamp to zero if nearly zero, or if below min threshold and braking.
	const float VSizeSq = Velocity.SizeSquared();
	if (VSizeSq <= UE_KINDA_SMALL_NUMBER || (!bZeroBraking && VSizeSq <= FMath::Square(BRAKE_TO_STOP_VELOCITY)))
	{
		Velocity = FVector::ZeroVector;
	}
}

void UProwerMovementComponent::UpdateOwnerRotation(const FVector& SurfaceNormal, float DeltaTime)
{
	const APlayerController* Controller = Cast<APlayerController>(CharacterOwner->GetController());
	if(!Controller)
	{
		return;
	}

	const FVector ForwardVector = CharacterOwner->GetActorForwardVector();

	// Align to surface
	const FQuat TargetOrientation = FRotationMatrix::MakeFromZX(SurfaceNormal, ForwardVector).ToQuat();
	FQuat SmoothTargetOrientation = FQuat::Slerp(CharacterOwner->GetActorQuat(), TargetOrientation, DeltaTime * RotationSmoothingSpeed);
	SmoothTargetOrientation.Normalize();

	// Rotate towards velocity
	const FVector TangentVelocity = Velocity - (Velocity | SurfaceNormal) * SurfaceNormal;
	if(!TangentVelocity.IsNearlyZero(RotateToVelocityThreshold))
	{
		const FQuat TargetForwardOrientation = FRotationMatrix::MakeFromXZ(TangentVelocity.GetSafeNormal(), SurfaceNormal).ToQuat();
		SmoothTargetOrientation = FQuat::Slerp(SmoothTargetOrientation, TargetForwardOrientation, DeltaTime * RotateToVelocityCurve->GetFloatValue(TangentVelocity.Size()));
		SmoothTargetOrientation.Normalize();
	}

	CharacterOwner->SetActorRotation(SmoothTargetOrientation);
}

void UProwerMovementComponent::UpdateOwnerRotationFalling(float DeltaTime)
{
	FVector VelocityDir = Velocity.GetSafeNormal();
	VelocityDir.Z = 0.0f;

	const FRotator TargetRotation = FRotator(0.0f, VelocityDir.Rotation().Yaw, 0.0f);
	FRotator UpdatedRotation = FMath::RInterpTo(CharacterOwner->GetActorRotation(), TargetRotation, DeltaTime, AirRotationSmoothingSpeed);

	CharacterOwner->SetActorRotation(UpdatedRotation);
}

void UProwerMovementComponent::CalculateTangentVelocity(const FVector& SurfaceNormal, float DeltaTime)
{
	const FVector ForwardVector = CharacterOwner->GetActorForwardVector();

	const FVector TangentVelocity = Velocity - (Velocity | SurfaceNormal) * SurfaceNormal;
	FVector TangetForward = TangentVelocity.GetSafeNormal();

	if(TangetForward.SizeSquared() < UE_KINDA_SMALL_NUMBER)
	{
		TangetForward = CharacterOwner->GetActorForwardVector();;
	}

	Velocity = TangentVelocity + TangetForward * TangentVelocityScale;
}
