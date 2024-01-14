// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectPrower/ProjectProwerCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeProjectProwerCharacter() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
	PROJECTPROWER_API UClass* Z_Construct_UClass_AProjectProwerCharacter();
	PROJECTPROWER_API UClass* Z_Construct_UClass_AProjectProwerCharacter_NoRegister();
	PROJECTPROWER_API UClass* Z_Construct_UClass_AWeaponBase_NoRegister();
	PROJECTPROWER_API UClass* Z_Construct_UClass_UCameraManagerComponent_NoRegister();
	PROJECTPROWER_API UClass* Z_Construct_UClass_UProwerMovementComponent_NoRegister();
	PROJECTPROWER_API UEnum* Z_Construct_UEnum_ProjectPrower_EMovementState();
	UPackage* Z_Construct_UPackage__Script_ProjectPrower();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EMovementState;
	static UEnum* EMovementState_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EMovementState.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EMovementState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ProjectPrower_EMovementState, (UObject*)Z_Construct_UPackage__Script_ProjectPrower(), TEXT("EMovementState"));
		}
		return Z_Registration_Info_UEnum_EMovementState.OuterSingleton;
	}
	template<> PROJECTPROWER_API UEnum* StaticEnum<EMovementState>()
	{
		return EMovementState_StaticEnum();
	}
	struct Z_Construct_UEnum_ProjectPrower_EMovementState_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_ProjectPrower_EMovementState_Statics::Enumerators[] = {
		{ "EMovementState::FREE", (int64)EMovementState::FREE },
		{ "EMovementState::WEAPON", (int64)EMovementState::WEAPON },
		{ "EMovementState::LOCKED", (int64)EMovementState::LOCKED },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_ProjectPrower_EMovementState_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "FREE.DisplayName", "Free" },
		{ "FREE.Name", "EMovementState::FREE" },
		{ "LOCKED.DisplayName", "Locked" },
		{ "LOCKED.Name", "EMovementState::LOCKED" },
		{ "ModuleRelativePath", "ProjectProwerCharacter.h" },
		{ "WEAPON.DisplayName", "Weapon" },
		{ "WEAPON.Name", "EMovementState::WEAPON" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ProjectPrower_EMovementState_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_ProjectPrower,
		nullptr,
		"EMovementState",
		"EMovementState",
		Z_Construct_UEnum_ProjectPrower_EMovementState_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_ProjectPrower_EMovementState_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ProjectPrower_EMovementState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ProjectPrower_EMovementState_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_ProjectPrower_EMovementState()
	{
		if (!Z_Registration_Info_UEnum_EMovementState.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EMovementState.InnerSingleton, Z_Construct_UEnum_ProjectPrower_EMovementState_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EMovementState.InnerSingleton;
	}
	DEFINE_FUNCTION(AProjectProwerCharacter::execResetFlightState)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ResetFlightState();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AProjectProwerCharacter::execIsAiming)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsAiming();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AProjectProwerCharacter::execUnequipWeapon)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UnequipWeapon();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AProjectProwerCharacter::execEquipWeapon)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->EquipWeapon();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AProjectProwerCharacter::execToggleWeapon)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ToggleWeapon();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AProjectProwerCharacter::execToggleWeaponVisibility)
	{
		P_GET_UBOOL(Z_Param_bIsVisible);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ToggleWeaponVisibility(Z_Param_bIsVisible);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AProjectProwerCharacter::execSetWeapon)
	{
		P_GET_OBJECT(AWeaponBase,Z_Param_Weapon);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetWeapon(Z_Param_Weapon);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AProjectProwerCharacter::execGetCurrentWeapon)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(AWeaponBase**)Z_Param__Result=P_THIS->GetCurrentWeapon();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AProjectProwerCharacter::execIsInMovementState)
	{
		P_GET_ENUM(EMovementState,Z_Param_StateToCheck);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsInMovementState(EMovementState(Z_Param_StateToCheck));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AProjectProwerCharacter::execSetMovementState)
	{
		P_GET_ENUM(EMovementState,Z_Param_NewState);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetMovementState(EMovementState(Z_Param_NewState));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AProjectProwerCharacter::execGetDefaultMovementState)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(EMovementState*)Z_Param__Result=P_THIS->GetDefaultMovementState();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AProjectProwerCharacter::execGetCurrentMovementState)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(EMovementState*)Z_Param__Result=P_THIS->GetCurrentMovementState();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AProjectProwerCharacter::execGetCameraManager)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UCameraManagerComponent**)Z_Param__Result=P_THIS->GetCameraManager();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AProjectProwerCharacter::execGetProwerMovementComponent)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UProwerMovementComponent**)Z_Param__Result=P_THIS->GetProwerMovementComponent();
		P_NATIVE_END;
	}
	struct ProjectProwerCharacter_eventToggleJumpballMesh_Parms
	{
		bool bShowJumpball;
	};
	static FName NAME_AProjectProwerCharacter_ToggleJumpballMesh = FName(TEXT("ToggleJumpballMesh"));
	void AProjectProwerCharacter::ToggleJumpballMesh(bool bShowJumpball)
	{
		ProjectProwerCharacter_eventToggleJumpballMesh_Parms Parms;
		Parms.bShowJumpball=bShowJumpball ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_AProjectProwerCharacter_ToggleJumpballMesh),&Parms);
	}
	void AProjectProwerCharacter::StaticRegisterNativesAProjectProwerCharacter()
	{
		UClass* Class = AProjectProwerCharacter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "EquipWeapon", &AProjectProwerCharacter::execEquipWeapon },
			{ "GetCameraManager", &AProjectProwerCharacter::execGetCameraManager },
			{ "GetCurrentMovementState", &AProjectProwerCharacter::execGetCurrentMovementState },
			{ "GetCurrentWeapon", &AProjectProwerCharacter::execGetCurrentWeapon },
			{ "GetDefaultMovementState", &AProjectProwerCharacter::execGetDefaultMovementState },
			{ "GetProwerMovementComponent", &AProjectProwerCharacter::execGetProwerMovementComponent },
			{ "IsAiming", &AProjectProwerCharacter::execIsAiming },
			{ "IsInMovementState", &AProjectProwerCharacter::execIsInMovementState },
			{ "ResetFlightState", &AProjectProwerCharacter::execResetFlightState },
			{ "SetMovementState", &AProjectProwerCharacter::execSetMovementState },
			{ "SetWeapon", &AProjectProwerCharacter::execSetWeapon },
			{ "ToggleWeapon", &AProjectProwerCharacter::execToggleWeapon },
			{ "ToggleWeaponVisibility", &AProjectProwerCharacter::execToggleWeaponVisibility },
			{ "UnequipWeapon", &AProjectProwerCharacter::execUnequipWeapon },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AProjectProwerCharacter_EquipWeapon_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProjectProwerCharacter_EquipWeapon_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ProjectProwerCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AProjectProwerCharacter_EquipWeapon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProjectProwerCharacter, nullptr, "EquipWeapon", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProjectProwerCharacter_EquipWeapon_Statics::Function_MetaDataParams), Z_Construct_UFunction_AProjectProwerCharacter_EquipWeapon_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_AProjectProwerCharacter_EquipWeapon()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AProjectProwerCharacter_EquipWeapon_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AProjectProwerCharacter_GetCameraManager_Statics
	{
		struct ProjectProwerCharacter_eventGetCameraManager_Parms
		{
			UCameraManagerComponent* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProjectProwerCharacter_GetCameraManager_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AProjectProwerCharacter_GetCameraManager_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ProjectProwerCharacter_eventGetCameraManager_Parms, ReturnValue), Z_Construct_UClass_UCameraManagerComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProjectProwerCharacter_GetCameraManager_Statics::NewProp_ReturnValue_MetaData), Z_Construct_UFunction_AProjectProwerCharacter_GetCameraManager_Statics::NewProp_ReturnValue_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProjectProwerCharacter_GetCameraManager_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProjectProwerCharacter_GetCameraManager_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProjectProwerCharacter_GetCameraManager_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ProjectProwerCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AProjectProwerCharacter_GetCameraManager_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProjectProwerCharacter, nullptr, "GetCameraManager", nullptr, nullptr, Z_Construct_UFunction_AProjectProwerCharacter_GetCameraManager_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AProjectProwerCharacter_GetCameraManager_Statics::PropPointers), sizeof(Z_Construct_UFunction_AProjectProwerCharacter_GetCameraManager_Statics::ProjectProwerCharacter_eventGetCameraManager_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProjectProwerCharacter_GetCameraManager_Statics::Function_MetaDataParams), Z_Construct_UFunction_AProjectProwerCharacter_GetCameraManager_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AProjectProwerCharacter_GetCameraManager_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AProjectProwerCharacter_GetCameraManager_Statics::ProjectProwerCharacter_eventGetCameraManager_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AProjectProwerCharacter_GetCameraManager()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AProjectProwerCharacter_GetCameraManager_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AProjectProwerCharacter_GetCurrentMovementState_Statics
	{
		struct ProjectProwerCharacter_eventGetCurrentMovementState_Parms
		{
			EMovementState ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_AProjectProwerCharacter_GetCurrentMovementState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ProjectProwerCharacter_eventGetCurrentMovementState_Parms, ReturnValue), Z_Construct_UEnum_ProjectPrower_EMovementState, METADATA_PARAMS(0, nullptr) }; // 1126189747
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProjectProwerCharacter_GetCurrentMovementState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProjectProwerCharacter_GetCurrentMovementState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProjectProwerCharacter_GetCurrentMovementState_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ProjectProwerCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AProjectProwerCharacter_GetCurrentMovementState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProjectProwerCharacter, nullptr, "GetCurrentMovementState", nullptr, nullptr, Z_Construct_UFunction_AProjectProwerCharacter_GetCurrentMovementState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AProjectProwerCharacter_GetCurrentMovementState_Statics::PropPointers), sizeof(Z_Construct_UFunction_AProjectProwerCharacter_GetCurrentMovementState_Statics::ProjectProwerCharacter_eventGetCurrentMovementState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProjectProwerCharacter_GetCurrentMovementState_Statics::Function_MetaDataParams), Z_Construct_UFunction_AProjectProwerCharacter_GetCurrentMovementState_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AProjectProwerCharacter_GetCurrentMovementState_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AProjectProwerCharacter_GetCurrentMovementState_Statics::ProjectProwerCharacter_eventGetCurrentMovementState_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AProjectProwerCharacter_GetCurrentMovementState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AProjectProwerCharacter_GetCurrentMovementState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AProjectProwerCharacter_GetCurrentWeapon_Statics
	{
		struct ProjectProwerCharacter_eventGetCurrentWeapon_Parms
		{
			AWeaponBase* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AProjectProwerCharacter_GetCurrentWeapon_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ProjectProwerCharacter_eventGetCurrentWeapon_Parms, ReturnValue), Z_Construct_UClass_AWeaponBase_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProjectProwerCharacter_GetCurrentWeapon_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProjectProwerCharacter_GetCurrentWeapon_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProjectProwerCharacter_GetCurrentWeapon_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ProjectProwerCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AProjectProwerCharacter_GetCurrentWeapon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProjectProwerCharacter, nullptr, "GetCurrentWeapon", nullptr, nullptr, Z_Construct_UFunction_AProjectProwerCharacter_GetCurrentWeapon_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AProjectProwerCharacter_GetCurrentWeapon_Statics::PropPointers), sizeof(Z_Construct_UFunction_AProjectProwerCharacter_GetCurrentWeapon_Statics::ProjectProwerCharacter_eventGetCurrentWeapon_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProjectProwerCharacter_GetCurrentWeapon_Statics::Function_MetaDataParams), Z_Construct_UFunction_AProjectProwerCharacter_GetCurrentWeapon_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AProjectProwerCharacter_GetCurrentWeapon_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AProjectProwerCharacter_GetCurrentWeapon_Statics::ProjectProwerCharacter_eventGetCurrentWeapon_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AProjectProwerCharacter_GetCurrentWeapon()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AProjectProwerCharacter_GetCurrentWeapon_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AProjectProwerCharacter_GetDefaultMovementState_Statics
	{
		struct ProjectProwerCharacter_eventGetDefaultMovementState_Parms
		{
			EMovementState ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_AProjectProwerCharacter_GetDefaultMovementState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ProjectProwerCharacter_eventGetDefaultMovementState_Parms, ReturnValue), Z_Construct_UEnum_ProjectPrower_EMovementState, METADATA_PARAMS(0, nullptr) }; // 1126189747
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProjectProwerCharacter_GetDefaultMovementState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProjectProwerCharacter_GetDefaultMovementState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProjectProwerCharacter_GetDefaultMovementState_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ProjectProwerCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AProjectProwerCharacter_GetDefaultMovementState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProjectProwerCharacter, nullptr, "GetDefaultMovementState", nullptr, nullptr, Z_Construct_UFunction_AProjectProwerCharacter_GetDefaultMovementState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AProjectProwerCharacter_GetDefaultMovementState_Statics::PropPointers), sizeof(Z_Construct_UFunction_AProjectProwerCharacter_GetDefaultMovementState_Statics::ProjectProwerCharacter_eventGetDefaultMovementState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProjectProwerCharacter_GetDefaultMovementState_Statics::Function_MetaDataParams), Z_Construct_UFunction_AProjectProwerCharacter_GetDefaultMovementState_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AProjectProwerCharacter_GetDefaultMovementState_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AProjectProwerCharacter_GetDefaultMovementState_Statics::ProjectProwerCharacter_eventGetDefaultMovementState_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AProjectProwerCharacter_GetDefaultMovementState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AProjectProwerCharacter_GetDefaultMovementState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AProjectProwerCharacter_GetProwerMovementComponent_Statics
	{
		struct ProjectProwerCharacter_eventGetProwerMovementComponent_Parms
		{
			UProwerMovementComponent* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProjectProwerCharacter_GetProwerMovementComponent_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AProjectProwerCharacter_GetProwerMovementComponent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ProjectProwerCharacter_eventGetProwerMovementComponent_Parms, ReturnValue), Z_Construct_UClass_UProwerMovementComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProjectProwerCharacter_GetProwerMovementComponent_Statics::NewProp_ReturnValue_MetaData), Z_Construct_UFunction_AProjectProwerCharacter_GetProwerMovementComponent_Statics::NewProp_ReturnValue_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProjectProwerCharacter_GetProwerMovementComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProjectProwerCharacter_GetProwerMovementComponent_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProjectProwerCharacter_GetProwerMovementComponent_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ProjectProwerCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AProjectProwerCharacter_GetProwerMovementComponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProjectProwerCharacter, nullptr, "GetProwerMovementComponent", nullptr, nullptr, Z_Construct_UFunction_AProjectProwerCharacter_GetProwerMovementComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AProjectProwerCharacter_GetProwerMovementComponent_Statics::PropPointers), sizeof(Z_Construct_UFunction_AProjectProwerCharacter_GetProwerMovementComponent_Statics::ProjectProwerCharacter_eventGetProwerMovementComponent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProjectProwerCharacter_GetProwerMovementComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_AProjectProwerCharacter_GetProwerMovementComponent_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AProjectProwerCharacter_GetProwerMovementComponent_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AProjectProwerCharacter_GetProwerMovementComponent_Statics::ProjectProwerCharacter_eventGetProwerMovementComponent_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AProjectProwerCharacter_GetProwerMovementComponent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AProjectProwerCharacter_GetProwerMovementComponent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AProjectProwerCharacter_IsAiming_Statics
	{
		struct ProjectProwerCharacter_eventIsAiming_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AProjectProwerCharacter_IsAiming_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((ProjectProwerCharacter_eventIsAiming_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AProjectProwerCharacter_IsAiming_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ProjectProwerCharacter_eventIsAiming_Parms), &Z_Construct_UFunction_AProjectProwerCharacter_IsAiming_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProjectProwerCharacter_IsAiming_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProjectProwerCharacter_IsAiming_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProjectProwerCharacter_IsAiming_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ProjectProwerCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AProjectProwerCharacter_IsAiming_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProjectProwerCharacter, nullptr, "IsAiming", nullptr, nullptr, Z_Construct_UFunction_AProjectProwerCharacter_IsAiming_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AProjectProwerCharacter_IsAiming_Statics::PropPointers), sizeof(Z_Construct_UFunction_AProjectProwerCharacter_IsAiming_Statics::ProjectProwerCharacter_eventIsAiming_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProjectProwerCharacter_IsAiming_Statics::Function_MetaDataParams), Z_Construct_UFunction_AProjectProwerCharacter_IsAiming_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AProjectProwerCharacter_IsAiming_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AProjectProwerCharacter_IsAiming_Statics::ProjectProwerCharacter_eventIsAiming_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AProjectProwerCharacter_IsAiming()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AProjectProwerCharacter_IsAiming_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AProjectProwerCharacter_IsInMovementState_Statics
	{
		struct ProjectProwerCharacter_eventIsInMovementState_Parms
		{
			EMovementState StateToCheck;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_StateToCheck;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_AProjectProwerCharacter_IsInMovementState_Statics::NewProp_StateToCheck = { "StateToCheck", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ProjectProwerCharacter_eventIsInMovementState_Parms, StateToCheck), Z_Construct_UEnum_ProjectPrower_EMovementState, METADATA_PARAMS(0, nullptr) }; // 1126189747
	void Z_Construct_UFunction_AProjectProwerCharacter_IsInMovementState_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((ProjectProwerCharacter_eventIsInMovementState_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AProjectProwerCharacter_IsInMovementState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ProjectProwerCharacter_eventIsInMovementState_Parms), &Z_Construct_UFunction_AProjectProwerCharacter_IsInMovementState_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProjectProwerCharacter_IsInMovementState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProjectProwerCharacter_IsInMovementState_Statics::NewProp_StateToCheck,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProjectProwerCharacter_IsInMovementState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProjectProwerCharacter_IsInMovementState_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Returns true if StateToCheck matches the current movement state*/" },
#endif
		{ "ModuleRelativePath", "ProjectProwerCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns true if StateToCheck matches the current movement state" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AProjectProwerCharacter_IsInMovementState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProjectProwerCharacter, nullptr, "IsInMovementState", nullptr, nullptr, Z_Construct_UFunction_AProjectProwerCharacter_IsInMovementState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AProjectProwerCharacter_IsInMovementState_Statics::PropPointers), sizeof(Z_Construct_UFunction_AProjectProwerCharacter_IsInMovementState_Statics::ProjectProwerCharacter_eventIsInMovementState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProjectProwerCharacter_IsInMovementState_Statics::Function_MetaDataParams), Z_Construct_UFunction_AProjectProwerCharacter_IsInMovementState_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AProjectProwerCharacter_IsInMovementState_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AProjectProwerCharacter_IsInMovementState_Statics::ProjectProwerCharacter_eventIsInMovementState_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AProjectProwerCharacter_IsInMovementState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AProjectProwerCharacter_IsInMovementState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AProjectProwerCharacter_ResetFlightState_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProjectProwerCharacter_ResetFlightState_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ProjectProwerCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AProjectProwerCharacter_ResetFlightState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProjectProwerCharacter, nullptr, "ResetFlightState", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProjectProwerCharacter_ResetFlightState_Statics::Function_MetaDataParams), Z_Construct_UFunction_AProjectProwerCharacter_ResetFlightState_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_AProjectProwerCharacter_ResetFlightState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AProjectProwerCharacter_ResetFlightState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AProjectProwerCharacter_SetMovementState_Statics
	{
		struct ProjectProwerCharacter_eventSetMovementState_Parms
		{
			EMovementState NewState;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_NewState;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_AProjectProwerCharacter_SetMovementState_Statics::NewProp_NewState = { "NewState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ProjectProwerCharacter_eventSetMovementState_Parms, NewState), Z_Construct_UEnum_ProjectPrower_EMovementState, METADATA_PARAMS(0, nullptr) }; // 1126189747
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProjectProwerCharacter_SetMovementState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProjectProwerCharacter_SetMovementState_Statics::NewProp_NewState,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProjectProwerCharacter_SetMovementState_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ProjectProwerCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AProjectProwerCharacter_SetMovementState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProjectProwerCharacter, nullptr, "SetMovementState", nullptr, nullptr, Z_Construct_UFunction_AProjectProwerCharacter_SetMovementState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AProjectProwerCharacter_SetMovementState_Statics::PropPointers), sizeof(Z_Construct_UFunction_AProjectProwerCharacter_SetMovementState_Statics::ProjectProwerCharacter_eventSetMovementState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProjectProwerCharacter_SetMovementState_Statics::Function_MetaDataParams), Z_Construct_UFunction_AProjectProwerCharacter_SetMovementState_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AProjectProwerCharacter_SetMovementState_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AProjectProwerCharacter_SetMovementState_Statics::ProjectProwerCharacter_eventSetMovementState_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AProjectProwerCharacter_SetMovementState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AProjectProwerCharacter_SetMovementState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AProjectProwerCharacter_SetWeapon_Statics
	{
		struct ProjectProwerCharacter_eventSetWeapon_Parms
		{
			AWeaponBase* Weapon;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Weapon;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AProjectProwerCharacter_SetWeapon_Statics::NewProp_Weapon = { "Weapon", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ProjectProwerCharacter_eventSetWeapon_Parms, Weapon), Z_Construct_UClass_AWeaponBase_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProjectProwerCharacter_SetWeapon_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProjectProwerCharacter_SetWeapon_Statics::NewProp_Weapon,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProjectProwerCharacter_SetWeapon_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ProjectProwerCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AProjectProwerCharacter_SetWeapon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProjectProwerCharacter, nullptr, "SetWeapon", nullptr, nullptr, Z_Construct_UFunction_AProjectProwerCharacter_SetWeapon_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AProjectProwerCharacter_SetWeapon_Statics::PropPointers), sizeof(Z_Construct_UFunction_AProjectProwerCharacter_SetWeapon_Statics::ProjectProwerCharacter_eventSetWeapon_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProjectProwerCharacter_SetWeapon_Statics::Function_MetaDataParams), Z_Construct_UFunction_AProjectProwerCharacter_SetWeapon_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AProjectProwerCharacter_SetWeapon_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AProjectProwerCharacter_SetWeapon_Statics::ProjectProwerCharacter_eventSetWeapon_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AProjectProwerCharacter_SetWeapon()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AProjectProwerCharacter_SetWeapon_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AProjectProwerCharacter_ToggleJumpballMesh_Statics
	{
		static void NewProp_bShowJumpball_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowJumpball;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AProjectProwerCharacter_ToggleJumpballMesh_Statics::NewProp_bShowJumpball_SetBit(void* Obj)
	{
		((ProjectProwerCharacter_eventToggleJumpballMesh_Parms*)Obj)->bShowJumpball = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AProjectProwerCharacter_ToggleJumpballMesh_Statics::NewProp_bShowJumpball = { "bShowJumpball", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ProjectProwerCharacter_eventToggleJumpballMesh_Parms), &Z_Construct_UFunction_AProjectProwerCharacter_ToggleJumpballMesh_Statics::NewProp_bShowJumpball_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProjectProwerCharacter_ToggleJumpballMesh_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProjectProwerCharacter_ToggleJumpballMesh_Statics::NewProp_bShowJumpball,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProjectProwerCharacter_ToggleJumpballMesh_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ProjectProwerCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AProjectProwerCharacter_ToggleJumpballMesh_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProjectProwerCharacter, nullptr, "ToggleJumpballMesh", nullptr, nullptr, Z_Construct_UFunction_AProjectProwerCharacter_ToggleJumpballMesh_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AProjectProwerCharacter_ToggleJumpballMesh_Statics::PropPointers), sizeof(ProjectProwerCharacter_eventToggleJumpballMesh_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProjectProwerCharacter_ToggleJumpballMesh_Statics::Function_MetaDataParams), Z_Construct_UFunction_AProjectProwerCharacter_ToggleJumpballMesh_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AProjectProwerCharacter_ToggleJumpballMesh_Statics::PropPointers) < 2048);
	static_assert(sizeof(ProjectProwerCharacter_eventToggleJumpballMesh_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AProjectProwerCharacter_ToggleJumpballMesh()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AProjectProwerCharacter_ToggleJumpballMesh_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AProjectProwerCharacter_ToggleWeapon_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProjectProwerCharacter_ToggleWeapon_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ProjectProwerCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AProjectProwerCharacter_ToggleWeapon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProjectProwerCharacter, nullptr, "ToggleWeapon", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProjectProwerCharacter_ToggleWeapon_Statics::Function_MetaDataParams), Z_Construct_UFunction_AProjectProwerCharacter_ToggleWeapon_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_AProjectProwerCharacter_ToggleWeapon()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AProjectProwerCharacter_ToggleWeapon_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AProjectProwerCharacter_ToggleWeaponVisibility_Statics
	{
		struct ProjectProwerCharacter_eventToggleWeaponVisibility_Parms
		{
			bool bIsVisible;
		};
		static void NewProp_bIsVisible_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsVisible;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AProjectProwerCharacter_ToggleWeaponVisibility_Statics::NewProp_bIsVisible_SetBit(void* Obj)
	{
		((ProjectProwerCharacter_eventToggleWeaponVisibility_Parms*)Obj)->bIsVisible = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AProjectProwerCharacter_ToggleWeaponVisibility_Statics::NewProp_bIsVisible = { "bIsVisible", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ProjectProwerCharacter_eventToggleWeaponVisibility_Parms), &Z_Construct_UFunction_AProjectProwerCharacter_ToggleWeaponVisibility_Statics::NewProp_bIsVisible_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProjectProwerCharacter_ToggleWeaponVisibility_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProjectProwerCharacter_ToggleWeaponVisibility_Statics::NewProp_bIsVisible,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProjectProwerCharacter_ToggleWeaponVisibility_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ProjectProwerCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AProjectProwerCharacter_ToggleWeaponVisibility_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProjectProwerCharacter, nullptr, "ToggleWeaponVisibility", nullptr, nullptr, Z_Construct_UFunction_AProjectProwerCharacter_ToggleWeaponVisibility_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AProjectProwerCharacter_ToggleWeaponVisibility_Statics::PropPointers), sizeof(Z_Construct_UFunction_AProjectProwerCharacter_ToggleWeaponVisibility_Statics::ProjectProwerCharacter_eventToggleWeaponVisibility_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProjectProwerCharacter_ToggleWeaponVisibility_Statics::Function_MetaDataParams), Z_Construct_UFunction_AProjectProwerCharacter_ToggleWeaponVisibility_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AProjectProwerCharacter_ToggleWeaponVisibility_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AProjectProwerCharacter_ToggleWeaponVisibility_Statics::ProjectProwerCharacter_eventToggleWeaponVisibility_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AProjectProwerCharacter_ToggleWeaponVisibility()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AProjectProwerCharacter_ToggleWeaponVisibility_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AProjectProwerCharacter_UnequipWeapon_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProjectProwerCharacter_UnequipWeapon_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ProjectProwerCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AProjectProwerCharacter_UnequipWeapon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProjectProwerCharacter, nullptr, "UnequipWeapon", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProjectProwerCharacter_UnequipWeapon_Statics::Function_MetaDataParams), Z_Construct_UFunction_AProjectProwerCharacter_UnequipWeapon_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_AProjectProwerCharacter_UnequipWeapon()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AProjectProwerCharacter_UnequipWeapon_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AProjectProwerCharacter);
	UClass* Z_Construct_UClass_AProjectProwerCharacter_NoRegister()
	{
		return AProjectProwerCharacter::StaticClass();
	}
	struct Z_Construct_UClass_AProjectProwerCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bUseCharacterVectors_MetaData[];
#endif
		static void NewProp_bUseCharacterVectors_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseCharacterVectors;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultRotationRate_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_DefaultRotationRate;
		static const UECodeGen_Private::FIntPropertyParams NewProp_DefaultMovementState_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultMovementState_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_DefaultMovementState;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsFlying_MetaData[];
#endif
		static void NewProp_bIsFlying_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsFlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_VerticalFlyDirection_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_VerticalFlyDirection;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bWeaponEquipped_MetaData[];
#endif
		static void NewProp_bWeaponEquipped_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bWeaponEquipped;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bCanEquipWeapon_MetaData[];
#endif
		static void NewProp_bCanEquipWeapon_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bCanEquipWeapon;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FollowCamera_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_FollowCamera;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CameraPivot_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraPivot;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultMappingContext_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DefaultMappingContext;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_JumpAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MoveAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MoveAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LookAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_LookAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WeaponEquipAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WeaponEquipAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WeaponAimAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WeaponAimAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WeaponAimEndAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WeaponAimEndAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FlyAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_FlyAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CameraManager_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraManager;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AProjectProwerCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_ProjectPrower,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AProjectProwerCharacter_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_AProjectProwerCharacter_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AProjectProwerCharacter_EquipWeapon, "EquipWeapon" }, // 1258606378
		{ &Z_Construct_UFunction_AProjectProwerCharacter_GetCameraManager, "GetCameraManager" }, // 653592809
		{ &Z_Construct_UFunction_AProjectProwerCharacter_GetCurrentMovementState, "GetCurrentMovementState" }, // 3190907930
		{ &Z_Construct_UFunction_AProjectProwerCharacter_GetCurrentWeapon, "GetCurrentWeapon" }, // 1203254288
		{ &Z_Construct_UFunction_AProjectProwerCharacter_GetDefaultMovementState, "GetDefaultMovementState" }, // 920827592
		{ &Z_Construct_UFunction_AProjectProwerCharacter_GetProwerMovementComponent, "GetProwerMovementComponent" }, // 440245385
		{ &Z_Construct_UFunction_AProjectProwerCharacter_IsAiming, "IsAiming" }, // 1767380142
		{ &Z_Construct_UFunction_AProjectProwerCharacter_IsInMovementState, "IsInMovementState" }, // 2910398411
		{ &Z_Construct_UFunction_AProjectProwerCharacter_ResetFlightState, "ResetFlightState" }, // 1885492335
		{ &Z_Construct_UFunction_AProjectProwerCharacter_SetMovementState, "SetMovementState" }, // 349371000
		{ &Z_Construct_UFunction_AProjectProwerCharacter_SetWeapon, "SetWeapon" }, // 3392083152
		{ &Z_Construct_UFunction_AProjectProwerCharacter_ToggleJumpballMesh, "ToggleJumpballMesh" }, // 2414625457
		{ &Z_Construct_UFunction_AProjectProwerCharacter_ToggleWeapon, "ToggleWeapon" }, // 2364228148
		{ &Z_Construct_UFunction_AProjectProwerCharacter_ToggleWeaponVisibility, "ToggleWeaponVisibility" }, // 3948385950
		{ &Z_Construct_UFunction_AProjectProwerCharacter_UnequipWeapon, "UnequipWeapon" }, // 1498262740
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AProjectProwerCharacter_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectProwerCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "ProjectProwerCharacter.h" },
		{ "ModuleRelativePath", "ProjectProwerCharacter.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_bUseCharacterVectors_MetaData[] = {
		{ "Category", "Movement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09* If true, the forward and right vectors of the character will be used for moving instead of the camera vectors.\n\x09*/" },
#endif
		{ "ModuleRelativePath", "ProjectProwerCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If true, the forward and right vectors of the character will be used for moving instead of the camera vectors." },
#endif
	};
#endif
	void Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_bUseCharacterVectors_SetBit(void* Obj)
	{
		((AProjectProwerCharacter*)Obj)->bUseCharacterVectors = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_bUseCharacterVectors = { "bUseCharacterVectors", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AProjectProwerCharacter), &Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_bUseCharacterVectors_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_bUseCharacterVectors_MetaData), Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_bUseCharacterVectors_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_DefaultRotationRate_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "ProjectProwerCharacter.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_DefaultRotationRate = { "DefaultRotationRate", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AProjectProwerCharacter, DefaultRotationRate), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_DefaultRotationRate_MetaData), Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_DefaultRotationRate_MetaData) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_DefaultMovementState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_DefaultMovementState_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "ProjectProwerCharacter.h" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_DefaultMovementState = { "DefaultMovementState", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AProjectProwerCharacter, DefaultMovementState), Z_Construct_UEnum_ProjectPrower_EMovementState, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_DefaultMovementState_MetaData), Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_DefaultMovementState_MetaData) }; // 1126189747
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_bIsFlying_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "ProjectProwerCharacter.h" },
	};
#endif
	void Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_bIsFlying_SetBit(void* Obj)
	{
		((AProjectProwerCharacter*)Obj)->bIsFlying = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_bIsFlying = { "bIsFlying", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AProjectProwerCharacter), &Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_bIsFlying_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_bIsFlying_MetaData), Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_bIsFlying_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_VerticalFlyDirection_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "ProjectProwerCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_VerticalFlyDirection = { "VerticalFlyDirection", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AProjectProwerCharacter, VerticalFlyDirection), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_VerticalFlyDirection_MetaData), Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_VerticalFlyDirection_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_bWeaponEquipped_MetaData[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "ProjectProwerCharacter.h" },
	};
#endif
	void Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_bWeaponEquipped_SetBit(void* Obj)
	{
		((AProjectProwerCharacter*)Obj)->bWeaponEquipped = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_bWeaponEquipped = { "bWeaponEquipped", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AProjectProwerCharacter), &Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_bWeaponEquipped_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_bWeaponEquipped_MetaData), Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_bWeaponEquipped_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_bCanEquipWeapon_MetaData[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "ProjectProwerCharacter.h" },
	};
#endif
	void Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_bCanEquipWeapon_SetBit(void* Obj)
	{
		((AProjectProwerCharacter*)Obj)->bCanEquipWeapon = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_bCanEquipWeapon = { "bCanEquipWeapon", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AProjectProwerCharacter), &Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_bCanEquipWeapon_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_bCanEquipWeapon_MetaData), Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_bCanEquipWeapon_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_CameraBoom_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Camera boom positioning the camera behind the character */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ProjectProwerCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Camera boom positioning the camera behind the character" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_CameraBoom = { "CameraBoom", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AProjectProwerCharacter, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_CameraBoom_MetaData), Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_CameraBoom_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_FollowCamera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Follow camera */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ProjectProwerCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Follow camera" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_FollowCamera = { "FollowCamera", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AProjectProwerCharacter, FollowCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_FollowCamera_MetaData), Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_FollowCamera_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_CameraPivot_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ProjectProwerCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_CameraPivot = { "CameraPivot", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AProjectProwerCharacter, CameraPivot), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_CameraPivot_MetaData), Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_CameraPivot_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_DefaultMappingContext_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** MappingContext */" },
#endif
		{ "ModuleRelativePath", "ProjectProwerCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "MappingContext" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_DefaultMappingContext = { "DefaultMappingContext", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AProjectProwerCharacter, DefaultMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_DefaultMappingContext_MetaData), Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_DefaultMappingContext_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_JumpAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Jump Input Action */" },
#endif
		{ "ModuleRelativePath", "ProjectProwerCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Jump Input Action" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_JumpAction = { "JumpAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AProjectProwerCharacter, JumpAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_JumpAction_MetaData), Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_JumpAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_MoveAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Move Input Action */" },
#endif
		{ "ModuleRelativePath", "ProjectProwerCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Move Input Action" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_MoveAction = { "MoveAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AProjectProwerCharacter, MoveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_MoveAction_MetaData), Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_MoveAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_LookAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Look Input Action */" },
#endif
		{ "ModuleRelativePath", "ProjectProwerCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Look Input Action" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_LookAction = { "LookAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AProjectProwerCharacter, LookAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_LookAction_MetaData), Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_LookAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_WeaponEquipAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Weapon Equip/Unequip Input Action */" },
#endif
		{ "ModuleRelativePath", "ProjectProwerCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Weapon Equip/Unequip Input Action" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_WeaponEquipAction = { "WeaponEquipAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AProjectProwerCharacter, WeaponEquipAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_WeaponEquipAction_MetaData), Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_WeaponEquipAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_WeaponAimAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Weapon Aim Input Action */" },
#endif
		{ "ModuleRelativePath", "ProjectProwerCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Weapon Aim Input Action" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_WeaponAimAction = { "WeaponAimAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AProjectProwerCharacter, WeaponAimAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_WeaponAimAction_MetaData), Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_WeaponAimAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_WeaponAimEndAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Weapon Aim End Input Action */" },
#endif
		{ "ModuleRelativePath", "ProjectProwerCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Weapon Aim End Input Action" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_WeaponAimEndAction = { "WeaponAimEndAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AProjectProwerCharacter, WeaponAimEndAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_WeaponAimEndAction_MetaData), Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_WeaponAimEndAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_FlyAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fly Input Action */" },
#endif
		{ "ModuleRelativePath", "ProjectProwerCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fly Input Action" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_FlyAction = { "FlyAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AProjectProwerCharacter, FlyAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_FlyAction_MetaData), Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_FlyAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_CameraManager_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// End Input //\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ProjectProwerCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "End Input" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_CameraManager = { "CameraManager", nullptr, (EPropertyFlags)0x004000000008001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AProjectProwerCharacter, CameraManager), Z_Construct_UClass_UCameraManagerComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_CameraManager_MetaData), Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_CameraManager_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AProjectProwerCharacter_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_bUseCharacterVectors,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_DefaultRotationRate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_DefaultMovementState_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_DefaultMovementState,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_bIsFlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_VerticalFlyDirection,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_bWeaponEquipped,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_bCanEquipWeapon,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_CameraBoom,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_FollowCamera,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_CameraPivot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_DefaultMappingContext,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_JumpAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_MoveAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_LookAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_WeaponEquipAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_WeaponAimAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_WeaponAimEndAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_FlyAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProjectProwerCharacter_Statics::NewProp_CameraManager,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AProjectProwerCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AProjectProwerCharacter>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AProjectProwerCharacter_Statics::ClassParams = {
		&AProjectProwerCharacter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AProjectProwerCharacter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AProjectProwerCharacter_Statics::PropPointers),
		0,
		0x008000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AProjectProwerCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_AProjectProwerCharacter_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AProjectProwerCharacter_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AProjectProwerCharacter()
	{
		if (!Z_Registration_Info_UClass_AProjectProwerCharacter.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AProjectProwerCharacter.OuterSingleton, Z_Construct_UClass_AProjectProwerCharacter_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AProjectProwerCharacter.OuterSingleton;
	}
	template<> PROJECTPROWER_API UClass* StaticClass<AProjectProwerCharacter>()
	{
		return AProjectProwerCharacter::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AProjectProwerCharacter);
	AProjectProwerCharacter::~AProjectProwerCharacter() {}
	struct Z_CompiledInDeferFile_FID_Users_eheil_Documents_Unreal_Projects_TailsProject_ProjectPrower_Source_ProjectPrower_ProjectProwerCharacter_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_eheil_Documents_Unreal_Projects_TailsProject_ProjectPrower_Source_ProjectPrower_ProjectProwerCharacter_h_Statics::EnumInfo[] = {
		{ EMovementState_StaticEnum, TEXT("EMovementState"), &Z_Registration_Info_UEnum_EMovementState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1126189747U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_eheil_Documents_Unreal_Projects_TailsProject_ProjectPrower_Source_ProjectPrower_ProjectProwerCharacter_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AProjectProwerCharacter, AProjectProwerCharacter::StaticClass, TEXT("AProjectProwerCharacter"), &Z_Registration_Info_UClass_AProjectProwerCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AProjectProwerCharacter), 653942067U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_eheil_Documents_Unreal_Projects_TailsProject_ProjectPrower_Source_ProjectPrower_ProjectProwerCharacter_h_273705470(TEXT("/Script/ProjectPrower"),
		Z_CompiledInDeferFile_FID_Users_eheil_Documents_Unreal_Projects_TailsProject_ProjectPrower_Source_ProjectPrower_ProjectProwerCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_eheil_Documents_Unreal_Projects_TailsProject_ProjectPrower_Source_ProjectPrower_ProjectProwerCharacter_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Users_eheil_Documents_Unreal_Projects_TailsProject_ProjectPrower_Source_ProjectPrower_ProjectProwerCharacter_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_eheil_Documents_Unreal_Projects_TailsProject_ProjectPrower_Source_ProjectPrower_ProjectProwerCharacter_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
