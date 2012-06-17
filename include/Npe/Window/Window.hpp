#pragma once

#include <Npe/Graphics/OpenGL.hpp>

#if NPE_OPENGL == NPE_OPENGL_ES2
#  include "EGL/WindowImpl.hpp"
#else
#  include "GLFW/WindowImpl.hpp"
#endif

namespace npe
{
   class Window
   {
   public:
      bool create(const int width, const int height, const bool fullscreen);

   private:
      detail::WindowImpl impl;
   };
}

