#pragma once

/*
   Defines: NPE_PLATFORM

   Target platform of the compiled application. 

   NPE_PLATFORM_WINDOWS
   NPE_PLATFORM_LINUX
   NPE_PLATFORM_ANDROID
*/

#define NPE_PLATFORM_WINDOWS 1
#define NPE_PLATFORM_LINUX   2
#define NPE_PLATFORM_ANDROID 3

#ifndef NPE_PLATFORM
#   error Unknown platform. Define NPE_PLATFORM to one of the values in Platform.hpp.
#endif
