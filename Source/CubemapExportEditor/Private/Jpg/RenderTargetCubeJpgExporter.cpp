// Copyright (C) 2023 by Lukerrr. All Rights Reserved.

#include "Jpg/RenderTargetCubeJpgExporter.h"
#include "CubemapUtils.h"
#include "Engine/TextureRenderTargetCube.h"

URenderTargetCubeJpgExporter::URenderTargetCubeJpgExporter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UTextureRenderTargetCube::StaticClass();
	PreferredFormatIndex = 0;
	FormatExtension.Add(TEXT("JPG"));
	FormatDescription.Add(TEXT("Joint Photographic Experts Group"));
}

bool URenderTargetCubeJpgExporter::ExportBinary(UObject* Object, const TCHAR* Type, FArchive& Ar, FFeedbackContext* Warn, int32 FileIndex /*= 0*/, uint32 PortFlags /*= 0*/)
{
	return FCubemapUtils::ExportRenderTargetCubeAsJPG(Cast<UTextureRenderTargetCube>(Object), Ar);
}
