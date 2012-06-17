#pragma once

#include <Npe/System/Platform.hpp>

/*
   Defines: NPE_OPENGL

   NPE_OPENGL_ES2 - OpenGL for Embedded Systems 2.0, used on Android or on Desktop for testing/dev.
   NPE_OPENGL_EW  - Desktop OpenGL based on OpenGL Extension Wrangler
*/

#define NPE_OPENGL_ES2 1
#define NPE_OPENGL_EW 2

#if NPE_OPENGL == NPE_OPENGL_ES2
#  include <GLES2/gl2.h>
#  include <GLES2/gl2ext.h>
#  include <GLES2/gl2extimg.h>
#elif NPE_OPENGL == NPE_OPENGL_EW
#  include <GL/glew.h>
#else
#  error NPE_OPENGL not set to supported value. See OpenGL.hpp
#endif
