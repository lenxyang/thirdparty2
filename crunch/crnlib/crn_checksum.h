// File: crn_checksum.h
#pragma once

namespace crnlib
{
   const uint cInitAdler32 = 1U;
   uint adler32(const void* pBuf, size_t buflen, uint adler32 = cInitAdler32);
   
   // crc16() intended for small buffers - doesn't use an acceleration table.
   const uint cInitCRC16 = 0;
   uint16_t crc16(const void* pBuf, size_t len, uint16_t crc = cInitCRC16);
   
}  // namespace crnlib
