#pragma once

#include <glm/gtx/std_based_type.hpp>

namespace npe
{
   struct VideoMode
   {
      VideoMode(const glm::size2 _size) : size(_size) { }

      const glm::size2 size;
   };
}

