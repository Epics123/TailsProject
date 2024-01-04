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

UCLASS(config=Game)
class AProjectProwerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AProjectProwerCharacter(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	UProwerMovementComponent* GetProwerMovementComponent() { return Cast<UProwerMovementComponent>(GetMovementComponent()); }

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

	UFUNCTION(BlueprintCallable, BlueprintPure)
	class AWeaponBase* GetCurrentWeapon() { return CurrentWeapon; }

	UFUNCTION(BlueprintCallable)
	void SetWeapon(class AWeaponBase* Weapon) { CurrentWeapon = Weapon; }

	UFUNCTION(BlueprintCallable)
	void ToggleWeaponVisibility(bool bIsVisible);

	UFUNCTION(BlueprintCallable)
	void ToggleWeapon();

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	virtual FVector GetMovementForwardVector();
	virtual FVector GetMovementRightVector();

	void UpdateCameraMode();
	void ResetRotationInAir(float DeltaSeconds);

	void ApplySlopePhysics();
	void CheckSlopeDetach();
	FVector GetSurfaceEjectionVector(float GravityZMultiplier = 1.0f);
	void GetFloorAngle(float& OutAngle, FVector& OutNormal);

	void ApplyFreeMovementStateSettings();
	void ApplyWeaponMovementStateSettings();
			
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay();

	virtual void Tick(float DeltaSeconds) override;

public:
	/**
	* If true, the forward and right vectors of the character will be used for moving instead of the camera vectors.
	*/
	UPROPERTY(Category = "Movement", BlueprintReadWrite, EditAnywhere)
	bool bUseCharacterVectors = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator DefaultRotationRate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	EMovementState DefaultMovementState = EMovementState::FREE;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bWeaponEquipped = false;

private:
	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USceneComponent* CameraPivot;

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

	/** Weapon Equip/Unequip Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* WeaponEquipAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraManagerComponent* CameraManager;

	EMovementState CurrentMovementState;

	TObjectPtr<class AWeaponBase> CurrentWeapon;
};

