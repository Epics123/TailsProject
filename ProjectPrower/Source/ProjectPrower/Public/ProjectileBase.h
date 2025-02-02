// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileBase.generated.h"

UCLASS()
class PROJECTPROWER_API AProjectileBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectileBase();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	class UProjectileMovementComponent* GetProjectileMovement() { return ProjectileMovementComponent; }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	class USphereComponent* GetSphereComponent() { return SphereComponent; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<class UStaticMeshComponent> ProjectileMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<class UNiagaraComponent> ProjectileParticle;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = ProjectileMovement, meta = (AllowPrivateAccess = "true"))
	class UProjectileMovementComponent* ProjectileMovementComponent;

	UPROPERTY(VisibleDefaultsOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	class USphereComponent* SphereComponent;
};
