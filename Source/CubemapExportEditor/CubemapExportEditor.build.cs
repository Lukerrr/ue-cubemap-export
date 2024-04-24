// Copyright (C) 2023-2024 by Lukerrr. MIT License.

using UnrealBuildTool;
using System.IO;

public class CubemapExportEditor : ModuleRules
{
    public CubemapExportEditor(ReadOnlyTargetRules ROTargetRules) : base(ROTargetRules)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "UnrealEd",
        });

        PrivateDependencyModuleNames.AddRange(new string[] {
            "CubemapExport",
        });
    }
}
