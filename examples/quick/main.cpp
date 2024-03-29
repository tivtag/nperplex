#include <iostream>

#include <Npe/Math/Float.hpp>
#include <Npe/Window/Window.hpp>
#include <Npe/System/Log.hpp>
#include <Npe/System/Thread.hpp>

using namespace npe;

int main()
{
   NPE_INFO 
      << "Compiler=" 
      << NPE_COMPILER
      << " Compiler Version="
      << NPE_COMPILER_VERSION

   #ifdef NPE_COMPILER_CPP11
      << " Supports C++11!"
   #endif

   #ifdef NPE_USE_THREADS
   #   ifdef NPE_COMPILER_SUPPORTS_THREADS
      << " Using STL threads"
   #   else
      << " Using boost threads"
   #   endif 
   #endif
      << npe::endl;
   
   static std::mutex my_mutex;

   float e = std::numeric_limits<float>::epsilon();
   float a = 0.5f;
   float b = 0.5f + e;

   std::cout.precision(30);
   std::cout << "a: " << a << std::endl;
   std::cout << "b: " << b << std::endl;
   std::cout << "e: " << e << std::endl << std::endl;

   std::cout << "abs error: " << npe::error_abs(a, b) << std::endl;
   std::cout << "rel error: " << npe::error_rel(a, b) << std::endl << std::endl;

   std::cout << "abs+rel: " << npe::close(a, b, e) << std::endl;
   std::cout << "abs:     " << npe::close_abs(a, b, e) << std::endl;
   std::cout << "rel:     " << npe::close_rel(a, b, e) << std::endl;
   std::cout << "ulp:     " << npe::close_ulp(a, b) << std::endl;
   
   std::cin.ignore();
   return 0;
}
