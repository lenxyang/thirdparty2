// File: crn_rand.h
// See Copyright Notice and license at the end of inc/crnlib.h
#pragma once 

namespace crnlib
{
   class kiss99
   {
   public:
      kiss99();
            
      void seed(uint32_t i, uint32_t j, uint32_t k);
            
      inline uint32_t next();
      
   private:
      uint32_t x;
      uint32_t y;
      uint32_t z;
      uint32_t c;
   };
      
   class well512
   {
   public:
      well512();
      
      enum { cStateSize = 16 };
      void seed(uint32_t seed[cStateSize]);
      void seed(uint32_t seed);
      void seed(uint32_t seed1, uint32_t seed2, uint32_t seed3);
            
      inline uint32_t next();
   
   private:      
      uint32_t m_state[cStateSize];
      uint32_t m_index;
   };
   
   class ranctx 
   { 
   public:
      ranctx() { seed(0xDE149737); }
            
      void seed(uint32_t seed);
      
      inline uint32_t next();
   
   private:
      uint32_t a; 
      uint32_t b; 
      uint32_t c; 
      uint32_t d; 
   };
   
   class random
   {
   public:
      random();
      random(uint32_t i);
      
      void seed(uint32_t i);
      void seed(uint32_t i1, uint32_t i2, uint32_t i3);
            
      uint32_t urand32();
      
      // "Fast" variant uses no multiplies.
      uint32_t fast_urand32();
      
      uint32_t bit();
      
      // Returns random between [0, 1)
      double drand(double l, double h);
      
      float frand(float l, float h);
      
      // Returns random between [l, h)
      int irand(int l, int h);
                  
      double gaussian(double mean, double stddev);
      
      void test();

   private:
      ranctx m_ranctx;
      kiss99 m_kiss99;
      well512 m_well512;
   };
   
   // Simpler, minimal state PRNG
   class fast_random
   {
   public:
      fast_random();
      fast_random(uint32_t i);
      fast_random(const fast_random& other);
      fast_random& operator=(const fast_random& other);
            
      void seed(uint32_t i);
      
      uint32_t urand32();
      
      int irand(int l, int h);
      
      double drand(double l, double h);

      float frand(float l, float h);
      
   private:      
      uint32_t jsr;
      uint32_t jcong;
   };

} // namespace crnlib
