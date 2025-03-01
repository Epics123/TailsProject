// Fill out your copyright notice in the Description page of Project Settings.


#include "ProwerCameraComponent.h"
#include "ProwerCameraMode.h"

#include "Engine/Canvas.h"

UProwerCameraComponent::UProwerCameraComponent(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	CameraModeStack = nullptr;
	FieldOfViewOffset = 0.0f;
}

void UProwerCameraComponent::DrawDebug(UCanvas* Canvas) const
{
	check(Canvas);

	FDisplayDebugManager& DisplayDebugManager = Canvas->DisplayDebugManager;

	DisplayDebugManager.SetFont(GEngine->GetSmallFont());
	DisplayDebugManager.SetDrawColor(FColor::Yellow);
	DisplayDebugManager.DrawString(FString::Printf(TEXT("ProwerCameraComponent: %s"), *GetNameSafe(GetTargetActor())));

	DisplayDebugManager.SetDrawColor(FColor::White);
	DisplayDebugManager.DrawString(FString::Printf(TEXT("   Location: %s"), *GetComponentLocation().ToCompactString()));
	DisplayDebugManager.DrawString(FString::Printf(TEXT("   Rotation: %s"), *GetComponentRotation().ToCompactString()));
	DisplayDebugManager.DrawString(FString::Printf(TEXT("   FOV: %f"), FieldOfView));

	CameraModeStack->DrawDebug(Canvas);
}

void UProwerCameraComponent::GetBlendInfo(float& OutWeightOfTopLayer, FGameplayTag& OutTagOfTopLayer) const
{
	check(CameraModeStack);
	CameraModeStack->GetBlendInfo(OutWeightOfTopLayer, OutTagOfTopLayer);
}

void UProwerCameraComponent::InitDefaultCameraMode(TSubclassOf<UProwerCameraMode> CameraMode)
{
	if(CameraMode)
	{
		CameraModeStack->PushCameraMode(CameraMode);
	}
}

void UProwerCameraComponent::PushCameraMode(TSubclassOf<UProwerCameraMode> CameraMode)
{
	if(CameraMode)
	{
		CameraModeStack->PushCameraMode(CameraMode);
	}
}

void UProwerCameraComponent::PushCameraModeInstance(UProwerCameraMode* CameraMode)
{
	if(CameraMode)
	{
		CameraModeStack->PushCameraModeInstance(CameraMode);
	}
}

bool UProwerCameraComponent::HasActiveCameraMode(TSubclassOf<UProwerCameraMode> CameraMode)
{
	return CameraModeStack->HasCameraMode(CameraMode);
}

bool UProwerCameraComponent::HasCameraTag(const FGameplayTag& Tag)
{
	return CameraModeStack->HasTag(Tag);
}

void UProwerCameraComponent::OnRegister()
{
	Super::OnRegister();

	if(!CameraModeStack)
	{
		CameraModeStack = NewObject<UProwerCameraModeStack>(this);
		check(CameraModeStack);
	}
}

void UProwerCameraComponent::GetCameraView(float DeltaTime, FMinimalViewInfo& DesiredView)
{
	UpdateCameraModes();

	FProwerCameraModeView CameraModeView;
	CameraModeStack->EvaluateStack(DeltaTime, CameraModeView);

	// Keep player controller in sync with the latest view.
	if (APawn* TargetPawn = Cast<APawn>(GetTargetActor()))
	{
		if (APlayerController* PC = TargetPawn->GetController<APlayerController>())
		{
			PC->SetControlRotation(CameraModeView.ControlRotation);
		}
	}

	// Apply any offset that was added to the field of view.
	CameraModeView.FOV += FieldOfViewOffset;
	FieldOfViewOffset = 0.0f;

	// Keep camera component in sync with the latest view.
	SetWorldLocationAndRotation(CameraModeView.Location, CameraModeView.Rotation);
	FieldOfView = CameraModeView.FOV;

	// Fill in desired view.
	DesiredView.Location = CameraModeView.Location;
	DesiredView.Rotation = CameraModeView.Rotation;
	DesiredView.FOV = CameraModeView.FOV;
	DesiredView.OrthoWidth = OrthoWidth;
	DesiredView.OrthoNearClipPlane = OrthoNearClipPlane;
	DesiredView.OrthoFarClipPlane = OrthoFarClipPlane;
	DesiredView.AspectRatio = AspectRatio;
	DesiredView.bConstrainAspectRatio = bConstrainAspectRatio;
	DesiredView.bUseFieldOfViewForLOD = bUseFieldOfViewForLOD;
	DesiredView.ProjectionMode = ProjectionMode;

	// See if the CameraActor wants to override the PostProcess settings used.
	DesiredView.PostProcessBlendWeight = PostProcessBlendWeight;
	if (PostProcessBlendWeight > 0.0f)
	{
		DesiredView.PostProcessSettings = PostProcessSettings;
	}
}

void UProwerCameraComponent::UpdateCameraModes()
{
	check(CameraModeStack);

	if (CameraModeStack->IsStackActive())
	{
		if (DetermineCameraModeDelegate.IsBound())
		{
			if (const TSubclassOf<UProwerCameraMode> CameraMode = DetermineCameraModeDelegate.Execute())
			{
				CameraModeStack->PushCameraMode(CameraMode);
			}
		}
	}
}
