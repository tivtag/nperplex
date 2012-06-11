#pragma once

#include <Npe/System/ToString.hpp>

namespace npe
{
   namespace LogLevel
   {
      /*
         Enum: LogLevel

         Enumerates various seriousness levels of log messages.

         Info  - Informative message
         Warn  - Non-disasterous warning
         Error - Possible recoverable error
         Fail  - Evil unrecoverable error
         Debug - Debug message. Filtered in Release builds by default.
      */
      enum Enum {
         Info  = 2 << 0,
         Warn  = 2 << 1,
         Error = 2 << 2,
         Fail  = 2 << 3,
         Debug = 2 << 4
      };
   }

   /*
      Function: to_str

      Specialized to convert <LogLevel> into a string.
   */
   template<>
   inline const std::string to_str<LogLevel::Enum>(const LogLevel::Enum& level)
   {
      switch(level)
      {
      case LogLevel::Info:
         return "Info";

      case LogLevel::Warn:
         return "Warn";
                  
      case LogLevel::Error:
         return "Error";
                  
      case LogLevel::Fail:
         return "Fail";

      case LogLevel::Debug:
         return "Debug";

      default:
         return "?";
      }
   }
}
