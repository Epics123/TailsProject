// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraManagerComponent.h"
#include "../ProjectProwerCharacter.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values for this component's properties
UCameraManagerComponent::UCameraManagerComponent()
{
	OwningCharacter = Cast<AProjectProwerCharacter>(GetOwner());
	CurrentCameraMode = DefaultCameraMode;
}


void UCameraManagerComponent::SetCameraMode(ECameraMode NewMode)
{
	OnCameraModeChanged(CurrentCameraMode, NewMode);
	CurrentCameraMode = NewMode;

	switch (CurrentCameraMode)
	{
	case ECameraMode::FREE:
		SetFreeCameraMode();
		break;
	case ECameraMode::LOCKED:
		break;
	case ECameraMode::LOOKAT:
		break;
	case ECameraMode::SLOPE:
		SetSlopeCameraMode();
		break;
	case ECameraMode::TURNCIRCLE:
		break;
	case ECameraMode::CUSTOM:
		break;
	default:
		break;
	}
}

void UCameraManagerComponent::OnCameraModeChanged(ECameraMode PrevMode, ECameraMode NewMode)
{
	ResetCameraAlignment(PrevMode, NewMode);
}

void UCameraManagerComponent::ResetCameraAlignment(ECameraMode PrevMode, ECameraMode NewMode)
{
	if(bResetCameraAfterLooping && OwningCharacter)
	{
		// Check if we are returning to default camera mode
		if(PrevMode == LoopingCameraMode && NewMode == DefaultCameraMode)
		{
			const float CharacterYaw = OwningCharacter->GetActorRotation().Yaw;
			OwningCharacter->GetController()->SetControlRotation(FRotator(0.0f, CharacterYaw, 0.0f));
		}
	}
}

// Called when the game starts
void UCameraManagerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UCameraManagerComponent::SetFreeCameraMode()
{
	AProjectProwerCharacter* Character = GetOwningCharacter();
	if (Character)
	{
		const float CharacterYaw = Character->GetActorRotation().Yaw;
		Character->GetCameraBoom()->SetRelativeRotation(FRotator(0.0f, CharacterYaw, 0.0f));
		Character->bUseCharacterVectors = false;

		Character->GetCharacterMovement()->RotationRate = Character->DefualtRotationRate;
	}
}

void UCameraManagerComponent::SetSlopeCameraMode()
{
	AProjectProwerCharacter* Character = GetOwningCharacter();
	if(Character)
	{
		const FRotator DesiredRotation = Character->GetActorRotation();
		Character->GetController()->SetControlRotation(DesiredRotation);
		Character->bUseCharacterVectors = true;

		Character->GetCharacterMovement()->RotationRate = Character->DefualtRotationRate * 0.5f;
	}
}

