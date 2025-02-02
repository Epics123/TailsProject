// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponBase.h"

#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"


// Sets default values
AWeaponBase::AWeaponBase()
{
 	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	WeaponMesh->SetupAttachment(RootComponent);

	ProjectileLaunchPoint = CreateDefaultSubobject<USceneComponent>(TEXT("PorjectileLaunchPoint"));
	ProjectileLaunchPoint->SetupAttachment(RootComponent);
}

AWeaponBase::~AWeaponBase()
{
	
}

// Called when the game starts or when spawned
void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AWeaponBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	GetWorld()->GetTimerManager().ClearTimer(WeaponFireHandle);
}

// Called every frame
void AWeaponBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWeaponBase::ResetWeaponFire()
{
	SetCanWeaponFire(true);
}

