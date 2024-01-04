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

	UFUNCTION(BlueprintCallable)
	void PlayWeaponEquipTransition();

	UFUNCTION(BlueprintCallable)
	void PlayWeaponUnequipTransition();

	UTimelineComponent* GetWeaponEquipTransitionTimeline() { return WeaponEquipTransition; }
	UTimelineComponent* GetWeaponUnequipTransitionTimeline() { return WeaponUnequipTransition; }

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void SetFreeCameraMode();
	void SetSlopeCameraMode();

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transitions")
	FVector WeaponEquipTargetLocation = FVector(80.0f, 50.0f, 0.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transitions")
	FVector DefaultRelativeCameraOffset = FVector::ZeroVector;

	UPROPERTY(EditDefaultsOnly, Category = "Transitions")
	class UCurveFloat* WeaponTransitionCurve;

	FOnTimelineFloat WeaponEquipTransitionUpdateDelegate {};
	FOnTimelineEvent WeaponEquipTransitionFinished {};

	FOnTimelineFloat WeaponUnequipTransitionUpdateDelegate{};
	FOnTimelineEvent WeaponUnequipTransitionFinished{};

protected:
	UTimelineComponent* WeaponEquipTransition;
	UTimelineComponent* WeaponUnequipTransition;
};
