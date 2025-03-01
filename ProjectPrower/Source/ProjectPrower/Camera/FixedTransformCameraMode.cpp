// Fill out your copyright notice in the Description page of Project Settings.


#include "FixedTransformCameraMode.h"

UFixedTransformCameraMode::UFixedTransformCameraMode()
	: TargetTransform(FTransform::Identity)
{

}

void UFixedTransformCameraMode::UpdateView(float DeltaTime)
{
	View.Location = TargetTransform.GetLocation();
	View.Rotation = TargetTransform.GetRotation().Rotator();
	View.ControlRotation = View.Rotation;
	View.FOV = FieldOfView;
}
