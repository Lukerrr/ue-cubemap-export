// Copyright (C) 2023-2024 by Lukerrr. MIT License.

#pragma once

#include "CoreMinimal.h"
#include "Exporters/Exporter.h"
#include "RenderTargetCubeExrExporter.generated.h"

UCLASS()
class CUBEMAPEXPORTEDITOR_API URenderTargetCubeExrExporter : public UExporter
{
	GENERATED_BODY()
public:
	URenderTargetCubeExrExporter(const FObjectInitializer& ObjectInitializer);

	//~Begin UExporter interface
	virtual bool ExportBinary(UObject* Object, const TCHAR* Type, FArchive& Ar, FFeedbackContext* Warn, int32 FileIndex = 0, uint32 PortFlags = 0) override;
	//~End UExporter interface
};
