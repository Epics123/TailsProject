// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectPrower/ProjectProwerGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeProjectProwerGameMode() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	PROJECTPROWER_API UClass* Z_Construct_UClass_AProjectProwerGameMode();
	PROJECTPROWER_API UClass* Z_Construct_UClass_AProjectProwerGameMode_NoRegister();
	UPackage* Z_Construct_UPackage__Script_ProjectPrower();
// End Cross Module References
	void AProjectProwerGameMode::StaticRegisterNativesAProjectProwerGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AProjectProwerGameMode);
	UClass* Z_Construct_UClass_AProjectProwerGameMode_NoRegister()
	{
		return AProjectProwerGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AProjectProwerGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AProjectProwerGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_ProjectPrower,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AProjectProwerGameMode_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectProwerGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "ProjectProwerGameMode.h" },
		{ "ModuleRelativePath", "ProjectProwerGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AProjectProwerGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AProjectProwerGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AProjectProwerGameMode_Statics::ClassParams = {
		&AProjectProwerGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AProjectProwerGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AProjectProwerGameMode_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AProjectProwerGameMode()
	{
		if (!Z_Registration_Info_UClass_AProjectProwerGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AProjectProwerGameMode.OuterSingleton, Z_Construct_UClass_AProjectProwerGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AProjectProwerGameMode.OuterSingleton;
	}
	template<> PROJECTPROWER_API UClass* StaticClass<AProjectProwerGameMode>()
	{
		return AProjectProwerGameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AProjectProwerGameMode);
	AProjectProwerGameMode::~AProjectProwerGameMode() {}
	struct Z_CompiledInDeferFile_FID_Users_eheil_Documents_Unreal_Projects_TailsProject_ProjectPrower_Source_ProjectPrower_ProjectProwerGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_eheil_Documents_Unreal_Projects_TailsProject_ProjectPrower_Source_ProjectPrower_ProjectProwerGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AProjectProwerGameMode, AProjectProwerGameMode::StaticClass, TEXT("AProjectProwerGameMode"), &Z_Registration_Info_UClass_AProjectProwerGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AProjectProwerGameMode), 4013077046U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_eheil_Documents_Unreal_Projects_TailsProject_ProjectPrower_Source_ProjectPrower_ProjectProwerGameMode_h_799701346(TEXT("/Script/ProjectPrower"),
		Z_CompiledInDeferFile_FID_Users_eheil_Documents_Unreal_Projects_TailsProject_ProjectPrower_Source_ProjectPrower_ProjectProwerGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_eheil_Documents_Unreal_Projects_TailsProject_ProjectPrower_Source_ProjectPrower_ProjectProwerGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
