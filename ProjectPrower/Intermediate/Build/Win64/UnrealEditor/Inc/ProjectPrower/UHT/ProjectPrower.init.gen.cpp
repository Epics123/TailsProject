// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeProjectPrower_init() {}
	PROJECTPROWER_API UFunction* Z_Construct_UDelegateFunction_ProjectPrower_AimEndedDelegate__DelegateSignature();
	PROJECTPROWER_API UFunction* Z_Construct_UDelegateFunction_ProjectPrower_AimStartedDelegate__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_ProjectPrower;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_ProjectPrower()
	{
		if (!Z_Registration_Info_UPackage__Script_ProjectPrower.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_ProjectPrower_AimEndedDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_ProjectPrower_AimStartedDelegate__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/ProjectPrower",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x7995C2FB,
				0x243B8569,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_ProjectPrower.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_ProjectPrower.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_ProjectPrower(Z_Construct_UPackage__Script_ProjectPrower, TEXT("/Script/ProjectPrower"), Z_Registration_Info_UPackage__Script_ProjectPrower, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x7995C2FB, 0x243B8569));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
