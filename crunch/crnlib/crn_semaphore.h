// File: crn_semaphore.h
// See Copyright Notice and license at the end of inc/crnlib.h
#pragma once

namespace crnlib
{
   class semaphore
   {
      CRNLIB_NO_COPY_OR_ASSIGNMENT_OP(semaphore);
      
   public:
      semaphore(int32_t initialCount = 0, int32_t maximumCount = 1, const char* pName = NULL);
      ~semaphore();

      inline void *get_handle(void) const { return m_handle; }   

      void release(int32_t releaseCount = 1, int32_t *pPreviousCount = NULL);

      bool wait(uint32_t milliseconds = UINT32_MAX);

   private:   
      void *m_handle;
   };

} // namespace crnlib
