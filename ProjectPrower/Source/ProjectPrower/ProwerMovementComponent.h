// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "ProwerMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTPROWER_API UProwerMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()
	
public:
	virtual bool DoJump(bool bReplayingMoves) override;

	void SetCurrentSurfaceNormal(const FVector& NewNormal) { CurrentSurfaceNormal = NewNormal; }

private:
	FVector GetComponentZAxis() const;

private:

	/* Normal vector of the surface we are currently standing on */
	FVector CurrentSurfaceNormal = FVector(0.0f, 0.0f, 1.0f);
};
