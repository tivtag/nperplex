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
         const bool evil = message.level != npe::LogLevel::Info && message.level != npe::LogLevel::Debug;
         std::ostream& stream = evil ? std::cerr : std::cout;

         stream << npe::to_str(message.level);
         
         if( evil )
         {
            stream << " | " << message.fileName << " " << message.funcName << " at line " << message.line;
         }
         
         stream << ": "  << message.text;
         stream.flush();
      }
   };
}
