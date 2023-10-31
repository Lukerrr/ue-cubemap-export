// Copyright (C) 2023 by Lukerrr. All Rights Reserved.

#include "CubemapExportLibrary.h"

#include "CubemapUtils.h"

#include "Engine/TextureCube.h"
#include "Engine/TextureRenderTargetCube.h"
#include "IImageWrapper.h"
#include "ImageUtils.h"
#include "Serialization/BufferArchive.h"

static EImageFormat GetImageFormatFromFileName(const FString& FileName)
{
	FString Extension = FPaths::GetExtension(FileName).ToUpper();

	if (Extension == TEXT("JPEG") || Extension == TEXT("JPG"))
	{
		return EImageFormat::JPEG;
	}
	else if (Extension == TEXT("BMP"))
	{
		return EImageFormat::BMP;
	}
	else if (Extension == TEXT("HDR"))
	{
		return EImageFormat::HDR;
	}
	else if (Extension == TEXT("EXR"))
	{
		return EImageFormat::EXR;
	}

	return EImageFormat::PNG;
}

void UCubemapExportLibrary::ExportRenderTargetCube(UTextureRenderTargetCube* TextureRenderTargetCube, const FString& FilePath, const FString& FileName)
{
	FString TotalFileName = FPaths::Combine(*FilePath, *FileName);
	FText PathError;
	FPaths::ValidatePath(TotalFileName, &PathError);

	if (!TextureRenderTargetCube)
	{
		FMessageLog("Blueprint").Warning(FText::Format(FText::FromString("ExportRenderTargetCube[{0}]: TextureRenderTarget must be non-null."),
			FText::FromString(TotalFileName)));
	}
	else if (!TextureRenderTargetCube->GetResource())
	{
		FMessageLog("Blueprint").Warning(FText::Format(FText::FromString("ExportRenderTargetCube[{0}]: render target has been released."),
			FText::FromString(TotalFileName)));
	}
	else if (!PathError.IsEmpty())
	{
		FMessageLog("Blueprint").Warning(FText::Format(FText::FromString("ExportRenderTargetCube[{0}]: Invalid file path provided: '{1}'"),
			FText::FromString(TotalFileName), PathError));
	}
	else if (FileName.IsEmpty())
	{
		FMessageLog("Blueprint").Warning(FText::Format(FText::FromString("ExportRenderTargetCube[{0}]: FileName must be non-empty."),
			FText::FromString(TotalFileName)));
	}
	else
	{
		FArchive* Ar = IFileManager::Get().CreateFileWriter(*TotalFileName);

		if (Ar)
		{
			FBufferArchive Buffer;

			bool bSuccess = false;
			switch (GetImageFormatFromFileName(FileName))
			{
			case EImageFormat::PNG:
				bSuccess = FCubemapUtils::ExportRenderTargetCubeAsPNG(TextureRenderTargetCube, Buffer);
				break;
			case EImageFormat::JPEG:
				bSuccess = FCubemapUtils::ExportRenderTargetCubeAsJPG(TextureRenderTargetCube, Buffer);
				break;
			case EImageFormat::BMP:
				bSuccess = FCubemapUtils::ExportRenderTargetCubeAsBMP(TextureRenderTargetCube, Buffer);
				break;
			case EImageFormat::EXR:
				bSuccess = FCubemapUtils::ExportRenderTargetCubeAsEXR(TextureRenderTargetCube, Buffer);
				break;
			case EImageFormat::HDR:
				bSuccess = FImageUtils::ExportRenderTargetCubeAsHDR(TextureRenderTargetCube, Buffer);
				break;
			default:
				break;
			}

			if (bSuccess)
			{
				Ar->Serialize(const_cast<uint8*>(Buffer.GetData()), Buffer.Num());
			}

			delete Ar;
		}
		else
		{
			FMessageLog("Blueprint").Warning(FText::Format(FText::FromString("ExportRenderTargetCube[{0}]: FileWrite failed to create."),
				FText::FromString(TotalFileName)));
		}
	}
}

void UCubemapExportLibrary::ExportTextureCube(UTextureCube* TextureCube, const FString& FilePath, const FString& FileName)
{
	FString TotalFileName = FPaths::Combine(*FilePath, *FileName);
	FText PathError;
	FPaths::ValidatePath(TotalFileName, &PathError);

	if (!TextureCube)
	{
		FMessageLog("Blueprint").Warning(FText::Format(FText::FromString("ExportTextureCube[{0}]: TextureRenderTarget must be non-null."),
			FText::FromString(TotalFileName)));
	}
	else if (!TextureCube->GetResource())
	{
		FMessageLog("Blueprint").Warning(FText::Format(FText::FromString("ExportTextureCube[{0}]: render target has been released."),
			FText::FromString(TotalFileName)));
	}
	else if (!PathError.IsEmpty())
	{
		FMessageLog("Blueprint").Warning(FText::Format(FText::FromString("ExportTextureCube[{0}]: Invalid file path provided: '{1}'"),
			FText::FromString(TotalFileName), PathError));
	}
	else if (FileName.IsEmpty())
	{
		FMessageLog("Blueprint").Warning(FText::Format(FText::FromString("ExportTextureCube[{0}]: FileName must be non-empty."),
			FText::FromString(TotalFileName)));
	}
	else
	{
		FArchive* Ar = IFileManager::Get().CreateFileWriter(*TotalFileName);

		if (Ar)
		{
			FBufferArchive Buffer;

			bool bSuccess = false;
			switch (GetImageFormatFromFileName(FileName))
			{
			case EImageFormat::PNG:
				bSuccess = FCubemapUtils::ExportTextureCubeAsPNG(TextureCube, Buffer);
				break;
			case EImageFormat::JPEG:
				bSuccess = FCubemapUtils::ExportTextureCubeAsJPG(TextureCube, Buffer);
				break;
			case EImageFormat::BMP:
				bSuccess = FCubemapUtils::ExportTextureCubeAsBMP(TextureCube, Buffer);
				break;
			case EImageFormat::EXR:
				bSuccess = FCubemapUtils::ExportTextureCubeAsEXR(TextureCube, Buffer);
				break;
			case EImageFormat::HDR:
				bSuccess = FImageUtils::ExportTextureCubeAsHDR(TextureCube, Buffer);
				break;
			default:
				break;
			}

			if (bSuccess)
			{
				Ar->Serialize(const_cast<uint8*>(Buffer.GetData()), Buffer.Num());
			}

			delete Ar;
		}
		else
		{
			FMessageLog("Blueprint").Warning(FText::Format(FText::FromString("ExportTextureCube[{0}]: FileWrite failed to create."),
				FText::FromString(TotalFileName)));
		}
	}
}
