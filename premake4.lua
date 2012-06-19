usethreads = true
useGLES2   = false
useRTTI    = true

function configexample()
   libdirs      { "bin/lib" }
   includedirs  { "include", "extlibs/boost", "extlibs/include/" }
   buildoptions {}

   configuration "Release*"
      links { "nperplex", "nperplex-lib" }
      targetdir "bin/examples/release"

   configuration "Debug*"
      links { "nperplex", "nperplex-lib-d" }
      targetdir "bin/examples/debug"
end 

solution "nperplex"
   language "C++"
   platforms { "x32", "x64" }
   flags     {"ExtraWarnings"}
   
   configurations {"ReleaseLib", "DebugLib"}
   location "project/"
           
   configuration "Release*"
      defines   {"NDEBUG"}
      flags     {"Optimize"}
      
   configuration "Debug*"     
      defines   {"_DEBUG", "DEBUG"}
      flags     {"Symbols"}
   
   -- Visual Studio 
   configuration {"Release*", "vs*"}
      buildoptions {"/GS-", "/wD9025"} -- Disable Buffer Security Check in VS release builds
      
   -- GCC 4.7
   configuration { "gmake" }
      buildoptions { "-std=c++11" }      
      if usethreads then
         links { "pthread" }
         buildoptions { "-pthread" }
      end
      buildoptions { "-std=c++11" }         
      linkoptions { "-L/usr/lib", "-L/usr/lib/x86_64-linux-gnu" }
         
   -- Libs
   if os.is("windows") then
      configuration "Release*"
         libdirs  { "extlibs/boost/stage/lib", "extlibs/bin/win32/release" }
                     
      configuration "Debug*"
         libdirs  { "extlibs/boost/stage/lib", "extlibs/bin/win32/debug" }
      defines { "NPE_PLATFORM=NPE_PLATFORM_WINDOWS"}
   else
      defines { "NPE_PLATFORM=NPE_PLATFORM_LINUX"}
   end
   
   -- Defines
   if not useRTTI then
      flags { "NoRTTI" }
      defines { "BOOST_NO_RTTI", "BOOST_NO_TYPEID" }
   end

   if usethreads then
      defines { "NPE_USE_THREADS" }
   end
   
   if useGLES2 then
      defines { "NPE_OPENGL=NPE_OPENGL_ES2" }
      links { "EGL", "GLESv2" }
   else
      defines { "NPE_OPENGL=NPE_OPENGL_EW" }
      links { "glfw", "GLEW" }

      configuration "*vs"
         links { "opengl32"}

      configuration "gmake"
         links { "GL" }
   end

   project "nperplex"
      kind "StaticLib"
               
      files {
         "src/Audio/**.cpp",
         "src/Graphics/**.cpp",
         "src/System/**.cpp",
         "src/Window/**.cpp",
         
         "include/Npe/Audio/**.hpp",
         "include/Npe/Graphics/**.hpp",
         "include/Npe/System/**.hpp",
         "include/Npe/System/**.inl",
         "include/Npe/Window/**.hpp",
         "include/Npe/Math/**.hpp",
         "include/Npe/Math/**.inl"
      }

      includedirs  { "include", "extlibs/boost", "extlibs/include/" }
      targetdir "bin/lib"
      
      configuration "ReleaseLib"
         targetsuffix "-lib"

      configuration "DebugLib"
         targetsuffix "-lib-d"
         
   project "nperplex.example.quick"
      kind "ConsoleApp"  
      files { "examples/quick/main.cpp" }      
      configexample()     

      
   project "nperplex.example.window"
      kind "ConsoleApp"      
      files { "examples/window/main.cpp" }      
      configexample()
      
