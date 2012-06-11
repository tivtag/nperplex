#pragma once

#include <iostream>
#include "ILogListener.hpp"

namespace npe
{
   struct StdLogListener : public npe::ILogListener
   {
      virtual void write(const npe::LogMessage& message)
      {  
         const bool evil = message.level == npe::LogLevel::Warn || message.level == npe::LogLevel::Error;
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
