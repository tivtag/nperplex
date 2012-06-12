solution "nperplex"
   configurations {"ReleaseLib", "DebugLib"}
   platforms { "x32" }
   
   language "C++"
   flags    {"ExtraWarnings"}

   location "project/"
           
   configuration "Release*"
      defines   {"NDEBUG"}
      flags     {"Optimize"}
      
   configuration {"Release*", "vs*"}
      buildoptions {"/GS-", "/wD9025"} -- Disable Buffer Security Check in VS release builds
      
   configuration "Debug*"     
      defines   {"_DEBUG", "DEBUG"}
      flags     {"Symbols"}
              
   project "nperplex"
      kind "StaticLib"
   
      --configuration "*Lib"
      --  kind "StaticLib"
      --configuration "*DLL"
      --  kind "SharedLib"
            
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

      includedirs  { "include", "extlibs/boost" }     
      links {}
      targetdir "bin/lib"

      configuration "ReleaseLib"
         targetsuffix "-win32"

      configuration "DebugLib"
         targetsuffix "-win32-d"

   project "nperplex.example.quick"
      kind "ConsoleApp"
      files {
         "examples/quick/main.cpp"
      }
      
      libdirs      { "bin/lib" }
      includedirs  { "include", "extlibs/boost" }
      buildoptions {}

      configuration "Release*"
         links { "nperplex", "nperplex-win32" }
         targetdir "bin/examples/release"

      configuration "Debug*"
         links { "nperplex", "nperplex-win32-d" }
         targetdir "bin/examples/debug"
                