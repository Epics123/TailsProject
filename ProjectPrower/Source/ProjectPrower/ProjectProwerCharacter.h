// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"

#include "ProwerMovementComponent.h"
#include "Camera/ProwerCameraComponent.h"

#include "ProjectProwerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

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

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UProwerCameraComponent* GetFollowCamera() const { return FollowCamera; }

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

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void OnWeaponEquipped();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void OnWeaponUnequipped();

	UFUNCTION(BlueprintPure)
	bool IsWeaponEquipped() const;

	UFUNCTION()
	void FireWeapon();

	UFUNCTION()
	void WeaponAltFire();

	UFUNCTION(BlueprintCallable)
	void ToggleWeaponAltFire();

	UFUNCTION(BlueprintPure)
	bool IsAiming() const;

	UFUNCTION(BlueprintPure)
	bool IsFlying();

	UFUNCTION(BlueprintPure)
	bool IsFlightBlocked() const;

	UFUNCTION(BlueprintCallable)
	void SetFlightBlocked(bool bBlock);

	UFUNCTION(BlueprintPure)
	bool IsMoveInputBlocked() const;

	UFUNCTION(BlueprintCallable)
	void SetMoveInputBlocked(bool bBlock);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void OnMoveInputPressed();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void OnMoveInputReleased();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void ToggleJumpballMesh(bool bShowJumpball);

	UFUNCTION(BlueprintCallable)
	void ResetFlightState();
	
	UFUNCTION()
	void StartFlying();
	UFUNCTION(BlueprintCallable)
	void StopFlying();

	UFUNCTION(BlueprintCallable)
	float GetJumpballPitchDuringJump(float ApexProximity, float MinDownwardRotation, float MaxUpwardRotation);

	USceneComponent* GetCameraPivot() { return CameraPivot; }

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	void MoveReleased();

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	void AimWeapon();
	void AimWeaponEnd();

	void ResetRotationInAir(float DeltaSeconds);

	class UPlayerInputData* GetInputData() { return InputData; }
			
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay();

	virtual void Tick(float DeltaSeconds) override;

	virtual void Jump() override;
	virtual void Landed(const FHitResult& Hit) override;

	virtual void DisplayDebug(class UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos) override;

public:

	UPROPERTY(Category = "Movement", EditAnywhere, BlueprintReadWrite)
	FRotator DefaultRotationRate;

	UPROPERTY(Category = "Movement", EditAnywhere, BlueprintReadWrite)
	bool bIsFlying = false;

	UPROPERTY(Category = "Movement", BlueprintReadWrite)
	float VerticalFlyDirection = 0.0f;

	UPROPERTY(Category = "Tags", EditAnywhere, BlueprintReadWrite)
	FGameplayTagContainer DefaultTags;

	UPROPERTY(BlueprintReadWrite)
	FGameplayTagContainer GameplayTags;

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
	UProwerCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USceneComponent* CameraPivot;

	// Input //
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UPlayerInputData> InputData;

	UProwerMovementComponent* ProwerMovementComponent;

	TObjectPtr<class AWisponBase> CurrentWeapon;

	bool bFlyInputHeld = false;

	FVector GravityDirection = FVector(0, 0, -1);
};

