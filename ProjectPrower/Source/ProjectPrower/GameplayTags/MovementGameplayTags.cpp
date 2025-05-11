// Fill out your copyright notice in the Description page of Project Settings.


#include "MovementGameplayTags.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(TAG_Movement_Flying, "MovementState.Flying", "Movement state indicating that we are flying")
UE_DEFINE_GAMEPLAY_TAG_COMMENT(TAG_Movement_BlockFlight, "MovementState.FlightBlocked", "Flight is blocked when this tag is applied")
UE_DEFINE_GAMEPLAY_TAG_COMMENT(TAG_Movement_Locked, "MovementState.Locked", "Movement is locked and controller input will have no effect on movement")
