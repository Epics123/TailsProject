// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ProjectProwerCharacter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AWeaponBase;
class UCameraManagerComponent;
class UProwerMovementComponent;
#ifdef PROJECTPROWER_ProjectProwerCharacter_generated_h
#error "ProjectProwerCharacter.generated.h already included, missing '#pragma once' in ProjectProwerCharacter.h"
#endif
#define PROJECTPROWER_ProjectProwerCharacter_generated_h

#define FID_Users_eheil_Documents_Unreal_Projects_TailsProject_ProjectPrower_Source_ProjectPrower_ProjectProwerCharacter_h_30_SPARSE_DATA
#define FID_Users_eheil_Documents_Unreal_Projects_TailsProject_ProjectPrower_Source_ProjectPrower_ProjectProwerCharacter_h_30_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_eheil_Documents_Unreal_Projects_TailsProject_ProjectPrower_Source_ProjectPrower_ProjectProwerCharacter_h_30_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_eheil_Documents_Unreal_Projects_TailsProject_ProjectPrower_Source_ProjectPrower_ProjectProwerCharacter_h_30_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execResetFlightState); \
	DECLARE_FUNCTION(execIsAiming); \
	DECLARE_FUNCTION(execUnequipWeapon); \
	DECLARE_FUNCTION(execEquipWeapon); \
	DECLARE_FUNCTION(execToggleWeapon); \
	DECLARE_FUNCTION(execToggleWeaponVisibility); \
	DECLARE_FUNCTION(execSetWeapon); \
	DECLARE_FUNCTION(execGetCurrentWeapon); \
	DECLARE_FUNCTION(execIsInMovementState); \
	DECLARE_FUNCTION(execSetMovementState); \
	DECLARE_FUNCTION(execGetDefaultMovementState); \
	DECLARE_FUNCTION(execGetCurrentMovementState); \
	DECLARE_FUNCTION(execGetCameraManager); \
	DECLARE_FUNCTION(execGetProwerMovementComponent);


#define FID_Users_eheil_Documents_Unreal_Projects_TailsProject_ProjectPrower_Source_ProjectPrower_ProjectProwerCharacter_h_30_ACCESSORS
#define FID_Users_eheil_Documents_Unreal_Projects_TailsProject_ProjectPrower_Source_ProjectPrower_ProjectProwerCharacter_h_30_CALLBACK_WRAPPERS
#define FID_Users_eheil_Documents_Unreal_Projects_TailsProject_ProjectPrower_Source_ProjectPrower_ProjectProwerCharacter_h_30_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAProjectProwerCharacter(); \
	friend struct Z_Construct_UClass_AProjectProwerCharacter_Statics; \
public: \
	DECLARE_CLASS(AProjectProwerCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectPrower"), NO_API) \
	DECLARE_SERIALIZER(AProjectProwerCharacter)


#define FID_Users_eheil_Documents_Unreal_Projects_TailsProject_ProjectPrower_Source_ProjectPrower_ProjectProwerCharacter_h_30_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AProjectProwerCharacter(AProjectProwerCharacter&&); \
	NO_API AProjectProwerCharacter(const AProjectProwerCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProjectProwerCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProjectProwerCharacter); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AProjectProwerCharacter) \
	NO_API virtual ~AProjectProwerCharacter();


#define FID_Users_eheil_Documents_Unreal_Projects_TailsProject_ProjectPrower_Source_ProjectPrower_ProjectProwerCharacter_h_27_PROLOG
#define FID_Users_eheil_Documents_Unreal_Projects_TailsProject_ProjectPrower_Source_ProjectPrower_ProjectProwerCharacter_h_30_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_eheil_Documents_Unreal_Projects_TailsProject_ProjectPrower_Source_ProjectPrower_ProjectProwerCharacter_h_30_SPARSE_DATA \
	FID_Users_eheil_Documents_Unreal_Projects_TailsProject_ProjectPrower_Source_ProjectPrower_ProjectProwerCharacter_h_30_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_eheil_Documents_Unreal_Projects_TailsProject_ProjectPrower_Source_ProjectPrower_ProjectProwerCharacter_h_30_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_eheil_Documents_Unreal_Projects_TailsProject_ProjectPrower_Source_ProjectPrower_ProjectProwerCharacter_h_30_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_eheil_Documents_Unreal_Projects_TailsProject_ProjectPrower_Source_ProjectPrower_ProjectProwerCharacter_h_30_ACCESSORS \
	FID_Users_eheil_Documents_Unreal_Projects_TailsProject_ProjectPrower_Source_ProjectPrower_ProjectProwerCharacter_h_30_CALLBACK_WRAPPERS \
	FID_Users_eheil_Documents_Unreal_Projects_TailsProject_ProjectPrower_Source_ProjectPrower_ProjectProwerCharacter_h_30_INCLASS_NO_PURE_DECLS \
	FID_Users_eheil_Documents_Unreal_Projects_TailsProject_ProjectPrower_Source_ProjectPrower_ProjectProwerCharacter_h_30_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECTPROWER_API UClass* StaticClass<class AProjectProwerCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_eheil_Documents_Unreal_Projects_TailsProject_ProjectPrower_Source_ProjectPrower_ProjectProwerCharacter_h


#define FOREACH_ENUM_EMOVEMENTSTATE(op) \
	op(EMovementState::FREE) \
	op(EMovementState::WEAPON) \
	op(EMovementState::LOCKED) 

enum class EMovementState;
template<> struct TIsUEnumClass<EMovementState> { enum { Value = true }; };
template<> PROJECTPROWER_API UEnum* StaticEnum<EMovementState>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
