// Copyright (C) 2023 by Lukerrr. All Rights Reserved.

#include "Png/RenderTargetCubePngExporter.h"
#include "CubemapUtils.h"
#include "Engine/TextureRenderTargetCube.h"

URenderTargetCubePngExporter::URenderTargetCubePngExporter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UTextureRenderTargetCube::StaticClass();
	PreferredFormatIndex = 0;
	FormatExtension.Add(TEXT("PNG"));
	FormatDescription.Add(TEXT("Portable Network Graphics"));
}

bool URenderTargetCubePngExporter::ExportBinary(UObject* Object, const TCHAR* Type, FArchive& Ar, FFeedbackContext* Warn, int32 FileIndex /*= 0*/, uint32 PortFlags /*= 0*/)
{
	return FCubemapUtils::ExportRenderTargetCubeAsPNG(Cast<UTextureRenderTargetCube>(Object), Ar);
}
