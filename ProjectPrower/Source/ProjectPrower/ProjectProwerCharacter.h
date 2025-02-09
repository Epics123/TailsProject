// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"

#include "ProwerMovementComponent.h"

#include "ProjectProwerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UENUM(BlueprintType)
enum class EMovementState
{
	FREE = 0	UMETA(DisplayName = "Free"),
	WEAPON = 1	UMETA(DisplayName = "Weapon"),
	LOCKED = 2	UMETA(DisplayName = "Locked")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAimStartedDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAimEndedDelegate);

UCLASS(config=Game)
class AProjectProwerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AProjectProwerCharacter(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	UProwerMovementComponent* GetProwerMovementComponent() { return ProwerMovementComponent; }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	class UCameraManagerComponent* GetCameraManager() const { return CameraManager; }

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	TEnumAsByte<EMovementState> GetCurrentMovementState() { return CurrentMovementState; }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	TEnumAsByte<EMovementState> GetDefaultMovementState() { return DefaultMovementState; }

	UFUNCTION(BlueprintCallable)
	void SetMovementState(TEnumAsByte<EMovementState> NewState);

	/* Returns true if StateToCheck matches the current movement state*/
	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool IsInMovementState(TEnumAsByte<EMovementState> StateToCheck) { return CurrentMovementState == StateToCheck; }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	class AWisponBase* GetCurrentWeapon() { return CurrentWeapon; }

	UFUNCTION(BlueprintCallable)
	void SetWeapon(class AWisponBase* Weapon) { CurrentWeapon = Weapon; }

	UFUNCTION(BlueprintCallable)
	void ToggleWeaponVisibility(bool bIsVisible);

	UFUNCTION(BlueprintCallable)
	void ToggleWeapon();

	UFUNCTION(BlueprintCallable)
	void EquipWeapon();

	UFUNCTION(BlueprintCallable)
	void UnequipWeapon();

	UFUNCTION()
	void FireWeapon();

	UFUNCTION()
	void WeaponAltFire();

	UFUNCTION(BlueprintCallable)
	void ToggleWeaponAltFire();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool IsAiming() { return CurrentMovementState == EMovementState::WEAPON && bIsAiming; }

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void ToggleJumpballMesh(bool bShowJumpball);

	UFUNCTION(BlueprintCallable)
	void ResetFlightState();
	
	UFUNCTION()
	void StartFlying();
	UFUNCTION(BlueprintCallable)
	void StopFlying();

	USceneComponent* GetCameraPivot() { return CameraPivot; }

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	void AimWeapon();
	void AimWeaponEnd();

	void UpdateCameraMode();
	void ResetRotationInAir(float DeltaSeconds);

	void ApplySlopePhysics();
	void CheckSlopeDetach();
	FVector GetSurfaceEjectionVector(float GravityZMultiplier = 1.0f);
	void GetFloorAngle(float& OutAngle, FVector& OutNormal);

	void ApplyFreeMovementStateSettings();
	void ApplyWeaponMovementStateSettings();

	class UPlayerInputData* GetInputData() { return InputData; }
			
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay();

	virtual void Tick(float DeltaSeconds) override;

	virtual void Landed(const FHitResult& Hit) override;

public:

	UPROPERTY(Category = "Movement", EditAnywhere, BlueprintReadWrite)
	FRotator DefaultRotationRate;

	UPROPERTY(Category = "Movement", EditDefaultsOnly, BlueprintReadOnly)
	EMovementState DefaultMovementState = EMovementState::FREE;

	UPROPERTY(Category = "Movement", EditAnywhere, BlueprintReadWrite)
	bool bIsFlying = false;

	UPROPERTY(Category = "Movement", BlueprintReadWrite)
	float VerticalFlyDirection = 0.0f;

	UPROPERTY(Category = "Weapon", EditAnywhere, BlueprintReadWrite)
	bool bWeaponEquipped = false;

	UPROPERTY(Category = "Weapon", EditAnywhere, BlueprintReadWrite)
	bool bCanEquipWeapon = true;

	UPROPERTY(BlueprintAssignable)
	FAimStartedDelegate OnAimStarted;

	UPROPERTY(BlueprintAssignable)
	FAimEndedDelegate OnAimEnded;

private:
	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USceneComponent* CameraPivot;

	// Input //
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UPlayerInputData> InputData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UCameraManagerComponent* CameraManager;

	UProwerMovementComponent* ProwerMovementComponent;

	EMovementState CurrentMovementState;

	TObjectPtr<class AWisponBase> CurrentWeapon;

	bool bIsAiming = false;

	bool bFlyInputHeld = false;

	FVector GravityDirection = FVector(0, 0, -1);
};

