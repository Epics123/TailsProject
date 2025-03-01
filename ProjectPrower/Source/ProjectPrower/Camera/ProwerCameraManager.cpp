// Fill out your copyright notice in the Description page of Project Settings.

#include "ProwerCameraManager.h"
#include "ProwerCameraMode.h"
#include "ProwerCameraComponent.h"

#include "Engine/Canvas.h"

AProwerCameraManager::AProwerCameraManager(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	DefaultFOV = CAMERA_DEFAULT_FOV;
	ViewPitchMin = CAMERA_DEFAULT_PITCH_MIN;
	ViewPitchMax = CAMERA_DEFAULT_PITCH_MAX;
}

//TSubclassOf<UProwerCameraMode> AProwerCameraManager::DetermineCameraMode() const
//{
//	
//}

void AProwerCameraManager::UpdateViewTarget(FTViewTarget& OutVT, float DeltaTime)
{
	// TODO: UI camera

	Super::UpdateViewTarget(OutVT, DeltaTime);
}

void AProwerCameraManager::DisplayDebug(UCanvas* Canvas, const FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos)
{
	check(Canvas);

	FDisplayDebugManager& DisplayDebugManager = Canvas->DisplayDebugManager;

	DisplayDebugManager.SetFont(GEngine->GetSmallFont());
	DisplayDebugManager.SetDrawColor(FColor::Yellow);
	DisplayDebugManager.DrawString(FString::Printf(TEXT("ProwerCameraManager: %s"), *GetNameSafe(this)));

	if(PCOwner && PCOwner->GetPawn())
	{
		UProwerCameraComponent* CameraComponent = UProwerCameraComponent::FindCameraComponent(PCOwner->GetPawn());
		if(CameraComponent)
		{
			CameraComponent->DrawDebug(Canvas);
		}
	}

	Super::DisplayDebug(Canvas, DebugDisplay, YL, YPos);
}

void AProwerCameraManager::BeginPlay()
{
	if (DefaultCameraMode && PCOwner)
	{
		APawn* Pawn = PCOwner->GetPawn();
		UProwerCameraComponent* CameraComponent = UProwerCameraComponent::FindCameraComponent(Pawn);
		if (CameraComponent)
		{
			CameraComponent->InitDefaultCameraMode(DefaultCameraMode);
		}
	}

	Super::BeginPlay();
}
