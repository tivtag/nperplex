#pragma once

#include <boost/noncopyable.hpp>
#include "LogLevel.hpp"

namespace npe
{
   /*
      Class: LogMessage

      A completed log message that is ready to be send off to <ILogListener>s.
   */
   struct LogMessage : private boost::noncopyable
   {
      LogMessage(const std::string& _text, const LogLevel::Enum _level, const std::string& _fileName, const std::string& _funcName, const int _line)
         : text(_text), level(_level), fileName(_fileName), funcName(_funcName), line(_line)
      {
      }

      const std::string& text;
      const LogLevel::Enum level;
      const std::string& fileName; 
      const std::string& funcName;
      const int line;
   };
}
