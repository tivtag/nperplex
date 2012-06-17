#pragma once

#include <boost/noncopyable.hpp>
#include <Npe/Graphics/OpenGL.hpp>

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

         bool create(const int width, const int height, const bool fullscreen);
      };
   }
}

#endif
