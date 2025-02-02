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

	Super::PhysFalling(DeltaTime, Iterations);
}

void UProwerMovementComponent::StartFalling(int32 Iterations, float RemainingTime, float TimeTick, const FVector& Delta, const FVector& SubLoc)
{
	PreviousNormal = FVector(0.0f, 0.0f, 1.0f);

	CustomGravityDirection = FVector(0.0f, 0.0f, -1.0f);
	SetGravityDirection(CustomGravityDirection); // TODO: Handle overriding gravity (i.e. if we want to force character to fall in a certain direction)

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
	const FVector ForwardVector = CharacterOwner->GetActorForwardVector();
	CharacterOwner->SetActorRotation(FRotationMatrix::MakeFromZX(Hit.Normal, ForwardVector).Rotator());
	Super::ProcessLanded(Hit, remainingTime, Iterations);
}

bool UProwerMovementComponent::IsValidLandingSpot(const FVector& CapsuleLocation, const FHitResult& Hit) const
{
	return Super::IsValidLandingSpot(CapsuleLocation, Hit);
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
