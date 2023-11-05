// Copyright (C) 2023 by Lukerrr. All Rights Reserved.

#include "CubemapUtils.h"

#include "CanvasItem.h"
#include "CanvasTypes.h"
#include "CubemapUnwrapUtils.h"
#include "Engine/TextureCube.h"
#include "Engine/TextureRenderTargetCube.h"
#include "Engine/TextureRenderTarget2D.h"
#include "IImageWrapper.h"
#include "IImageWrapperModule.h"
#include "Runtime/Launch/Resources/Version.h"

/**
 * Helper function to export an unwrapped 2D image of
 * the cube map ( longitude/latitude ) with specified format into the archive.
 *
 * @param	Ar				Archive to fill with data.
 * @param	CubeTex			Cubemap texture object (either TextureCube or RenderTargetCube).
 * @param	Format			Format of output image
 * @param	Quality			Compression quality
 * @return					true on success.
 */
template<class CubeTextureClass>
static bool WriteCubemapToArchive(FArchive& Ar, CubeTextureClass* CubeTex, EImageFormat Format, int32 Quality)
{
	TArray64<uint8> Bits;
	FIntPoint Size;
	EPixelFormat PixelFormat;
	if (!CubemapHelpers::GenerateLongLatUnwrap(CubeTex, Bits, Size, PixelFormat))
	{
		return false;
	}

	FImage Image2D;
	switch (PixelFormat)
	{
	case PF_B8G8R8A8:
	{
		Image2D = FImage(Size.X, Size.Y, ERawImageFormat::BGRA8);
		Image2D.RawData = Bits;
		break;
	}
	case PF_FloatRGBA:
	{
		if (Format == EImageFormat::PNG)
		{
			// Convert 16-bit linear color to 8-bit sRGB color (BGRA8 format)
			FImage ImageView16Bit = FImage(Size.X, Size.Y, ERawImageFormat::RGBA16F);
			ImageView16Bit.RawData = Bits;
			ImageView16Bit.CopyTo(Image2D, ERawImageFormat::BGRA8, EGammaSpace::sRGB);
		}
		else
		{
			Image2D = FImage(Size.X, Size.Y, ERawImageFormat::RGBA16F);
			Image2D.RawData = Bits;
		}
		break;
	}
	default:
	{
		break;
	}
	}

	// Set A to 255, because GenerateLongLatUnwrap fills alpha channel with zeros
#if (ENGINE_MAJOR_VERSION >= 5) && (ENGINE_MINOR_VERSION >= 2)
	FImageCore::SetAlphaOpaque(Image2D);
#else
	switch (Image2D.Format)
	{
	case ERawImageFormat::BGRA8:
	{
		TArrayView64<FColor> SrcColorArray = Image2D.AsBGRA8();

		FColor* ColorPtr = &SrcColorArray[0];
		FColor* EndPtr = ColorPtr + SrcColorArray.Num();

		for (; ColorPtr < EndPtr; ++ColorPtr)
		{
			ColorPtr->A = 255;
		}
		break;
	}
	case ERawImageFormat::RGBA16F:
	{
		TArrayView64<FFloat16Color> SrcColorArray = Image2D.AsRGBA16F();

		FFloat16Color* ColorPtr = &SrcColorArray[0];
		FFloat16Color* EndPtr = ColorPtr + SrcColorArray.Num();

		for (; ColorPtr < EndPtr; ++ColorPtr)
		{
			ColorPtr->A = 1.f;
		}
		break;
	}
	default:
	{
		break;
	}
	}
#endif

	TArray64<uint8> CompressedImage2D;
	auto& ImageWrapperModule = FModuleManager::Get().LoadModuleChecked<IImageWrapperModule>(TEXT("ImageWrapper"));
	if (!ImageWrapperModule.CompressImage(CompressedImage2D, Format, Image2D, Quality))
	{
		return false;
	}

	Ar.Serialize(const_cast<uint8*>(CompressedImage2D.GetData()), CompressedImage2D.Num());

	return true;
}

bool FCubemapUtils::ExportRenderTargetCubeAsJPG(UTextureRenderTargetCube* CubeRt, FArchive& Ar, int32 Quality /*= 100*/)
{
	return WriteCubemapToArchive(Ar, CubeRt, EImageFormat::JPEG, Quality);
}

bool FCubemapUtils::ExportTextureCubeAsJPG(UTextureCube* CubeTex, FArchive& Ar, int32 Quality /*= 100*/)
{
	return WriteCubemapToArchive(Ar, CubeTex, EImageFormat::JPEG, Quality);
}

bool FCubemapUtils::ExportRenderTargetCubeAsPNG(UTextureRenderTargetCube* CubeRt, FArchive& Ar)
{
	return WriteCubemapToArchive(Ar, CubeRt, EImageFormat::PNG, 100);
}

bool FCubemapUtils::ExportTextureCubeAsPNG(UTextureCube* CubeTex, FArchive& Ar)
{
	return WriteCubemapToArchive(Ar, CubeTex, EImageFormat::PNG, 100);
}

bool FCubemapUtils::ExportRenderTargetCubeAsEXR(UTextureRenderTargetCube* CubeRt, FArchive& Ar, bool bZipComp /*= false*/)
{
	return WriteCubemapToArchive(Ar, CubeRt, EImageFormat::EXR, bZipComp ? 100 : (int32)EImageCompressionQuality::Uncompressed);
}

bool FCubemapUtils::ExportTextureCubeAsEXR(UTextureCube* CubeTex, FArchive& Ar, bool bZipComp /*= false*/)
{
	return WriteCubemapToArchive(Ar, CubeTex, EImageFormat::EXR, bZipComp ? 100 : (int32)EImageCompressionQuality::Uncompressed);
}

bool FCubemapUtils::ExportRenderTargetCubeAsBMP(UTextureRenderTargetCube* CubeRt, FArchive& Ar)
{
	return WriteCubemapToArchive(Ar, CubeRt, EImageFormat::BMP, 100);
}

bool FCubemapUtils::ExportTextureCubeAsBMP(UTextureCube* CubeTex, FArchive& Ar)
{
	return WriteCubemapToArchive(Ar, CubeTex, EImageFormat::BMP, 100);
}
