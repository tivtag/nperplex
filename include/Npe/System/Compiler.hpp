#pragma once

#define NPE_COMPILER_MSVC 1
#define NPE_COMPILER_GCC 2

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
#    endif
#else
#   pragma error "Unknown compiler. See Compiler.hpp!"
#endif

