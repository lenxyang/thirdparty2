// File: dds_defs.h
// DX9 .DDS file header definitions.
#ifndef CRNLIB_DDS_DEFS_H
#define CRNLIB_DDS_DEFS_H

#include "crnlib.h"

#define CRNLIB_PIXEL_FMT_FOURCC(a, b, c, d) ((a) | ((b) << 8U) | ((c) << 16U) | ((d) << 24U))

namespace crnlib
{
   enum pixel_format
   {
      PIXEL_FMT_INVALID               = 0,

      PIXEL_FMT_DXT1                  = CRNLIB_PIXEL_FMT_FOURCC('D', 'X', 'T', '1'),
      PIXEL_FMT_DXT2                  = CRNLIB_PIXEL_FMT_FOURCC('D', 'X', 'T', '2'),
      PIXEL_FMT_DXT3                  = CRNLIB_PIXEL_FMT_FOURCC('D', 'X', 'T', '3'),
      PIXEL_FMT_DXT4                  = CRNLIB_PIXEL_FMT_FOURCC('D', 'X', 'T', '4'),
      PIXEL_FMT_DXT5                  = CRNLIB_PIXEL_FMT_FOURCC('D', 'X', 'T', '5'),
      PIXEL_FMT_3DC                   = CRNLIB_PIXEL_FMT_FOURCC('A', 'T', 'I', '2'), // DXN_YX
      PIXEL_FMT_DXN                   = CRNLIB_PIXEL_FMT_FOURCC('A', '2', 'X', 'Y'), // DXN_XY
      PIXEL_FMT_DXT5A                 = CRNLIB_PIXEL_FMT_FOURCC('A', 'T', 'I', '1'), // ATI1N, http://developer.amd.com/media/gpu_assets/Radeon_X1x00_Programming_Guide.pdf

      // Non-standard, crnlib-specific pixel formats (some of these are supported by ATI's compressonator)
      PIXEL_FMT_DXT5_CCxY             = CRNLIB_PIXEL_FMT_FOURCC('C', 'C', 'x', 'Y'),
      PIXEL_FMT_DXT5_xGxR             = CRNLIB_PIXEL_FMT_FOURCC('x', 'G', 'x', 'R'),
      PIXEL_FMT_DXT5_xGBR             = CRNLIB_PIXEL_FMT_FOURCC('x', 'G', 'B', 'R'),
      PIXEL_FMT_DXT5_AGBR             = CRNLIB_PIXEL_FMT_FOURCC('A', 'G', 'B', 'R'),

      PIXEL_FMT_DXT1A                 = CRNLIB_PIXEL_FMT_FOURCC('D', 'X', '1', 'A'),

      PIXEL_FMT_R8G8B8                = CRNLIB_PIXEL_FMT_FOURCC('R', 'G', 'B', 'x'),
      PIXEL_FMT_L8                    = CRNLIB_PIXEL_FMT_FOURCC('L', 'x', 'x', 'x'),
      PIXEL_FMT_A8                    = CRNLIB_PIXEL_FMT_FOURCC('x', 'x', 'x', 'A'),
      PIXEL_FMT_A8L8                  = CRNLIB_PIXEL_FMT_FOURCC('L', 'x', 'x', 'A'),
      PIXEL_FMT_A8R8G8B8              = CRNLIB_PIXEL_FMT_FOURCC('R', 'G', 'B', 'A')
   };

   const crn_uint32_t cDDSMaxImageDimensions = 8192U;

   // Total size of header is sizeof(uint32)+cDDSSizeofDDSurfaceDesc2;
   const crn_uint32_t cDDSSizeofDDSurfaceDesc2 = 124;

   // "DDS "
   const crn_uint32_t cDDSFileSignature = 0x20534444;

   struct DDCOLORKEY
   {
      crn_uint32_t dwUnused0;
      crn_uint32_t dwUnused1;
   };

   struct DDPIXELFORMAT
   {
      crn_uint32_t dwSize;
      crn_uint32_t dwFlags;
      crn_uint32_t dwFourCC;
      crn_uint32_t dwRGBBitCount;     // ATI compressonator and crnlib sometimes place a FOURCC code here
      crn_uint32_t dwRBitMask;
      crn_uint32_t dwGBitMask;
      crn_uint32_t dwBBitMask;
      crn_uint32_t dwRGBAlphaBitMask;
   };

   struct DDSCAPS2
   {
      crn_uint32_t dwCaps;
      crn_uint32_t dwCaps2;
      crn_uint32_t dwCaps3;
      crn_uint32_t dwCaps4;
   };

   struct DDSURFACEDESC2
   {
      crn_uint32_t dwSize;
      crn_uint32_t dwFlags;
      crn_uint32_t dwHeight;
      crn_uint32_t dwWidth;
      union
      {
         crn_int32_t lPitch;
         crn_uint32_t dwLinearSize;
      };
      crn_uint32_t dwBackBufferCount;
      crn_uint32_t dwMipMapCount;
      crn_uint32_t dwAlphaBitDepth;
      crn_uint32_t dwUnused0;
      crn_uint32_t lpSurface;
      DDCOLORKEY unused0;
      DDCOLORKEY unused1;
      DDCOLORKEY unused2;
      DDCOLORKEY unused3;
      DDPIXELFORMAT ddpfPixelFormat;
      DDSCAPS2 ddsCaps;
      crn_uint32_t dwUnused1;
   };
   
   const crn_uint32_t DDSD_CAPS                   = 0x00000001;
   const crn_uint32_t DDSD_HEIGHT                 = 0x00000002;
   const crn_uint32_t DDSD_WIDTH                  = 0x00000004;
   const crn_uint32_t DDSD_PITCH                  = 0x00000008;

   const crn_uint32_t DDSD_BACKBUFFERCOUNT        = 0x00000020;
   const crn_uint32_t DDSD_ZBUFFERBITDEPTH        = 0x00000040;
   const crn_uint32_t DDSD_ALPHABITDEPTH          = 0x00000080;

   const crn_uint32_t DDSD_LPSURFACE              = 0x00000800;
                                                            
   const crn_uint32_t DDSD_PIXELFORMAT            = 0x00001000;
   const crn_uint32_t DDSD_CKDESTOVERLAY          = 0x00002000;
   const crn_uint32_t DDSD_CKDESTBLT              = 0x00004000;
   const crn_uint32_t DDSD_CKSRCOVERLAY           = 0x00008000;

   const crn_uint32_t DDSD_CKSRCBLT               = 0x00010000;
   const crn_uint32_t DDSD_MIPMAPCOUNT            = 0x00020000;
   const crn_uint32_t DDSD_REFRESHRATE            = 0x00040000;
   const crn_uint32_t DDSD_LINEARSIZE             = 0x00080000;

   const crn_uint32_t DDSD_TEXTURESTAGE           = 0x00100000;
   const crn_uint32_t DDSD_FVF                    = 0x00200000;
   const crn_uint32_t DDSD_SRCVBHANDLE            = 0x00400000;
   const crn_uint32_t DDSD_DEPTH                  = 0x00800000;

   const crn_uint32_t DDSD_ALL                    = 0x00fff9ee;

   const crn_uint32_t DDPF_ALPHAPIXELS            = 0x00000001;
   const crn_uint32_t DDPF_ALPHA                  = 0x00000002;
   const crn_uint32_t DDPF_FOURCC                 = 0x00000004;
   const crn_uint32_t DDPF_PALETTEINDEXED8        = 0x00000020;
   const crn_uint32_t DDPF_RGB                    = 0x00000040;
   const crn_uint32_t DDPF_LUMINANCE              = 0x00020000;

   const crn_uint32_t DDSCAPS_COMPLEX             = 0x00000008;
   const crn_uint32_t DDSCAPS_TEXTURE             = 0x00001000;
   const crn_uint32_t DDSCAPS_MIPMAP              = 0x00400000;

   const crn_uint32_t DDSCAPS2_CUBEMAP            = 0x00000200;
   const crn_uint32_t DDSCAPS2_CUBEMAP_POSITIVEX  = 0x00000400;
   const crn_uint32_t DDSCAPS2_CUBEMAP_NEGATIVEX  = 0x00000800;

   const crn_uint32_t DDSCAPS2_CUBEMAP_POSITIVEY  = 0x00001000;
   const crn_uint32_t DDSCAPS2_CUBEMAP_NEGATIVEY  = 0x00002000;
   const crn_uint32_t DDSCAPS2_CUBEMAP_POSITIVEZ  = 0x00004000;
   const crn_uint32_t DDSCAPS2_CUBEMAP_NEGATIVEZ  = 0x00008000;

   const crn_uint32_t DDSCAPS2_VOLUME             = 0x00200000;

} // namespace crnlib

#endif // CRNLIB_DDS_DEFS_H
