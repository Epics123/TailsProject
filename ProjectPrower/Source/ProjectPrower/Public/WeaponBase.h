// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponBase.generated.h"

UCLASS()
class PROJECTPROWER_API AWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeaponBase();

	~AWeaponBase();

	virtual void FireWeapon(bool bIsAltFire = false){};

	virtual void PostFireWeapon(){};

	virtual void SpawnProjectile(){};

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void SetOwningPlayer(AProjectProwerCharacter* Character) { OwningCharacter = Character; }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool CanFireWeapon() { return bCanFireWeapon; }

	UFUNCTION(BlueprintCallable)
	void SetCanWeaponFire(bool bCanFire) { bCanFireWeapon = bCanFire; }

	void ResetWeaponFire();

	UFUNCTION(BlueprintPure)
	class AProjectProwerCharacter* GetWeaponOwner() const { return OwningCharacter; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* WeaponMesh;

	// Where on the weapon projectiles will be fired from
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USceneComponent* ProjectileLaunchPoint;

protected:
	TObjectPtr<class AProjectProwerCharacter> OwningCharacter;

	bool bCanFireWeapon = true;

	FTimerHandle WeaponFireHandle;
};
