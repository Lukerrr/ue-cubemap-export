// Copyright (C) 2023-2024 by Lukerrr. MIT License.

#pragma once

#include "CoreMinimal.h"
#include "Exporters/Exporter.h"
#include "RenderTargetCubeJpgExporter.generated.h"

UCLASS()
class CUBEMAPEXPORTEDITOR_API URenderTargetCubeJpgExporter : public UExporter
{
	GENERATED_BODY()
public:
	URenderTargetCubeJpgExporter(const FObjectInitializer& ObjectInitializer);

	//~Begin UExporter interface
	virtual bool ExportBinary(UObject* Object, const TCHAR* Type, FArchive& Ar, FFeedbackContext* Warn, int32 FileIndex = 0, uint32 PortFlags = 0) override;
	//~End UExporter interface
};
