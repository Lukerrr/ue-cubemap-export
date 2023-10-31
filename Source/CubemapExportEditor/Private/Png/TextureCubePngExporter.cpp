// Copyright (C) 2023 by Lukerrr. All Rights Reserved.

#include "Png/TextureCubePngExporter.h"
#include "CubemapUtils.h"
#include "Engine/TextureCube.h"

UTextureCubePngExporter::UTextureCubePngExporter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UTextureCube::StaticClass();
	PreferredFormatIndex = 0;
	FormatExtension.Add(TEXT("PNG"));
	FormatDescription.Add(TEXT("Portable Network Graphics"));
}

bool UTextureCubePngExporter::ExportBinary(UObject* Object, const TCHAR* Type, FArchive& Ar, FFeedbackContext* Warn, int32 FileIndex /*= 0*/, uint32 PortFlags /*= 0*/)
{
	return FCubemapUtils::ExportTextureCubeAsPNG(Cast<UTextureCube>(Object), Ar);
}
