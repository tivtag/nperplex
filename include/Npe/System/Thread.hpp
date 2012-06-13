#pragma once

/*
   Define: NPE_USE_THREADS
   
   Build flag that states whether the system should be build with multi-threading support.
   Enabling this requires additional dependencies depending on your compiler and platform.
*/

#if NPE_USE_THREADS
#  if NPE_COMPILER_SUPPORTS_THREADS
#     include <thread>
#     include <mutex>
#  else
#     include <boost/thread.hpp>
#     include <boost/thread/mutex.hpp>

      namespace std
      {
         using boost::thread;
         using boost::mutex;
         using boost::mutex::scoped_lock;
      }

#  endif
#endif
