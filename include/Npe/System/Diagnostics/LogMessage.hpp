#pragma once

#include "LogSource.hpp"

namespace npe
{
   /*
      Class: LogMessage

      A completed log message that is ready to be send off to <ILogListener>s.
   */
   struct LogMessage : public npe::LogSource
   {
      LogMessage(const std::string& _text, const LogLevel::Enum _level, const std::string& _fileName, const std::string& _funcName, const int _line)
         : text(_text), LogSource(_level, _fileName, _funcName, _line)
      {
      }

      const std::string& text;
   };
}
