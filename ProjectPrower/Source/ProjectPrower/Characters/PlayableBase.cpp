// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayableBase.h"
#include "PlayerInputData.h"

#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
APlayableBase::APlayableBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayableBase::BeginPlay()
{
	Super::BeginPlay();
	
}

//void APlayableBase::Move(const FInputActionValue& Value)
//{
//	// input is a Vector2D
//	//FVector2D MovementVector = Value.Get<FVector2D>();
//	LastMovementInput = Value.Get<FVector2D>();
//
//	//if (Controller != nullptr)
//	//{
//	//	// find out which way is forward
//	//	const FRotator Rotation = Controller->GetControlRotation();
//	//	const FRotator YawRotation(0, Rotation.Yaw, 0);
//
//	//	// get forward vector
//	//	const FVector ForwardDirection = GetMovementForwardVector();
//
//	//	// get right vector 
//	//	const FVector RightDirection = GetMovementRightVector();
//
//	//	// add movement 
//	//	AddMovementInput(ForwardDirection, MovementVector.Y);
//	//	AddMovementInput(RightDirection, MovementVector.X);
//	//}
//}
//
//void APlayableBase::Look(const FInputActionValue& Value)
//{
//
//}

void APlayableBase::HandleSlopePhysics(bool bAccountForSlope)
{
	if(CachedBreakSpeed == 0.0f)
	{
		CachedBreakSpeed = MotionParams->BreakSpeed;
	}

	if(bAccountForSlope)
	{
		// See https://github.com/R3verseG0d/Project06OSP/blob/main/PlayerBase.cs#L1655
		const FVector WorldUp = FVector(0.0f, 0.0f, 1.0f);
		Angle = FMath::RadiansToDegrees(WorldUp | GetActorForwardVector()) - 90.0f; // "|" = Dot operator

		const float LocalUpDotWorldUp = GetActorUpVector() | WorldUp;
		const float MaxAngle = 0.85f; // TODO: Make this not a constant
		const float GravityFactor = -0.325f;

		const FRotator CameraRotation = FRotator::MakeFromEuler(WorldUp * ((FollowCamera != nullptr) ? FollowCamera->GetRelativeRotation().Yaw : 1.0f));
		const FQuat CameraOrientation = FQuat::MakeFromRotator(CameraRotation);

		FVector OrientedForward = CameraOrientation * FVector(1.0f, 0.0f, 0.0f);
		OrientedForward.Z = 0.0f;
		OrientedForward.Normalize();

		FVector OrientedRight = CameraOrientation * FVector(0.0f, 1.0f, 0.0f);
		OrientedRight.Z = 0.0f;
		OrientedRight.Normalize();

		FVector InputDir = LastMovementInput.X * OrientedRight + LastMovementInput.Y * OrientedForward;
		InputDir.Normalize();
		InputDir = FQuat::MakeFromRotator(FRotationMatrix::MakeFromX(GetActorUpVector() - WorldUp).Rotator()) * InputDir;

		bApplyingDrag = (Angle < 0.0f - SlopeFactor) || Angle > SlopeFactor;

		//FVector V = FVector(0.0f, 1.0f, 0.0f);
		FVector UpXY = FVector(GetActorUpVector().X, GetActorUpVector().Y, 0.0f);
		FVector TargetDir = GetActorUpVector() ^ (GetActorUpVector() ^ -UpXY); // "^" = Cross product
		TargetDir.Normalize();

		if(InputDir != FVector::ZeroVector)
		{
			if(bApplyingDrag && CurrentSpeed > MotionParams->WalkSpeed && CurrentSpeed < MotionParams->MaxSpeed * 2.0f)
			{
				CurrentSpeed += FVector(0.0f, 0.0f, GravityFactor) | GetActorForwardVector();
			}
		}
		else if(LocalUpDotWorldUp > 0.0f && LocalUpDotWorldUp < MaxAngle)
		{
			if(CurrentSpeed > MotionParams->WalkSpeed && CurrentSpeed < MotionParams->MaxSpeed * 2.0f)
			{
				CurrentSpeed += FVector(0.0f, 0.0f, GravityFactor) | GetActorForwardVector();
			}
		}
	}
	else
	{

	}
}

//FVector APlayableBase::GetMovementForwardVector()
//{
//	return FVector();
//}

// Called every frame
void APlayableBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayableBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (InputData)
		{
			// Jumping
			//EnhancedInputComponent->BindAction(InputData->JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
			//EnhancedInputComponent->BindAction(InputData->JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

			// Moving
			//EnhancedInputComponent->BindAction(InputData->MoveAction, ETriggerEvent::Triggered, this, &APlayableBase::Move);

			// Looking
			//EnhancedInputComponent->BindAction(InputData->LookAction, ETriggerEvent::Triggered, this, &APlayableBase::Look);

			// Weapon Equip/Unequip
			//EnhancedInputComponent->BindAction(InputData->WeaponEquipAction, ETriggerEvent::Triggered, this, &AProjectProwerCharacter::ToggleWeapon);

			// Weapon Aim
			//EnhancedInputComponent->BindAction(InputData->WeaponAimAction, ETriggerEvent::Triggered, this, &AProjectProwerCharacter::AimWeapon);
			//EnhancedInputComponent->BindAction(InputData->WeaponAimEndAction, ETriggerEvent::Triggered, this, &AProjectProwerCharacter::AimWeaponEnd);

			// Weapon Fire
			//EnhancedInputComponent->BindAction(InputData->WeaponFireAction, ETriggerEvent::Triggered, this, &AProjectProwerCharacter::FireWeapon);
			//EnhancedInputComponent->BindAction(InputData->WeaponAltFireAction, ETriggerEvent::Triggered, this, &AProjectProwerCharacter::WeaponAltFire);

			// Fly
			//EnhancedInputComponent->BindAction(InputData->FlyAction, ETriggerEvent::Started, this, &AProjectProwerCharacter::StartFlying);
			//EnhancedInputComponent->BindAction(InputData->FlyAction, ETriggerEvent::Completed, this, &AProjectProwerCharacter::StopFlying);
			//EnhancedInputComponent->BindAction(InputData->FlyAction, ETriggerEvent::Triggered, this, &AProjectProwerCharacter::Fly);
		}
	}
	else
	{
		//UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

