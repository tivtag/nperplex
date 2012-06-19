#include <Npe/Window/GLFW/WindowImpl.hpp>

#if NPE_OPENGL == NPE_OPENGL_EW
#  include <Npe/System/Log.hpp>
#  include <GL/glfw.h>

   npe::detail::WindowImpl:: ~WindowImpl()
   {
      glfwCloseWindow();

      // ToDo: Move to own class to manage lifetime
      glfwTerminate();
   }

   bool npe::detail::WindowImpl::create(const npe::VideoMode& mode, const bool fullscreen)
   { 
      if( !glfwInit() )
      {
         NPE_ERROR << "Could not initialize GLFW." << npe::endl;
         return false;
      }
      
      glfwCloseWindow();

      if( !glfwOpenWindow(mode.size.x, mode.size.y, 8, 8, 8, 8, 0, 0, fullscreen ? GLFW_FULLSCREEN : GLFW_WINDOW) )
      {
         NPE_ERROR << "Could not open GLFW window." << npe::endl;
         return false;
      }
      
      return true;
   }

#endif
