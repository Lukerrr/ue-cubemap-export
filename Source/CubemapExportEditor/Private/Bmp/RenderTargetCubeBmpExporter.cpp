// Copyright (C) 2023-2024 by Lukerrr. MIT License.

#include "Bmp/RenderTargetCubeBmpExporter.h"
#include "CubemapUtils.h"
#include "Engine/TextureRenderTargetCube.h"

URenderTargetCubeBmpExporter::URenderTargetCubeBmpExporter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UTextureRenderTargetCube::StaticClass();
	PreferredFormatIndex = 0;
	FormatExtension.Add(TEXT("BMP"));
	FormatDescription.Add(TEXT("Bitmap Picture"));
}

bool URenderTargetCubeBmpExporter::ExportBinary(UObject* Object, const TCHAR* Type, FArchive& Ar, FFeedbackContext* Warn, int32 FileIndex /*= 0*/, uint32 PortFlags /*= 0*/)
{
	return FCubemapUtils::ExportRenderTargetCubeAsBMP(Cast<UTextureRenderTargetCube>(Object), Ar);
}
