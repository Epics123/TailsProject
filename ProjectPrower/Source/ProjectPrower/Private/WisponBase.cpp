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

static TAutoConsoleVariable<int32> CVarDebugWeaponTraces(
	TEXT("Weapon.DebugWeaponTraces"),
	0,
	TEXT("Set to 1 to show weapon debug traces, 0 otherwise"));

AWisponBase::AWisponBase()
{
	
}

void AWisponBase::FireWeapon(bool bIsAltFire)
{
	if(bCanFireWeapon)
	{
		switch (CurrentWisponType)
		{
		case EWisponType::LASER:
			FireLaser(bIsAltFire);
			break;
		case EWisponType::BURST:
			break;
		case EWisponType::SPIKE:
			break;
		case EWisponType::CUBE:
			break;
		case EWisponType::VOID:
			break;
		case EWisponType::HOVER:
			break;
		default:
			break;
		}

		PostFireWeapon();
	}
	
}

void AWisponBase::PostFireWeapon()
{
	const UWeaponData* Data = GetCurrentWeaponData();
	if(Data)
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

void AWisponBase::FireLaser(const bool bIsAltFire)
{
	if (OwningCharacter)
	{
		const TObjectPtr<UWeaponData> WeaponData = GetCurrentWeaponData();
		if(!bIsAltFire)
		{
			FVector Start, End;
			FHitResult OutHit;

			FCollisionQueryParams ObjectParams;
			ObjectParams.AddIgnoredActor(this);
			ObjectParams.AddIgnoredActor(OwningCharacter);

			FCollisionObjectQueryParams QueryParams;
			QueryParams.AddObjectTypesToQuery(ECollisionChannel::ECC_WorldDynamic);
			QueryParams.AddObjectTypesToQuery(ECollisionChannel::ECC_WorldStatic);
			QueryParams.AddObjectTypesToQuery(ECollisionChannel::ECC_Pawn);

			const float WeaponRange = WeaponData->MaxProjectileDistance;

			Start = WeaponMesh->GetSocketLocation("Barrel");

			if (OwningCharacter->IsAiming())
			{
				FHitResult CameraHitResult;

				const FVector CameraTraceStart = OwningCharacter->GetFollowCamera()->GetComponentLocation();
				const FVector CameraTraceEnd = CameraTraceStart + (OwningCharacter->GetFollowCamera()->GetForwardVector() * (WeaponRange + OwningCharacter->GetCameraBoom()->TargetArmLength));
				GetWorld()->LineTraceSingleByObjectType(CameraHitResult, CameraTraceStart, CameraTraceEnd, QueryParams, ObjectParams);

				if (CameraHitResult.GetActor())
				{
					End = CameraHitResult.ImpactPoint;
				}
				else
				{
					End = OwningCharacter->GetFollowCamera()->GetComponentLocation() + (OwningCharacter->GetFollowCamera()->GetForwardVector() * (WeaponRange + OwningCharacter->GetCameraBoom()->TargetArmLength));
				}
			}
			else
			{
				End = Start + (OwningCharacter->GetActorForwardVector() * WeaponRange);
			}

			if (WeaponData->ProjecileSystem)
			{
				UNiagaraComponent* ProjectileSystem = UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), WeaponData->ProjecileSystem, Start);

				ProjectileSystem->SetVariableVec3("beamEnd", End);
			}

			GetWorld()->LineTraceSingleByObjectType(OutHit, Start, End, QueryParams, ObjectParams);

			if (CVarDebugWeaponTraces.GetValueOnGameThread() > 0)
			{
				DrawDebugSphere(GetWorld(), End, 10.0f, 20, FColor::Green, false, 2.0f);
				DrawDebugLine(GetWorld(), Start, End, FColor::Blue, false, 1.0f, 0, 1.0f);
			}
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Cyan, TEXT("Laser Alt Fire"));
		}
		
	}
}
