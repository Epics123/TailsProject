// Fill out your copyright notice in the Description page of Project Settings.

#include "ProwerMovementComponent.h"

bool UProwerMovementComponent::DoJump(bool bReplayingMoves)
{
	const FVector JumpDir = GetComponentZAxis();

	// If movement isn't constrained or the angle between plane normal and jump direction is between 60 and 120 degrees...
	if (!bConstrainToPlane || FMath::Abs(PlaneConstraintNormal | JumpDir) < 0.5f)
	{
		// Zero the vertical component of velocity.
		Velocity = FVector::VectorPlaneProject(Velocity, JumpDir);

		// Perform jump.
		Velocity += JumpDir * JumpZVelocity;
		SetMovementMode(MOVE_Falling);

		return true;
	}

	return false;
}

FVector UProwerMovementComponent::GetComponentZAxis() const
{
	// Fast simplification of FQuat::RotateVector() with FVector(0,0,1).
	const FQuat ComponentRotation = UpdatedComponent->GetComponentQuat();
	const FVector QuatVector(ComponentRotation.X, ComponentRotation.Y, ComponentRotation.Z);

	return FVector(ComponentRotation.Y * ComponentRotation.W * 2.0f, ComponentRotation.X * ComponentRotation.W * -2.0f,
		FMath::Square(ComponentRotation.W) - QuatVector.SizeSquared()) + QuatVector * (ComponentRotation.Z * 2.0f);
}
