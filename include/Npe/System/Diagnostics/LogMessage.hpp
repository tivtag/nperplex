#pragma once

#include "LogLevel.hpp"
#include "LogSource.hpp"

namespace npe
{
   /*
      Class: LogMessage

      A completed log message that is ready to be send off to <ILogListener>s.
   */
   struct LogMessage : private boost::noncopyable
   {
      LogMessage(const npe::LogLevel::Enum _level, const std::string& _text, const npe::LogSource& _source)
         : level(_level), text(_text), source(_source)
      {
      }
 
      const npe::LogLevel::Enum level;
      const std::string& text;
      const npe::LogSource& source;
   };
}
