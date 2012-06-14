#pragma once

/*
   Defines: Compilers

      Lists supported compilers.

      NPE_COMPILER_MSVC - Microsoft Visual C++
      NPE_COMPILER_GCC  - GNU G++


   Define: NPE_COMPILER

      Specifies the current compiler. See <Compilers>.

   Define: NPE_COMPILER_VERSION
      
      Specifies the version of the compiler.
*/
#define NPE_COMPILER_MSVC 1
#define NPE_COMPILER_GCC 2

/*
   Define: NPE_COMPILER_CPP11

      States whether the compiler supports most of the CP11 feature-set.

   Define: NPE_COMPILER_SUPPORTS_THREADS

      States whether the compiler/stl implementation supports std::thread
      and companions natively.

      boost is used if not available natively. See <Thread.hpp>
*/

#if defined(_MSC_VER)
#   define NPE_COMPILER NPE_COMPILER_MSVC
#   define NPE_COMPILER_VERSION _MSC_VER

#   if _MSC_VER >= 1600
#      define NPE_COMPILER_CPP11
#   endif
#elif defined(__GNUC__)
#   define NPE_COMPILER NPE_COMPILER_GCC
#   define NPE_COMPILER_VERSION (__GNUC__ * 10000 \
                           + __GNUC_MINOR__ * 100 \
                           + __GNUC_PATCHLEVEL__)

#   if __cplusplus >= 201103L || __GXX_EXPERIMENTAL_CXX0X__ == 1
#      define NPE_COMPILER_CPP11
#      define NPE_COMPILER_SUPPORTS_THREADS // must link with pthread
#    endif
#else
#   pragma error "Unknown compiler. See Compiler.hpp!"
#endif

