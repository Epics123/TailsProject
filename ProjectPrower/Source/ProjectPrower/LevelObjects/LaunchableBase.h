// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LaunchableBase.generated.h"

class AProjectProwerCharacter;

UCLASS()
class PROJECTPROWER_API ALaunchableBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALaunchableBase();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void Launch(AProjectProwerCharacter* Character);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Launch Settings")
	float LaunchPower = 200.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement Locks", meta=(DisplayName="ShouldLockFlight"))
	bool bLockFlight;

	// How long to lock flight after being launched
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement Locks", meta=(EditCondition="bLockFlight"))
	float FlightLockDuration = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement Locks", meta = (DisplayName = "ShouldLockMovement"))
	bool bLockMovement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement Locks", meta=(EditCondition="bLockMovement"))
	float MovementLockDuration = 1.0f;
};
