# Cubemap Export

**Available on the [Marketplace](https://www.unrealengine.com/marketplace/en-US/product/7b9b6aa0079d4073b909fdb11e12e60d).**

Engine supports only HDR format by default when exporting cubemaps, the plugin extends formats list. Plugin provides editor tools and runtime API for exporting of cube textures and render targets to files in various formats.

**Image formats supported:**
- _PNG (8-bit)_
- _JPEG (8-bit)_
- _BMP (8-bit)_
- _EXR (32-bit)_
- _HDR (32-bit)_

## Technical information

**Features:**
- _Export cubemap assets via **'Asset Actions -> Export'** menu in editor_
- _Export cubemap textures in runtime using Blueprints or C++ API_

**Texture types supported:**
- _Texture Render Target Cube_
- _Texture Cube_

**Code Modules:**
- _CubemapExport [<ins>Runtime</ins>]_
- _CubemapExportEditor [<ins>Editor</ins>]_

**Supported platforms:** _Windows_

## Installation

### From Marketplace

1. Buy the plugin on the [Marketplace page](https://www.unrealengine.com/marketplace/en-US/product/7b9b6aa0079d4073b909fdb11e12e60d).
2. Install the plugin to the engine using Epic Games Launcher.
3. Open your project and enable the plugin in '_Edit->Plugins_' menu.

### From Release

1. Download latest [release](https://github.com/Lukerrr/ue-cubemap-export/releases) from the GitHub page.
2. Unzip the release into your project's plugins directory: _%PROJECT_DIR%/Plugins_.
3. Open your project and enable the plugin in '_Edit->Plugins_' menu.

### Manual build

1. Clone repository or download zip.
2. Put the plugin's files into your project's plugins directory: _%PROJECT_DIR%/Plugins/CubemapExport_.
3. Rebuild your project.

## How to use

### Export assets

1. Right-click on the asset ('_Texture Render Target Cube_' or '_Texture Cube_').
2. Select '_Asset Actions -> Export_'.
3. Choose file format and save the file.

### Blueprint API

[See Blueprints example.](https://blueprintue.com/blueprint/yg1xu1ot/)

### C++ API

1. Add _CubemapExport_ module dependency into your project's module (_.Build.cs_ file):
```cs
PublicDependencyModuleNames.AddRange(new string[] {
  "CubemapExport"
});
```
2. Use API function to export cubemaps:
```cpp
#include "Engine/TextureCube.h"
#include "Engine/TextureRenderTargetCube.h"
#include "CubemapExportLibrary.h"
...
UTextureRenderTargetCube* RenderTargetCube;
UTextureCube* TextureCube;
...
UCubemapExportLibrary::ExportRenderTargetCube(RenderTargetCube, TEXT("E:/"), TEXT("RenderTarget.png")); // Export render target cube as PNG
UCubemapExportLibrary::ExportRenderTargetCube(RenderTargetCube, TEXT("E:/"), TEXT("RenderTarget.jpg")); // Export render target cube as JPEG
UCubemapExportLibrary::ExportRenderTargetCube(RenderTargetCube, TEXT("E:/"), TEXT("RenderTarget.bmp")); // Export render target cube as BMP
UCubemapExportLibrary::ExportRenderTargetCube(RenderTargetCube, TEXT("E:/"), TEXT("RenderTarget.exr")); // Export render target cube as EXR
UCubemapExportLibrary::ExportRenderTargetCube(RenderTargetCube, TEXT("E:/"), TEXT("RenderTarget.hdr")); // Export render target cube as HDR
...
UCubemapExportLibrary::ExportTextureCube(TextureCube, TEXT("E:/"), TEXT("Texture.png"); // Export texture cube as PNG
UCubemapExportLibrary::ExportTextureCube(TextureCube, TEXT("E:/"), TEXT("Texture.jpg"); // Export texture cube as JPEG
UCubemapExportLibrary::ExportTextureCube(TextureCube, TEXT("E:/"), TEXT("Texture.bmp"); // Export texture cube as BMP
UCubemapExportLibrary::ExportTextureCube(TextureCube, TEXT("E:/"), TEXT("Texture.exr"); // Export texture cube as EXR
UCubemapExportLibrary::ExportTextureCube(TextureCube, TEXT("E:/"), TEXT("Texture.hdr"); // Export texture cube as HDR
```
## Known limitations

1. Alpha channel is not fully supported and filled with 255 or 1.0 values (in case of various formats).
1. PNG format is exported only with 8-bit depth.

## Contact

- **E-Mail:** _thelukerrr@gmail.com_
- **Discord:** _@Lukerrr_
