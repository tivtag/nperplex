#pragma once

#include <boost/noncopyable.hpp>
#include "LogLevel.hpp"

namespace npe
{
   struct LogSource : private boost::noncopyable
   {
      LogSource(const LogLevel::Enum _level, const std::string& _fileName, const std::string& _funcName, const int _line)
         : level(_level), fileName(_fileName), funcName(_funcName), line(_line)
      {
      }

      const LogLevel::Enum level;
      const std::string& fileName; 
      const std::string& funcName;
      const int line;
   };
}
