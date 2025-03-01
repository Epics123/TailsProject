// Fill out your copyright notice in the Description page of Project Settings.

// Classes based on Lyra's example: https://github.com/EpicGames/UnrealEngine/blob/ue5-main/Samples/Games/Lyra/Source/LyraGame/Camera/LyraCameraMode.h

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

#include "ProwerCameraMode.generated.h"

class UCanvas;
class UProwerCameraComponent;

/**
 * EProwerCameraModeBlendFunction
 *
 *	Blend function used for transitioning between camera modes.
 */
UENUM(BlueprintType)
enum class EProwerCameraModeBlendFunction : uint8
{
	// Does a simple linear interpolation.
	Linear,

	// Immediately accelerates, but smoothly decelerates into the target.  Ease amount controlled by the exponent.
	EaseIn,

	// Smoothly accelerates, but does not decelerate into the target.  Ease amount controlled by the exponent.
	EaseOut,

	// Smoothly accelerates and decelerates.  Ease amount controlled by the exponent.
	EaseInOut,

	COUNT	UMETA(Hidden)
};

struct FProwerCameraModeView
{
	FProwerCameraModeView();

	void Blend(const FProwerCameraModeView& Other, float OtherWeight);

	FVector Location;
	FRotator Rotation;
	FRotator ControlRotation;
	float FOV;
};

/**
 * 
 */
 UCLASS(Abstract, Blueprintable)
class UProwerCameraMode : public UObject
{
	GENERATED_BODY()

public:
	UProwerCameraMode();
	~UProwerCameraMode(){};

	UProwerCameraComponent* GetCameraComponent() const;

	virtual UWorld* GetWorld() const override;

	AActor* GetTargetActor() const;

	const FProwerCameraModeView& GetCameraModeView() const { return View; }

	// Called when this camera mode is activated on the camera mode stack.
	virtual void OnActivation() {};

	// Called when this camera mode is deactivated on the camera mode stack.
	virtual void OnDeactivation() {};

	void UpdateCameraMode(float DeltaTime);

	float GetBlendTime() const { return BlendTime; }
	float GetBlendWeight() const { return BlendWeight; }
	void SetBlendWeight(float Weight);

	FGameplayTag GetCameraTypeTag() const { return CameraTypeTag; }

	virtual void DrawDebug(UCanvas* Canvas) const;

protected:
	
	virtual FVector GetPivotLocation() const;
	virtual FRotator GetPivotRotation() const;

	virtual void UpdateView(float DeltaTime);
	virtual void UpdateBlending(float DeltaTime);

protected:
// A tag that can be queried by gameplay code that cares when a kind of camera mode is active
	// without having to ask about a specific mode (e.g., when aiming downsights to get more accuracy)
	UPROPERTY(EditDefaultsOnly, Category = "Blending")
	FGameplayTag CameraTypeTag;

	// View output produced by the camera mode.
	FProwerCameraModeView View;

	// The horizontal field of view (in degrees).
	UPROPERTY(EditDefaultsOnly, Category = "View", Meta = (UIMin = "5.0", UIMax = "170", ClampMin = "5.0", ClampMax = "170.0"))
	float FieldOfView;

	// Minimum view pitch (in degrees).
	UPROPERTY(EditDefaultsOnly, Category = "View", Meta = (UIMin = "-89.9", UIMax = "89.9", ClampMin = "-89.9", ClampMax = "89.9"))
	float ViewPitchMin;

	// Maximum view pitch (in degrees).
	UPROPERTY(EditDefaultsOnly, Category = "View", Meta = (UIMin = "-89.9", UIMax = "89.9", ClampMin = "-89.9", ClampMax = "89.9"))
	float ViewPitchMax;

	// How long it takes to blend in this mode.
	UPROPERTY(EditDefaultsOnly, Category = "Blending")
	float BlendTime;

	// Function used for blending.
	UPROPERTY(EditDefaultsOnly, Category = "Blending")
	EProwerCameraModeBlendFunction BlendFunction;

	// Exponent used by blend functions to control the shape of the curve.
	UPROPERTY(EditDefaultsOnly, Category = "Blending")
	float BlendExponent;

	// Linear blend alpha used to determine the blend weight.
	float BlendAlpha;

	// Blend weight calculated using the blend alpha and function.
	float BlendWeight;

protected:
	/** If true, skips all interpolation and puts camera in ideal location.  Automatically set to false next frame. */
	UPROPERTY(transient)
	uint32 bResetInterpolation:1;
};

// Stack used for blending camera modes.
UCLASS()
class UProwerCameraModeStack : public UObject
{
	GENERATED_BODY()

public:
	UProwerCameraModeStack();

	void ActivateStack();
	void DeactivateStack();

	void PushCameraMode(TSubclassOf<UProwerCameraMode> CameraModeClass);

	void PushCameraModeInstance(TObjectPtr<UProwerCameraMode> CameraMode);

	bool EvaluateStack(float DeltaTime, FProwerCameraModeView& OutCameraModeView);

	void DrawDebug(UCanvas* Canvas) const;

	void GetBlendInfo(float& OutWeightOfTopLayer, FGameplayTag& OutTagOfTopLayer);

	bool IsStackActive() const { return bActive; }

	bool HasCameraMode(TSubclassOf<UProwerCameraMode> CameraModeClass);

	bool HasTag(const FGameplayTag& Tag);

protected:
	UProwerCameraMode* GetCameraModeInstance(TSubclassOf<UProwerCameraMode> CameraModeClass);

	void UpdateStack(float DeltaTime);
	void BlendStack(FProwerCameraModeView& OutCameraModeView) const;

private:
	void AddToStack(UProwerCameraMode* CameraMode);

protected:
	bool bActive;

	UPROPERTY()
	TArray<TObjectPtr<UProwerCameraMode>> CameraModeInstances;

	UPROPERTY()
	TArray<TObjectPtr<UProwerCameraMode>> CameraModeStack;
};
