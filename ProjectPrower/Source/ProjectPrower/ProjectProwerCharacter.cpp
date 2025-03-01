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

#include "WisponBase.h"
#include "PlayerInputData.h"

DEFINE_LOG_CATEGORY_STATIC(LogTemplateCharacter, Error, All);

//////////////////////////////////////////////////////////////////////////
// AProjectProwerCharacter

AProjectProwerCharacter::AProjectProwerCharacter(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer.SetDefaultSubobjectClass<UProwerMovementComponent>(ACharacter::CharacterMovementComponentName))
{
	ProwerMovementComponent = Cast<UProwerMovementComponent>(GetMovementComponent());

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
		
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	//GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
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
	FollowCamera = CreateDefaultSubobject<UProwerCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	CurrentMovementState = DefaultMovementState;

	ProwerMovementComponent->OnFlightExhauseted.AddDynamic(this, &AProjectProwerCharacter::StopFlying);
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
		UnequipWeapon();
	}
	else
	{
		EquipWeapon();
	}
	bWeaponEquipped = !bWeaponEquipped;
}

void AProjectProwerCharacter::EquipWeapon()
{
	if(bCanEquipWeapon)
	{
		// Update our movement state
		SetMovementState(EMovementState::WEAPON);
		ToggleWeaponVisibility(true);
		CameraBoom->ProbeSize = 5.0f;
	}
}

void AProjectProwerCharacter::UnequipWeapon()
{
	// Make sure we are no longer aiming
	AimWeaponEnd();

	// Update our movement state
	SetMovementState(EMovementState::FREE);
	ToggleWeaponVisibility(false);
	CameraBoom->ProbeSize = 12.0f;
}

void AProjectProwerCharacter::FireWeapon()
{
	if(CurrentMovementState == EMovementState::WEAPON && CurrentWeapon)
	{
		CurrentWeapon->FireWeapon();
	}
}

void AProjectProwerCharacter::WeaponAltFire()
{
	if (CurrentMovementState == EMovementState::WEAPON && CurrentWeapon)
	{
		CurrentWeapon->FireWeapon(true);
	}
}

void AProjectProwerCharacter::ToggleWeaponAltFire()
{
	if(CurrentWeapon)
	{
		const bool IsInAltFire = CurrentWeapon->IsInAltFire();
		CurrentWeapon->SetAltFire(!IsInAltFire);
	}
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
			if(InputData)
			{
				UInputMappingContext* DefaultMappingContext = InputData->DefaultMappingContext;
				if(DefaultMappingContext)
				{
					Subsystem->AddMappingContext(DefaultMappingContext, 0);
				}	
			}
			
		}
	}

	OnMoveInputReleased(); // Used to kick off idle camera if we don't move when first starting the game
}

void AProjectProwerCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	//UpdateCameraMode();
	//ApplySlopePhysics();
	
	//CheckSlopeDetach();

	ResetRotationInAir(DeltaSeconds);

	//SmoothResetVerticalFlyDirection(DeltaSeconds);
}

void AProjectProwerCharacter::Landed(const FHitResult& Hit)
{
	Super::Landed(Hit);

	ResetFlightState();
}

//////////////////////////////////////////////////////////////////////////
// Input

void AProjectProwerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		
		if(InputData)
		{
			// Jumping
			EnhancedInputComponent->BindAction(InputData->JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
			EnhancedInputComponent->BindAction(InputData->JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

			// Moving
			EnhancedInputComponent->BindAction(InputData->MoveAction, ETriggerEvent::Triggered, this, &AProjectProwerCharacter::Move);
			EnhancedInputComponent->BindAction(InputData->MoveAction, ETriggerEvent::Completed, this, &AProjectProwerCharacter::MoveReleased);

			// Looking
			EnhancedInputComponent->BindAction(InputData->LookAction, ETriggerEvent::Triggered, this, &AProjectProwerCharacter::Look);

			// Weapon Equip/Unequip
			EnhancedInputComponent->BindAction(InputData->WeaponEquipAction, ETriggerEvent::Triggered, this, &AProjectProwerCharacter::ToggleWeapon);

			// Weapon Aim
			EnhancedInputComponent->BindAction(InputData->WeaponAimAction, ETriggerEvent::Triggered, this, &AProjectProwerCharacter::AimWeapon);
			EnhancedInputComponent->BindAction(InputData->WeaponAimEndAction, ETriggerEvent::Triggered, this, &AProjectProwerCharacter::AimWeaponEnd);

			// Weapon Fire
			EnhancedInputComponent->BindAction(InputData->WeaponFireAction, ETriggerEvent::Triggered, this, &AProjectProwerCharacter::FireWeapon);
			EnhancedInputComponent->BindAction(InputData->WeaponAltFireAction, ETriggerEvent::Triggered, this, &AProjectProwerCharacter::WeaponAltFire);

			// Fly
			EnhancedInputComponent->BindAction(InputData->FlyAction, ETriggerEvent::Started, this, &AProjectProwerCharacter::StartFlying);
			EnhancedInputComponent->BindAction(InputData->FlyAction, ETriggerEvent::Completed, this, &AProjectProwerCharacter::StopFlying);
		}
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

	const APlayerController* PlayerController = Cast<APlayerController>(Controller);

	if (PlayerController != nullptr)
	{
		const UProwerMovementComponent* MovementComp = GetProwerMovementComponent();

		const FVector SurfaceNormal = MovementComp->GetCurrentSurfaceNormal();
		const bool bUseCharacterVectors = (!bIsFlying && ((SurfaceNormal | FVector(0, 0, 1)) < MovementComp->MaxCameraVectorAngle)) || MovementComp->bForceCharacterVectors;

		if(bUseCharacterVectors)
		{
			const FVector VelocityDir = MovementComp->GetLastUpdateVelocity().GetSafeNormal();

			// get forward vector
			const FVector ForwardDirection = VelocityDir.IsNearlyZero(10.0f) ? GetActorForwardVector() : VelocityDir;

			// get right vector 
			const FVector RightDirection = (MovementComp->GetCurrentSurfaceNormal() ^ ForwardDirection).GetSafeNormal();

			//add movement 
			AddMovementInput(ForwardDirection, MovementVector.Y);
			AddMovementInput(RightDirection, MovementVector.X);
		}
		else
		{
			const FRotator CameraRotation = PlayerController->PlayerCameraManager->GetCameraRotation();
			FVector CameraForward = CameraRotation.Vector();
			FVector CameraRight = FRotationMatrix(CameraRotation).GetScaledAxis(EAxis::Y);

			CameraForward = (CameraForward - (CameraForward | SurfaceNormal) * SurfaceNormal).GetSafeNormal();
			CameraRight = (CameraRight - (CameraRight | SurfaceNormal) * SurfaceNormal).GetSafeNormal();

			const FVector MoveDirection = ((CameraForward * MovementVector.Y) + (CameraRight * MovementVector.X)).GetSafeNormal();
			AddMovementInput(MoveDirection, 1.0f);
		}

		OnMoveInputPressed();
	}
}

void AProjectProwerCharacter::MoveReleased()
{
	OnMoveInputReleased();
}

void AProjectProwerCharacter::Look(const FInputActionValue& Value)
{
	const float AxisMultiplier = IsAiming() ? 0.25f : 1.0f;

	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>() * AxisMultiplier;

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AProjectProwerCharacter::AimWeapon()
{
	if (CurrentMovementState == EMovementState::WEAPON)
	{
		bIsAiming = true;
		bUseControllerRotationYaw = true;
		
		UProwerMovementComponent* MovementComponent = GetProwerMovementComponent();
		MovementComponent->bOrientRotationToMovement = false;
		//MovementComponent->MaxWalkSpeed = MovementComponent->DefaultAimWalkSpeed;
		if(MovementComponent->Velocity.Length() >= MovementComponent->MaxWalkSpeed)
		{
			MovementComponent->Velocity = MovementComponent->Velocity.GetSafeNormal() * MovementComponent->MaxWalkSpeed;
		}
		GetLocalViewingPlayerController()->PlayerCameraManager->ViewPitchMax = 20.0f;
		GetLocalViewingPlayerController()->PlayerCameraManager->ViewPitchMin = -15.0f;

		OnAimStarted.Broadcast();
	}
}

void AProjectProwerCharacter::AimWeaponEnd()
{
	if (CurrentMovementState == EMovementState::WEAPON)
	{
		bIsAiming = false;
		bUseControllerRotationYaw = false;
		
		UProwerMovementComponent* MovementComponent = GetProwerMovementComponent();
		MovementComponent->bOrientRotationToMovement = true;
		//MovementComponent->MaxWalkSpeed = MovementComponent->DefaultWeaponWalkSpeed;

		GetLocalViewingPlayerController()->PlayerCameraManager->ViewPitchMax = 90.0f;
		GetLocalViewingPlayerController()->PlayerCameraManager->ViewPitchMin = -90.0f;

		OnAimEnded.Broadcast();
	}
}

void AProjectProwerCharacter::StartFlying()
{
	UProwerMovementComponent* MovementComponent = GetProwerMovementComponent();
	if(MovementComponent->IsFalling() && !MovementComponent->bFlightExhausted)
	{
		StopJumping();
 		ToggleJumpballMesh(false);

		MovementComponent->SetMovementMode(MOVE_Flying);
		MovementComponent->MaxAcceleration = 2048.0f;

		if(MovementComponent->bHasFlightReset)
		{
			/// TODO: Handle flying w/ custom gravity
			MovementComponent->MaxFlightZ = (GetActorLocation() + (FVector(0.0f, 0.0f, 1.0f) * MovementComponent->MaxVerticalFlyDistance)).Z;
			MovementComponent->bHasFlightReset = false;
		}

		bIsFlying = true;
		MovementComponent->bFlightInputHeld = true;
	}
}

void AProjectProwerCharacter::StopFlying()
{
	UProwerMovementComponent* MovementComponent = GetProwerMovementComponent();
	if (MovementComponent->MovementMode == EMovementMode::MOVE_Flying)
	{
		MovementComponent->SetMovementMode(MOVE_Falling);
		MovementComponent->MaxAcceleration = 600.0f;
	}

	MovementComponent->bFlightInputHeld = false;
}

void AProjectProwerCharacter::ResetFlightState()
{
	UProwerMovementComponent* MovementComponent = GetProwerMovementComponent();
	if (MovementComponent)
	{
		StopFlying();

		MovementComponent->ResetFlightTime();
		MovementComponent->bFlightExhausted = false;

		bIsFlying = false;
		MovementComponent->bHasFlightReset = true;
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

void AProjectProwerCharacter::ApplyFreeMovementStateSettings()
{
	UProwerMovementComponent* MovementComponent = GetProwerMovementComponent();
	if(MovementComponent)
	{
		//MovementComponent->MaxWalkSpeed = MovementComponent->DefaultWalkSpeed;
	}

	bIsAiming = false;
}

void AProjectProwerCharacter::ApplyWeaponMovementStateSettings()
{
	UProwerMovementComponent* MovementComponent = GetProwerMovementComponent();
	if (MovementComponent)
	{
		//MovementComponent->MaxWalkSpeed = MovementComponent->DefaultWeaponWalkSpeed;
		if(MovementComponent->Velocity.Length() > MovementComponent->MaxWalkSpeed)
		{
			MovementComponent->Velocity = MovementComponent->Velocity.GetSafeNormal() * MovementComponent->MaxWalkSpeed;
		}
	}
}
