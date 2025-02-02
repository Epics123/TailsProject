// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/TimelineComponent.h"
#include "CameraManagerComponent.generated.h"

UENUM(BlueprintType)
enum class ECameraMode : uint8
{
	FREE = 0		UMETA(DisplayName = "Free"),
	LOCKED = 1		UMETA(DisplayName = "Locked"),
	LOOKAT = 2		UMETA(DisplayName = "LookAt"),
	SLOPE = 3		UMETA(DisplayName = "Slope"),
	TURNCIRCLE = 4	UMETA(DisplayName = "TurnCircle"),
	WEAPON = 5		UMETA(DisplayName = "Weapon"),
	CUSTOM = 6		UMETA(DisplayName = "Custom")
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTPROWER_API UCameraManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCameraManagerComponent();

	class AProjectProwerCharacter* GetOwningCharacter() { return OwningCharacter; }

	UFUNCTION(BlueprintCallable)
	void SetCameraMode(ECameraMode NewMode);

	void OnCameraModeChanged(ECameraMode PrevMode, ECameraMode NewMode);

	UFUNCTION(BlueprintCallable)
	void ResetCameraAlignment(ECameraMode PrevMode, ECameraMode NewMode);

	UFUNCTION()
	void WeaponEquipTransitionUpdate(float Alpha);
	UFUNCTION()
	void OnWeaponEquipTransitionFinished();

	UFUNCTION()
	void WeaponUnequipTransitionUpdate(float Alpha);
	UFUNCTION()
	void OnWeaponUnequipTransitionFinished();

	UFUNCTION()
	void WeaponAimTransitionUpdate(float Alpha);
	UFUNCTION()
	void OnWeaponAimTransitionFinished();

	UFUNCTION()
	void WeaponAimEndTransitionUpdate(float Alpha);
	UFUNCTION()
	void OnWeaponAimEndTransitionFinished();

	UFUNCTION(BlueprintCallable)
	void PlayWeaponEquipTransition();

	UFUNCTION(BlueprintCallable)
	void PlayWeaponUnequipTransition();

	UFUNCTION(BlueprintCallable)
	void PlayAimTransition();

	UFUNCTION(BlueprintCallable)
	void PlayAimEndTransition();

	UTimelineComponent* GetWeaponEquipTransitionTimeline() { return WeaponEquipTransition; }
	UTimelineComponent* GetWeaponUnequipTransitionTimeline() { return WeaponUnequipTransition; }
	UTimelineComponent* GetWeaponAimTransitionTimeline() { return WeaponAimTransition; }
	UTimelineComponent* GetWeaponAimEndTransitionTimeline() { return WeaponAimEndTransition; }

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	/*void SetFreeCameraMode();
	void SetSlopeCameraMode();*/

public:
	TObjectPtr<class AProjectProwerCharacter> OwningCharacter;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	ECameraMode DefaultCameraMode = ECameraMode::FREE;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	ECameraMode LoopingCameraMode = ECameraMode::SLOPE;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECameraMode CurrentCameraMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator ViewRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bResetCameraAfterLooping = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transitions|WeaponEquip")
	FVector WeaponEquipTargetLocation = FVector(0.0f, 50.0f, 0.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transitions|WeaponEquip")
	FVector DefaultRelativeCameraOffset = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transitions|WeaponEquip")
	FVector TargetCameraPivotLocation = FVector(0.0f, 0.0f, 42.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transitions|WeaponEquip")
	FVector DefaultCameraPivotLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transitions|WeaponEquip")
	float WeaponEquipArmLength = 200.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transitions|WeaponEquip")
	float DefaultArmLength = 500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transitions|WeaponEquip")
	FVector TargetSocketOffset = FVector(0.0f, 0.0f, 0.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transitions|WeaponEquip")
	FVector DefaultSocketOffset;

	UPROPERTY(EditDefaultsOnly, Category = "Transitions|WeaponEquip")
	class UCurveFloat* WeaponTransitionCurve;

	UPROPERTY(EditDefaultsOnly, Category = "Transitions|WeaponAim")
	float AimTargetFOV = 60.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Transitions|WeaponAim")
	float DefaultCameraFOV = 80.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Transitions|WeaponAim")
	class UCurveFloat* WeaponAimCurve;

	FOnTimelineFloat WeaponEquipTransitionUpdateDelegate {};
	FOnTimelineEvent WeaponEquipTransitionFinished {};

	FOnTimelineFloat WeaponUnequipTransitionUpdateDelegate{};
	FOnTimelineEvent WeaponUnequipTransitionFinished{};

	FOnTimelineFloat WeaponAimTransitionUpdateDelegate{};
	FOnTimelineEvent WeaponAimTransitionFinished{};

	FOnTimelineFloat WeaponAimEndTransitionUpdateDelegate{};
	FOnTimelineEvent WeaponAimEndTransitionFinished{};

protected:
	UTimelineComponent* WeaponEquipTransition;
	UTimelineComponent* WeaponUnequipTransition;
	UTimelineComponent* WeaponAimTransition;
	UTimelineComponent* WeaponAimEndTransition;

	float CurrentCameraFOV;
};
