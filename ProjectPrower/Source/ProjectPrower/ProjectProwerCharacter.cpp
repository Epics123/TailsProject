// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjectProwerCharacter.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/ChildActorComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

#include "CameraManagerComponent.h"
#include "WeaponBase.h"

DEFINE_LOG_CATEGORY_STATIC(LogTemplateCharacter, Error, All);

//////////////////////////////////////////////////////////////////////////
// AProjectProwerCharacter

AProjectProwerCharacter::AProjectProwerCharacter(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer.SetDefaultSubobjectClass<UProwerMovementComponent>(ACharacter::CharacterMovementComponentName))
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
		
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	DefaultRotationRate = GetCharacterMovement()->RotationRate;

	// Create camera pivot
	CameraPivot = CreateDefaultSubobject<USceneComponent>(TEXT("CameraPivot"));
	CameraPivot->SetupAttachment(RootComponent);
	CameraPivot->SetRelativeLocation(FVector(0.0f, 0.0f, 160.0f));

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(CameraPivot);
	CameraBoom->TargetArmLength = 500.0f; // The camera follows at this distance behind the character
	CameraBoom->SocketOffset = FVector(0.0f, 0.0f, -100);
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	CameraManager = CreateDefaultSubobject<UCameraManagerComponent>(TEXT("CameraManager"));

	CurrentMovementState = DefaultMovementState;
}

void AProjectProwerCharacter::SetMovementState(TEnumAsByte<EMovementState> NewState)
{
	CurrentMovementState = NewState;

	switch (CurrentMovementState)
	{
	case EMovementState::FREE:
		ApplyFreeMovementStateSettings();
		break;
	case EMovementState::WEAPON:
		ApplyWeaponMovementStateSettings();
		break;
	case EMovementState::LOCKED:
		break;
	default:
		break;
	}
}

void AProjectProwerCharacter::ToggleWeaponVisibility(bool bIsVisible)
{
	if(CurrentWeapon)
	{
		CurrentWeapon->SetActorHiddenInGame(!bIsVisible);
	}
}

void AProjectProwerCharacter::ToggleWeapon()
{
	if(bWeaponEquipped)
	{
		// Update our movement state
		SetMovementState(EMovementState::FREE);
		ToggleWeaponVisibility(false);

		CameraManager->PlayWeaponUnequipTransition();
	}
	else
	{
		// Update our movement state
		SetMovementState(EMovementState::WEAPON);
		ToggleWeaponVisibility(true);

		CameraManager->PlayWeaponEquipTransition();
	}
	bWeaponEquipped = !bWeaponEquipped;
}

void AProjectProwerCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

void AProjectProwerCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	UpdateCameraMode();
	ApplySlopePhysics();
	
	CheckSlopeDetach();
	ResetRotationInAir(DeltaSeconds);
}

//////////////////////////////////////////////////////////////////////////
// Input

void AProjectProwerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AProjectProwerCharacter::Move);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AProjectProwerCharacter::Look);

		// Weapon Equip/Unequip
		EnhancedInputComponent->BindAction(WeaponEquipAction, ETriggerEvent::Triggered, this, &AProjectProwerCharacter::ToggleWeapon);
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void AProjectProwerCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = GetMovementForwardVector();
	
		// get right vector 
		const FVector RightDirection = GetMovementRightVector();

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AProjectProwerCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

FVector AProjectProwerCharacter::GetMovementForwardVector()
{
	if (bUseCharacterVectors)
	{
		// Add forward movement.
		return FVector::VectorPlaneProject(FRotationMatrix(GetActorRotation()).GetScaledAxis(EAxis::X), GetActorQuat().GetAxisZ()).GetSafeNormal();
	}
	else //UseCameraVector
	{
		// Add forward movement based on camera.
		return FVector::VectorPlaneProject(FRotationMatrix(GetControlRotation()).GetScaledAxis(EAxis::X), GetActorQuat().GetAxisZ()).GetSafeNormal();
	}
}

FVector AProjectProwerCharacter::GetMovementRightVector()
{
	const FVector AxisZ = GetActorQuat().GetAxisZ();

	if (bUseCharacterVectors)
	{
		// Add side movement.
		return AxisZ ^ FVector::VectorPlaneProject(FRotationMatrix(GetActorRotation()).GetScaledAxis(EAxis::X), AxisZ).GetSafeNormal();
	}
	else //UseCameraVectors
	{
		// Add side movement based on camera.
		return AxisZ ^ FVector::VectorPlaneProject(FRotationMatrix(GetControlRotation()).GetScaledAxis(EAxis::X), AxisZ).GetSafeNormal();
	}
}

void AProjectProwerCharacter::UpdateCameraMode()
{
	UProwerMovementComponent* MovementComponent = GetProwerMovementComponent();
	if(CameraManager && MovementComponent)
	{
		const FHitResult FloorHit = MovementComponent->CurrentFloor.HitResult;
		if(FloorHit.ImpactNormal.Z <= MovementComponent->GetWalkableFloorZ() && !MovementComponent->IsFalling())
		{
			CameraManager->SetCameraMode(ECameraMode::SLOPE);
		}
		else
		{
			CameraManager->SetCameraMode(ECameraMode::FREE);
		}
	}
}

void AProjectProwerCharacter::ResetRotationInAir(float DeltaSeconds)
{	
	UCharacterMovementComponent* MovementComponent = GetCharacterMovement();
	if(MovementComponent)
	{
		if (MovementComponent->IsFalling())
		{
			FRotator TargetRotation = FRotator(0.0f, GetActorRotation().Yaw, 0.0f);
			SetActorRotation(FMath::RInterpTo(GetActorRotation(), TargetRotation, DeltaSeconds, 10.0f));
		}
	}
}

void AProjectProwerCharacter::ApplySlopePhysics()
{
	UProwerMovementComponent* MovementComponent = GetProwerMovementComponent();
	if(MovementComponent)
	{
		if(GetVelocity().Length() >= MovementComponent->MinSlopeEffectSpeed)
		{
			const FVector SlopeVector = GetActorForwardVector() * (GetActorForwardVector().Z * MovementComponent->SlopeFactor);
			MovementComponent->Velocity += SlopeVector;
		}
	}
}

void AProjectProwerCharacter::CheckSlopeDetach()
{
	UProwerMovementComponent* MovementComponent = GetProwerMovementComponent();
	if (MovementComponent && GetActorUpVector().Z <= (MovementComponent->GetWalkableFloorZ() + 0.035f))
	{
		if (GetVelocity().Length() <= MovementComponent->MinSlopeSpeed)
		{
			const FHitResult FloorHit = MovementComponent->CurrentFloor.HitResult;
			const FVector EjectionVector = (GetSurfaceEjectionVector() * MovementComponent->SlopeEjectForce) * 10000.0f;

			const float ZRange = FMath::GetMappedRangeValueClamped(FVector2D(MovementComponent->GetWalkableFloorZ(), -1.0f), FVector2D(0.15f, 1.0f), GetActorUpVector().Z);

			MovementComponent->AddForce(EjectionVector * ZRange);
		}
	}
}

FVector AProjectProwerCharacter::GetSurfaceEjectionVector(float GravityZMultiplier)
{
	FVector FloorNormal;
	float FloorAngle;

	GetFloorAngle(FloorAngle, FloorNormal);
	return FVector(FloorNormal.X, FloorNormal.Y, GetProwerMovementComponent()->GetGravityDirection().Z * GravityZMultiplier);
}

void AProjectProwerCharacter::GetFloorAngle(float& OutAngle, FVector& OutNormal)
{
	FVector FloorNormal = GetCharacterMovement()->CurrentFloor.HitResult.ImpactNormal;
	OutAngle = FMath::RadiansToDegrees(FMath::Acos(FloorNormal | FVector::UpVector));
	OutNormal = FloorNormal;
}

void AProjectProwerCharacter::ApplyFreeMovementStateSettings()
{
	UProwerMovementComponent* MovementComponent = GetProwerMovementComponent();
	if(MovementComponent)
	{
		MovementComponent->MaxWalkSpeed = 2000.0f;
	}
}

void AProjectProwerCharacter::ApplyWeaponMovementStateSettings()
{
	UProwerMovementComponent* MovementComponent = GetProwerMovementComponent();
	if (MovementComponent)
	{
		MovementComponent->MaxWalkSpeed = 900.0f;
	}
}
