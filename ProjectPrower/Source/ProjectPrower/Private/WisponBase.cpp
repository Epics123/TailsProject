// Fill out your copyright notice in the Description page of Project Settings.


#include "WisponBase.h"
#include "ProjectileBase.h"
#include "../ProjectProwerCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"

AWisponBase::AWisponBase()
{
	
}

void AWisponBase::FireWeapon(bool bIsAltFire)
{
	Super::FireWeapon(bIsAltFire);

	if(bCanFireWeapon)
	{
		OnWisponFired(CurrentWisponType, bIsAltFire);

		PostFireWeapon();
	}
	
}

void AWisponBase::PostFireWeapon()
{
	const UWeaponData* Data = GetCurrentWeaponData();
	if(Data && bCanFireWeapon)
	{
		bCanFireWeapon = false;
		const float TimeUntilNextShot = Data->MaxTimeBetweenShots;

		if(TimeUntilNextShot > 0.0f)
		{
			GetWorld()->GetTimerManager().SetTimer(WeaponFireHandle, this, &AWisponBase::ResetWeaponFire, TimeUntilNextShot, false);
		}
		else
		{
			bCanFireWeapon = true;
		}
	}

}
