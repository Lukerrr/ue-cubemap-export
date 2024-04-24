// Copyright (C) 2023-2024 by Lukerrr. MIT License.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CubemapExportLibrary.generated.h"

class UTextureCube;
class UTextureRenderTargetCube;

UCLASS()
class CUBEMAPEXPORT_API UCubemapExportLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**
	 * Exports RenderTargetCube onto the disk.
	 * Supported formats: PNG/JPEG/BMP/HDR/EXR.
	 * Image format is determined from the file extension.
	 * If format cannot be determined - PNG format is chosen.
	 */
	UFUNCTION(BlueprintCallable, Category = "Rendering", meta = (Keywords = "ExportRenderTargetCube"))
	static void ExportRenderTargetCube(UTextureRenderTargetCube* TextureRenderTargetCube, const FString& FilePath, const FString& FileName);

	/**
	 * Exports TextureCube onto the disk.
	 * Supported formats: PNG/JPEG/BMP/HDR/EXR.
	 * Image format is determined from the file extension.
	 * If format cannot be determined - PNG format is chosen.
	 */
	UFUNCTION(BlueprintCallable, Category = "Rendering", meta = (Keywords = "ExportTextureCube"))
	static void ExportTextureCube(UTextureCube* TextureCube, const FString& FilePath, const FString& FileName);
};
