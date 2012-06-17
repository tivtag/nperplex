#pragma once

#include <Npe/System/Platform.hpp>

#if NPE_PLATFORM == NPE_PLATFORM_ANDROID || defined(NPE_USE_GLES2_EMULATION)
#  include "EGL/Window.hpp"
#else
#  include "GLFW/Window.hpp"
#endif

namespace npe
{
}

