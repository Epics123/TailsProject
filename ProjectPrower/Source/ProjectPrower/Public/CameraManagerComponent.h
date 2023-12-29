// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CameraManagerComponent.generated.h"

UENUM(BlueprintType)
enum class ECameraMode : uint8
{
	FREE = 0		UMETA(DisplayName = "Free"),
	LOCKED = 1		UMETA(DisplayName = "Locked"),
	LOOKAT = 2		UMETA(DisplayName = "LookAt"),
	SLOPE = 3		UMETA(DisplayName = "Slope"),
	TURNCIRCLE = 4	UMETA(DisplayName = "TurnCircle"),
	CUSTOM = 5		UMETA(DisplayName = "Custom")
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
};
