// File: crn_win32_threading.h
// See Copyright Notice and license at the end of inc/crnlib.h
#pragma once

namespace crnlib
{
   // g_number_of_processors defaults to 1. Will be higher on multicore machines.
   extern uint g_number_of_processors;

   int32_t interlocked_compare_exchange32(int32_t volatile *Destination, int32_t Exchange, int32_t Comperand);
   int32_t interlocked_increment32(int32_t volatile *lpAddend);
   int32_t interlocked_exchange_add32(int32_t volatile *Addend, int32_t Value);
   int32_t interlocked_exchange32(int32_t volatile *Target, int32_t Value);
   uint32_t get_current_thread_id();

} // namespace crnlib


