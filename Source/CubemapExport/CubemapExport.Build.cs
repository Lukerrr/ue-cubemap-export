// Copyright (C) 2023 by Lukerrr. All Rights Reserved.

using UnrealBuildTool;

public class CubemapExport : ModuleRules
{
	public CubemapExport(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;			

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
		});

		PrivateDependencyModuleNames.AddRange(new string[] {
			"CoreUObject",
			"Engine",
			"Slate",
			"SlateCore",
            "RHI",
            "RenderCore",
            "ImageCore",
        });
	}
}
