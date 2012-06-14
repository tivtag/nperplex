#pragma once

#include "BuildOptions.hpp"
#include "Compiler.hpp"

#ifdef NPE_USE_THREADS
#  ifdef NPE_COMPILER_SUPPORTS_THREADS
#     include <thread>
#     include <mutex>
#  else
#     include <boost/thread.hpp>
#     include <boost/thread/mutex.hpp>

      namespace std
      {
         using boost::thread;
         using boost::mutex;
         using boost::lock_guard;
      }

#  endif
#endif

