#pragma once

#include <iostream>
#include "ILogListener.hpp"

namespace npe
{
   /*
      Class: StdLogListener

      Implements an <ILogListener> that writes <LogLevel::Info> and <LogLevel::Debug> messages to std:cout 
      and all other messages to std::cerr.
   */
   struct StdLogListener : public npe::ILogListener
   {
      virtual void write(const npe::LogMessage& message)
      {
         const npe::LogSource& source = message.source;
         const bool evil = message.level != npe::LogLevel::Info && message.level != npe::LogLevel::Debug;
         std::ostream& stream = evil ? std::cerr : std::cout;
         
         stream << npe::to_str(message.level);
         
         if( evil )
         {
            stream << " | " << source.fileName << " " << source.funcName << " at line " << source.line;
         }

         stream << ": "  << message.text;
         stream.flush();
      }
   };
}
