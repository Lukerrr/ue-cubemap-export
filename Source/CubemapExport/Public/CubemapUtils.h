// Copyright (C) 2023 by Lukerrr. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

class UTextureCube;
class UTextureRenderTargetCube;

/**
 * Class of static cubemap export functions.
 */
class FCubemapUtils
{
public:
	/**
	 * Exports a UTextureRenderTargetCube as 8-bit JPEG image into FArchive.
	 *
	 * @param CubeRt	The render target cube to export
	 * @param Ar		Archive to fill with data.
	 * @param Quality	JPEG compression quality (1-100).
	 * @return			Export operation success or failure.
	 */
	CUBEMAPEXPORT_API static bool ExportRenderTargetCubeAsJPG(UTextureRenderTargetCube* CubeRt, FArchive& Ar, int32 Quality = 100);

	/**
	 * Exports a UTextureCube as 8-bit JPEG image into FArchive.
	 *
	 * @param CubeTex	The texture cube to export
	 * @param Ar		Archive to fill with data.
	 * @param Quality	JPEG compression quality (1-100).
	 * @return			Export operation success or failure.
	 */
	CUBEMAPEXPORT_API static bool ExportTextureCubeAsJPG(UTextureCube* CubeTex, FArchive& Ar, int32 Quality = 100);

	/**
	 * Exports a UTextureRenderTargetCube as 8-bit PNG image into FArchive.
	 * Compression is not applied.
	 *
	 * @param CubeRt	The render target cube to export
	 * @param Ar		Archive to fill with data.
	 * @return			Export operation success or failure.
	 */
	CUBEMAPEXPORT_API static bool ExportRenderTargetCubeAsPNG(UTextureRenderTargetCube* CubeRt, FArchive& Ar);

	/**
	 * Exports a UTextureCube as 8-bit PNG image into FArchive.
	 * Compression is not applied.
	 *
	 * @param CubeTex	The texture cube to export
	 * @param Ar		Archive to fill with data.
	 * @return			Export operation success or failure.
	 */
	CUBEMAPEXPORT_API static bool ExportTextureCubeAsPNG(UTextureCube* CubeTex, FArchive& Ar);

	/**
	 * Exports a UTextureRenderTargetCube as 32-bit EXR image into FArchive.
	 *
	 * @param CubeRt	The render target cube to export
	 * @param Ar		Archive to fill with data.
	 * @param bZipComp	Whether to use zip compression for output.
	 * @return			Export operation success or failure.
	 */
	CUBEMAPEXPORT_API static bool ExportRenderTargetCubeAsEXR(UTextureRenderTargetCube* CubeRt, FArchive& Ar, bool bZipComp = false);

	/**
	 * Exports a UTextureCube as 32-bit EXR image into FArchive.
	 *
	 * @param CubeTex	The texture cube to export
	 * @param Ar		Archive to fill with data.
	 * @param bZipComp	Whether to use zip compression for output.
	 * @return			Export operation success or failure.
	 */
	CUBEMAPEXPORT_API static bool ExportTextureCubeAsEXR(UTextureCube* CubeTex, FArchive& Ar, bool bZipComp = false);

	/**
	 * Exports a UTextureRenderTargetCube as 8-bit BMP image into FArchive.
	 *
	 * @param CubeRt	The render target cube to export
	 * @param Ar		Archive to fill with data.
	 * @return			Export operation success or failure.
	 */
	CUBEMAPEXPORT_API static bool ExportRenderTargetCubeAsBMP(UTextureRenderTargetCube* CubeRt, FArchive& Ar);

	/**
	 * Exports a UTextureCube as 8-bit BMP image into FArchive.
	 *
	 * @param CubeTex	The texture cube to export
	 * @param Ar		Archive to fill with data.
	 * @return			Export operation success or failure.
	 */
	CUBEMAPEXPORT_API static bool ExportTextureCubeAsBMP(UTextureCube* CubeTex, FArchive& Ar);
};
