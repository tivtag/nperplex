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
      links { "pthread", "glfw", "GLEW" }
      buildoptions { "-std=c++11", "-pthread" }         
      linkoptions { "-L/usr/lib", "-L/usr/lib/x86_64-linux-gnu" }
         
   -- Libs
   if os.is("windows") then
      configuration "Release*"
         libdirs  { "extlibs/boost/stage/lib", "extlibs/bin/win32/release" }
                     
      configuration "Debug*"
         libdirs  { "extlibs/boost/stage/lib", "extlibs/bin/win32/debug" }
   else
   end

   project "nperplex"
      kind "StaticLib"
               
      files {
         "src/Audio/**.cpp",
         "src/Graphic/**.cpp*",
         "src/System/**.cpp",
         "src/Window/**.cpp",
         
         "include/Npe/Audio/**.hpp",
         "include/Npe/Graphic/**.hpp*",
         "include/Npe/System/**.hpp",
         "include/Npe/System/**.inl",
         "include/Npe/Window/**.hpp",
         "include/Npe/Math/**.hpp",
         "include/Npe/Math/**.inl"
      }

      includedirs  { "include", "extlibs/boost", "extlibs/include/" }     
      links {}
      targetdir "bin/lib"
      
      configuration "ReleaseLib"
         targetsuffix "-lib"

      configuration "DebugLib"
         targetsuffix "-lib-d"

   project "nperplex.example.quick"
      kind "ConsoleApp"
      files {
         "examples/quick/main.cpp"
      }
      
      libdirs      { "bin/lib" }
      includedirs  { "include", "extlibs/boost" }
      buildoptions {}

      configuration "Release*"
         links { "nperplex", "nperplex-lib" }
         targetdir "bin/examples/release"

      configuration "Debug*"
         links { "nperplex", "nperplex-lib-d" }
         targetdir "bin/examples/debug"
                
