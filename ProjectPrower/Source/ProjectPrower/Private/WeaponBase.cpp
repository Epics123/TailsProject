// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponBase.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AWeaponBase::AWeaponBase()
{
 	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	WeaponMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeaponBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

