// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProwerCameraMode.h"
#include "FixedTransformCameraMode.generated.h"

/**
 * 
 */
UCLASS(Abstract, Blueprintable)
class PROJECTPROWER_API UFixedTransformCameraMode : public UProwerCameraMode
{
	GENERATED_BODY()

public:
	UFixedTransformCameraMode();

protected:
	virtual void UpdateView(float DeltaTime);
	
public:
	// Target transform for this camera. Ignores scale
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTransform TargetTransform;
};
