#pragma once
#include <cmath>

namespace npe
{
   /* 
      Func: close_enough
      
      Determines whether the two floating-point values a and b are
      close enough together that they can be considered equal.
   */
   bool close_enough(const float a, const float b)
   {
      const float EPSILON = 1e-6f;
      return std::abs((a - b) / ((b == 0.0f) ? 1.0f : b)) < EPSILON;
   }
}
