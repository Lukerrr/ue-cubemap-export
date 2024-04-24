// Copyright (C) 2023-2024 by Lukerrr. MIT License.

#include "Bmp/TextureCubeBmpExporter.h"
#include "CubemapUtils.h"
#include "Engine/TextureCube.h"

UTextureCubeBmpExporter::UTextureCubeBmpExporter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UTextureCube::StaticClass();
	PreferredFormatIndex = 0;
	FormatExtension.Add(TEXT("BMP"));
	FormatDescription.Add(TEXT("Bitmap Picture"));
}

bool UTextureCubeBmpExporter::ExportBinary(UObject* Object, const TCHAR* Type, FArchive& Ar, FFeedbackContext* Warn, int32 FileIndex /*= 0*/, uint32 PortFlags /*= 0*/)
{
	return FCubemapUtils::ExportTextureCubeAsBMP(Cast<UTextureCube>(Object), Ar);
}
