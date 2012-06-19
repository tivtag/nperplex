#include <Npe/Window/Window.hpp>
#include <Npe/System/Log.hpp>

bool npe::Window::create(const npe::VideoMode& mode, const bool fullscreen)
{
   if(!impl.create(mode, fullscreen))
   {
      NPE_ERROR << "Could not create window (" << mode.size.x << "x" << mode.size.y << (fullscreen ? " @ fullscreen)" : ")");
      return false;
   }

   return false;
}
