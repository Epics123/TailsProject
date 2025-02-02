// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "../Data/MotionParams.h"

#include "PlayableBase.generated.h"

UCLASS()
class PROJECTPROWER_API APlayableBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayableBase();

	UFUNCTION(BlueprintCallable, BlueprintGetter)
	float GetCurrentSpeed() { return CurrentSpeed; }

	UFUNCTION(BlueprintCallable, BlueprintSetter)
	void SetCurrentSpeed(float Speed) { CurrentSpeed = Speed; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Called for movement input */
	//void Move(const FInputActionValue& Value);

	/** Called for looking input */
	//void Look(const FInputActionValue& Value);

	void HandleSlopePhysics(bool bAccountForSlope = false);

	//virtual FVector GetMovementForwardVector();
	//virtual FVector GetMovementRightVector();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// Input //
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UPlayerInputData> InputData;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UMotionParams> MotionParams;

	bool bShouldAccountForSlope;

	float Angle = 0.0f;
	float SlopeFactor = 10.0f;
	bool bApplyingDrag;

	float CurrentSpeed = 0.0f;
	float CachedBreakSpeed = 0.0f;

	FVector2D LastMovementInput;
};
