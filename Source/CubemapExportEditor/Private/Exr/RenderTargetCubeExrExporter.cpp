// Copyright (C) 2023 by Lukerrr. All Rights Reserved.

#include "Exr/RenderTargetCubeExrExporter.h"
#include "CubemapUtils.h"
#include "Engine/TextureRenderTargetCube.h"

URenderTargetCubeExrExporter::URenderTargetCubeExrExporter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UTextureRenderTargetCube::StaticClass();
	PreferredFormatIndex = 0;
	FormatExtension.Add(TEXT("EXR"));
	FormatDescription.Add(TEXT("Extended Dynamic Range"));
}

bool URenderTargetCubeExrExporter::ExportBinary(UObject* Object, const TCHAR* Type, FArchive& Ar, FFeedbackContext* Warn, int32 FileIndex /*= 0*/, uint32 PortFlags /*= 0*/)
{
	return FCubemapUtils::ExportRenderTargetCubeAsEXR(Cast<UTextureRenderTargetCube>(Object), Ar);
}
