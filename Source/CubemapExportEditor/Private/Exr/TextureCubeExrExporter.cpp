// Copyright (C) 2023-2024 by Lukerrr. MIT License.

#include "Exr/TextureCubeExrExporter.h"
#include "CubemapUtils.h"
#include "Engine/TextureCube.h"

UTextureCubeExrExporter::UTextureCubeExrExporter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UTextureCube::StaticClass();
	PreferredFormatIndex = 0;
	FormatExtension.Add(TEXT("EXR"));
	FormatDescription.Add(TEXT("Extended Dynamic Range"));
}

bool UTextureCubeExrExporter::ExportBinary(UObject* Object, const TCHAR* Type, FArchive& Ar, FFeedbackContext* Warn, int32 FileIndex /*= 0*/, uint32 PortFlags /*= 0*/)
{
	return FCubemapUtils::ExportTextureCubeAsEXR(Cast<UTextureCube>(Object), Ar);
}
