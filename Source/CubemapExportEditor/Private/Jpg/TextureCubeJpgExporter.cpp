// Copyright (C) 2023 by Lukerrr. All Rights Reserved.

#include "Jpg/TextureCubeJpgExporter.h"
#include "CubemapUtils.h"
#include "Engine/TextureCube.h"

UTextureCubeJpgExporter::UTextureCubeJpgExporter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UTextureCube::StaticClass();
	PreferredFormatIndex = 0;
	FormatExtension.Add(TEXT("JPG"));
	FormatDescription.Add(TEXT("Joint Photographic Experts Group"));
}

bool UTextureCubeJpgExporter::ExportBinary(UObject* Object, const TCHAR* Type, FArchive& Ar, FFeedbackContext* Warn, int32 FileIndex /*= 0*/, uint32 PortFlags /*= 0*/)
{
	return FCubemapUtils::ExportTextureCubeAsJPG(Cast<UTextureCube>(Object), Ar);
}
