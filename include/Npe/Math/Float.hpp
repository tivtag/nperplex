#pragma once

#include <cmath>
#include <cassert>
#include <limits>
#include <boost/math/special_functions/next.hpp>

namespace npe
{
   /*
      Topic: Floating Point Arithmetic

      See:
         http://www.infogoaround.org/JBook/FloatingComparison.pdf
         http://realtimecollisiondetection.net/blog/?p=89
   */

   /*
      Func: error_abs

      Calculates the absolute error between two floating-point values.
   */
   template<typename T>
   T error_abs(const T a, const T b)
   {
      return std::abs(a - b);
   }

   /*
      Func: error_rel

      Calculates the relative error between two floating-point values.
   */
   template<typename T>
   T error_rel(const T a, const T b)
   {
      return std::abs(a - b) / std::abs(a);
   }

   /*
      Func: close

      Combined relative and absolute tolerance comparision of two floating-point values with equal tolerances.
   */
   template<typename T>
   bool close(const T a, const T b, const T tolerance = std::numeric_limits<T>::epsilon() )
   {
      return std::abs(a - b) <= tolerance * std::max(1.0f, std::max(std::abs(a), std::abs(b)));
   }
     
   /*
      Func: close

      Combined relative and absolute tolerance comparision of two floating-point values with seperate tolerances.
   */
   template<typename T>
   bool close(const T a, const T b, const T absoluteTolerance, const T relativeTolerance)
   {
      return std::abs(a - b) <= std::max(absoluteTolerance, relativeTolerance * std::max(std::abs(a), std::abs(b)));
   }

   /*
      Func: close_abs

      Absolute tolerance comparison of two floating-point values.

      Advantages:    fast and simple
      Disadvantages: Fails when input values are large.
   */
   template<typename T>
   bool close_abs(const T a, const T b, const T tolerance = std::numeric_limits<T>::epsilon() )
   {
      return std::abs(a - b) <= tolerance;
   }

   /*
      Func: close_rel

      Relative tolerance comparison of two floating-point values

      Author: 
         jchavez (http://realtimecollisiondetection.net/blog/?p=89)
   */
   bool close_rel(const float a, const float b, const float epsilon = std::numeric_limits<float>::epsilon())
   {
      // assume small positive epsilon
      assert(epsilon >= 0.0f && epsilon <= 1.0f);

      const float diff = std::abs(a - b);
      const float maxab = std::max(std::abs(a), std::abs(b));

      // if the multiply won't underflow then use a multiply
      if(maxab >= 1.0f)
      {
         // The error is measured as the percentage of the size of the larger number.
         // |a - b| < max(a, b) * eps
         return diff <= (epsilon * maxab);
      }
      // multiply could underflow so use a divide if non-zero denominator
      else if(maxab > 0.0f)
      {
         // correctly returns false on divide overflow
         // (inf < = epsilon is false), since overflow means the
         // relative difference is large and they are therefore not close
         return (diff / maxab) <= epsilon;
      }
      else
      {
         // both a and b are zero
         return false;
      }
   }

   /*
      Func: close_ulp

      Tolerance comparison of two floating-point values based on units of least precision.
   */
   template<typename T>
   bool close_ulp(const T a, const T b, const int maxUlps = 4)
   {
      const T ulps = std::abs(boost::math::float_distance<T>( a, b ));
      return ulps <= maxUlps;
   }
}
