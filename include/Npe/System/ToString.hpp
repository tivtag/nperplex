#pragma once

#include <string>
#include <boost/lexical_cast.hpp>

namespace npe
{
   /*
      Function: to_str

      Converts a value into a string. Specialize to support user-defined types.
   */
   template<typename T>
   inline const std::string to_str(const T& value)
   {
      return boost::lexical_cast<std::string>(value);
   }

   template<>
   inline const std::string to_str<std::string>(const std::string& str)
   {
      return str;
   }
}

