#include <Npe/Window/Window.hpp>
#include <Npe/System/Log.hpp>

bool npe::Window::create(const int width, const int height, const bool fullscreen)
{
   if(!impl.create(width, height, fullscreen))
   {
      NPE_ERROR << "Could not create window (" << width << "x" << height << (fullscreen ? " @ fullscreen)" : ")");
      return false;
   }

   return false;
}