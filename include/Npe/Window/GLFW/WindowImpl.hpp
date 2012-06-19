#pragma once

#include <boost/noncopyable.hpp>
#include <Npe/Graphics/OpenGL.hpp>
#include <Npe/Window/VideoMode.hpp>

#if NPE_OPENGL == NPE_OPENGL_EW

namespace npe
{
   namespace detail
   {
      class WindowImpl : private boost::noncopyable
      {
      public:
         WindowImpl() {}
         ~WindowImpl();

         bool create(const npe::VideoMode& mode, const bool fullscreen);
      };
   }
}

#endif
