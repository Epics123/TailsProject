// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraManagerComponent.h"
#include "../ProjectProwerCharacter.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values for this component's properties
UCameraManagerComponent::UCameraManagerComponent()
{
	OwningCharacter = Cast<AProjectProwerCharacter>(GetOwner());
	CurrentCameraMode = DefaultCameraMode;
	CurrentCameraFOV = DefaultCameraFOV;

	WeaponEquipTransition = CreateDefaultSubobject<UTimelineComponent>(TEXT("WeaponEquipTransition"));
	WeaponUnequipTransition = CreateDefaultSubobject<UTimelineComponent>(TEXT("WeaponUnequipTransition"));
	WeaponAimTransition = CreateDefaultSubobject<UTimelineComponent>(TEXT("WeaponAimTransition"));
	WeaponAimEndTransition = CreateDefaultSubobject<UTimelineComponent>(TEXT("WeaponAimEndTransition"));

	WeaponEquipTransitionUpdateDelegate.BindUFunction(this, FName("WeaponEquipTransitionUpdate"));
	WeaponEquipTransitionFinished.BindUFunction(this, FName("OnWeaponEquipTransitionFinished"));

	WeaponUnequipTransitionUpdateDelegate.BindUFunction(this, FName("WeaponUnequipTransitionUpdate"));
	WeaponUnequipTransitionFinished.BindUFunction(this, FName("OnWeaponUnequipTransitionFinished"));

	WeaponAimTransitionUpdateDelegate.BindUFunction(this, FName("WeaponAimTransitionUpdate"));
	WeaponAimTransitionFinished.BindUFunction(this, FName("OnWeaponAimTransitionFinished"));

	WeaponAimEndTransitionUpdateDelegate.BindUFunction(this, FName("WeaponAimEndTransitionUpdate"));
	WeaponAimEndTransitionFinished.BindUFunction(this, FName("OnWeaponAimEndTransitionFinished"));
}


void UCameraManagerComponent::SetCameraMode(ECameraMode NewMode)
{
	OnCameraModeChanged(CurrentCameraMode, NewMode);
	CurrentCameraMode = NewMode;

	switch (CurrentCameraMode)
	{
	case ECameraMode::FREE:
		//SetFreeCameraMode();
		break;
	case ECameraMode::LOCKED:
		break;
	case ECameraMode::LOOKAT:
		break;
	case ECameraMode::SLOPE:
		//SetSlopeCameraMode();
		break;
	case ECameraMode::TURNCIRCLE:
		break;
	case ECameraMode::WEAPON:
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

void UCameraManagerComponent::WeaponEquipTransitionUpdate(float Alpha)
{
	AProjectProwerCharacter* Character = GetOwningCharacter();
	if(Character)
	{
		const FVector TargetLocation = FMath::Lerp(Character->GetFollowCamera()->GetRelativeLocation(), WeaponEquipTargetLocation, Alpha);
		Character->GetFollowCamera()->SetRelativeLocation(TargetLocation);

		const float TargetArmLength = FMath::Lerp(Character->GetCameraBoom()->TargetArmLength, WeaponEquipArmLength, Alpha);
		Character->GetCameraBoom()->TargetArmLength = TargetArmLength;

		const FVector TargetPivotLocation = FMath::Lerp(Character->GetCameraPivot()->GetRelativeLocation(), TargetCameraPivotLocation, Alpha);
		Character->GetCameraPivot()->SetRelativeLocation(TargetPivotLocation);

		const FVector SocketOffset = FMath::Lerp(Character->GetCameraBoom()->SocketOffset, TargetSocketOffset, Alpha);
		Character->GetCameraBoom()->SocketOffset = SocketOffset;
	}
}

void UCameraManagerComponent::OnWeaponEquipTransitionFinished()
{

}

void UCameraManagerComponent::WeaponUnequipTransitionUpdate(float Alpha)
{
	AProjectProwerCharacter* Character = GetOwningCharacter();
	if (Character)
	{
		const FVector TargetLocation = FMath::Lerp(Character->GetFollowCamera()->GetRelativeLocation(), DefaultRelativeCameraOffset, Alpha);
		Character->GetFollowCamera()->SetRelativeLocation(TargetLocation);

		const float TargetArmLength = FMath::Lerp(Character->GetCameraBoom()->TargetArmLength, DefaultArmLength, Alpha);
		Character->GetCameraBoom()->TargetArmLength = TargetArmLength;

		const FVector TargetPivotLocation = FMath::Lerp(Character->GetCameraPivot()->GetRelativeLocation(), DefaultCameraPivotLocation, Alpha);
		Character->GetCameraPivot()->SetRelativeLocation(TargetPivotLocation);

		const FVector SocketOffset = FMath::Lerp(Character->GetCameraBoom()->SocketOffset, DefaultSocketOffset, Alpha);
		Character->GetCameraBoom()->SocketOffset = SocketOffset;
	}
}

void UCameraManagerComponent::OnWeaponUnequipTransitionFinished()
{
	
}

void UCameraManagerComponent::WeaponAimTransitionUpdate(float Alpha)
{
	AProjectProwerCharacter* Character = GetOwningCharacter();
	if (Character)
	{
		CurrentCameraFOV = FMath::Lerp(CurrentCameraFOV, AimTargetFOV, Alpha);
		Character->GetFollowCamera()->SetFieldOfView(CurrentCameraFOV);
	}
}

void UCameraManagerComponent::OnWeaponAimTransitionFinished()
{

}

void UCameraManagerComponent::WeaponAimEndTransitionUpdate(float Alpha)
{
	AProjectProwerCharacter* Character = GetOwningCharacter();
	if (Character)
	{
		CurrentCameraFOV = FMath::Lerp(CurrentCameraFOV, DefaultCameraFOV, Alpha);
		Character->GetFollowCamera()->SetFieldOfView(CurrentCameraFOV);
	}
}

void UCameraManagerComponent::OnWeaponAimEndTransitionFinished()
{

}

void UCameraManagerComponent::PlayWeaponEquipTransition()
{
	if(WeaponUnequipTransition->IsPlaying())
	{
		WeaponUnequipTransition->Stop();
	}
	WeaponEquipTransition->PlayFromStart();
}

void UCameraManagerComponent::PlayWeaponUnequipTransition()
{
	if (WeaponEquipTransition->IsPlaying())
	{
		WeaponEquipTransition->Stop();
	}
	WeaponUnequipTransition->PlayFromStart();
}

void UCameraManagerComponent::PlayAimTransition()
{
	if(WeaponAimEndTransition->IsPlaying())
	{
		WeaponAimEndTransition->Stop();
	}
	WeaponAimTransition->PlayFromStart();
	
	OwningCharacter->GetLocalViewingPlayerController()->PlayerCameraManager->ViewPitchMax = 35.0f;
	OwningCharacter->GetLocalViewingPlayerController()->PlayerCameraManager->ViewPitchMin = -35.0f;
}

void UCameraManagerComponent::PlayAimEndTransition()
{
	if (WeaponAimTransition->IsPlaying())
	{
		WeaponAimTransition->Stop();
	}
	WeaponAimEndTransition->PlayFromStart();

	OwningCharacter->GetLocalViewingPlayerController()->PlayerCameraManager->ViewPitchMax = 90.0f;
	OwningCharacter->GetLocalViewingPlayerController()->PlayerCameraManager->ViewPitchMin = -90.0f;
}

// Called when the game starts
void UCameraManagerComponent::BeginPlay()
{
	Super::BeginPlay();

	if(WeaponTransitionCurve)
	{
		WeaponEquipTransition->AddInterpFloat(WeaponTransitionCurve, WeaponEquipTransitionUpdateDelegate, FName("Alpha"));
		WeaponEquipTransition->SetTimelineFinishedFunc(WeaponEquipTransitionFinished);

		WeaponUnequipTransition->AddInterpFloat(WeaponTransitionCurve, WeaponUnequipTransitionUpdateDelegate, FName("Alpha"));
		WeaponUnequipTransition->SetTimelineFinishedFunc(WeaponUnequipTransitionFinished);
	}

	if(WeaponAimCurve)
	{
		WeaponAimTransition->AddInterpFloat(WeaponAimCurve, WeaponAimTransitionUpdateDelegate, FName("Alpha"));
		WeaponAimTransition->SetTimelineFinishedFunc(WeaponAimTransitionFinished);

		WeaponAimEndTransition->AddInterpFloat(WeaponAimCurve, WeaponAimEndTransitionUpdateDelegate, FName("Alpha"));
		WeaponAimEndTransition->SetTimelineFinishedFunc(WeaponAimEndTransitionFinished);
	}
	
}

//void UCameraManagerComponent::SetFreeCameraMode()
//{
//	AProjectProwerCharacter* Character = GetOwningCharacter();
//	if (Character)
//	{
//		const float CharacterYaw = Character->GetActorRotation().Yaw;
//		Character->GetCameraBoom()->SetRelativeRotation(FRotator(0.0f, CharacterYaw, 0.0f));
//		//Character->bUseCharacterVectors = false;
//
//		Character->GetCameraBoom()->bEnableCameraLag = false;
//		Character->GetCameraBoom()->bEnableCameraRotationLag = false;
//		Character->GetCameraBoom()->ProbeSize = 12.0f;
//
//		Character->GetCharacterMovement()->RotationRate = Character->DefaultRotationRate;
//	}
//}
//
//void UCameraManagerComponent::SetSlopeCameraMode()
//{
//	AProjectProwerCharacter* Character = GetOwningCharacter();
//	if(Character)
//	{
//		const FRotator DesiredRotation = Character->GetActorRotation();
//		Character->GetController()->SetControlRotation(DesiredRotation);
//		//Character->bUseCharacterVectors = true;
//
//		Character->GetCameraBoom()->bEnableCameraLag = true;
//		Character->GetCameraBoom()->bEnableCameraRotationLag = true;
//		Character->GetCameraBoom()->CameraLagSpeed = 15.0f;
//		Character->GetCameraBoom()->CameraLagMaxDistance = 300.0f;
//		Character->GetCameraBoom()->ProbeSize = 50.0f;
//
//		Character->GetCharacterMovement()->RotationRate = Character->DefaultRotationRate * 0.5f;
//	}
//}

