#pragma once

#include "Compiler.hpp"

#ifdef NPE_COMPILER_CPP11
#   include <memory> // std::shared_ptr, std::make_shared, ..
#else
#   define nullptr 0
#   include <boost/shared_ptr.hpp>
#   include <boost/make_shared.hpp>

   namespace std
   {
      using boost::shared_ptr;
      using boost::make_shared;
   }
#endif
