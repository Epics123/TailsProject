// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MotionParams.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTPROWER_API UMotionParams : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GroundMovement)
	float WalkSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GroundMovement)
	float TopSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GroundMovement)
	float MaxSpeed;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Breaking)
	float BreakSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Breaking)
	float BreakDecelSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Breaking)
	float BreakTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Jumping)
	float JumpTime;
};
