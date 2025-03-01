// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"

#include "GameplayTagContainer.h"

#include "ProwerCameraComponent.generated.h"

class UCanvas;
class UProwerCameraMode;
class UProwerCameraModeStack;

DECLARE_DELEGATE_RetVal(TSubclassOf<UProwerCameraMode>, FProwerCameraModeDelegate);

/**
 * 
 */
UCLASS()
class PROJECTPROWER_API UProwerCameraComponent : public UCameraComponent
{
	GENERATED_BODY()
	
public:
	UProwerCameraComponent(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Camera")
	static UProwerCameraComponent* FindCameraComponent(const AActor* Actor) { return (Actor? Actor->FindComponentByClass<UProwerCameraComponent>() : nullptr); }

	// Returns the target actor that the camera is looking at.
	virtual AActor* GetTargetActor() const { return GetOwner(); }

	// Add an offset to the field of view.  The offset is only for one frame, it gets cleared once it is applied.
	void AddFOVOffset(float FovOffset) { FieldOfViewOffset += FovOffset; }

	virtual void DrawDebug(UCanvas* Canvas) const;

	// Gets the tag associated with the top layer and the blend weight of it
	void GetBlendInfo(float& OutWeightOfTopLayer, FGameplayTag& OutTagOfTopLayer) const;

	void InitDefaultCameraMode(TSubclassOf<UProwerCameraMode> CameraMode);

	UFUNCTION(BlueprintCallable)
	void PushCameraMode(TSubclassOf<UProwerCameraMode> CameraMode);

	UFUNCTION(BlueprintCallable)
	void PushCameraModeInstance(UProwerCameraMode* CameraMode);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool HasActiveCameraMode(TSubclassOf<UProwerCameraMode> CameraMode);

	// Returns true if the camera stack has any camera modes containing this tag
	UFUNCTION(BlueprintPure)
	bool HasCameraTag(const FGameplayTag& Tag);

protected:
	virtual void OnRegister() override;
	virtual void GetCameraView(float DeltaTime, FMinimalViewInfo& DesiredView) override;

	virtual void UpdateCameraModes();

public:
	// Delegate used to query for the best camera mode.
	FProwerCameraModeDelegate DetermineCameraModeDelegate;

protected:
	UPROPERTY()
	TObjectPtr<UProwerCameraModeStack> CameraModeStack;

	// Offset applied to the field of view.  The offset is only for one frame, it gets cleared once it is applied.
	float FieldOfViewOffset;
};
