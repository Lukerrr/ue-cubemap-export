// Copyright (C) 2023 by Lukerrr. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Exporters/Exporter.h"
#include "RenderTargetCubePngExporter.generated.h"

UCLASS()
class CUBEMAPEXPORTEDITOR_API URenderTargetCubePngExporter : public UExporter
{
	GENERATED_BODY()
public:
	URenderTargetCubePngExporter(const FObjectInitializer& ObjectInitializer);

	//~Begin UExporter interface
	virtual bool ExportBinary(UObject* Object, const TCHAR* Type, FArchive& Ar, FFeedbackContext* Warn, int32 FileIndex = 0, uint32 PortFlags = 0) override;
	//~End UExporter interface
};
