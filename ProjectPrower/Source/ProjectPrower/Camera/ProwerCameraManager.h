// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "ProwerCameraManager.generated.h"

#define CAMERA_DEFAULT_FOV (80.0f)
#define CAMERA_DEFAULT_PITCH_MIN (-89.0f)
#define CAMERA_DEFAULT_PITCH_MAX (89.0f)

class UProwerCameraMode;

/**
 * 
 */
UCLASS()
class PROJECTPROWER_API AProwerCameraManager : public APlayerCameraManager
{
	GENERATED_BODY()

public:
	AProwerCameraManager(const FObjectInitializer& ObjectInitializer);

	//TSubclassOf<UProwerCameraMode> DetermineCameraMode() const;

protected:
	virtual void UpdateViewTarget(FTViewTarget& OutVT, float DeltaTime) override;
	virtual void DisplayDebug(UCanvas* Canvas, const FDebugDisplayInfo& DebugDisplay, float& YL, float & YPos) override;

	virtual void BeginPlay() override;

public:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UProwerCameraMode> DefaultCameraMode;
};
