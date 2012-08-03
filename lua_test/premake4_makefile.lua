if not _PREMAKE_VERSION then
   os.execute('premake4 --file=premake4_makefile.lua clean')
   os.execute('premake4 --file=premake4_makefile.lua gmake')
   return
end

solution "lua_test"
   configurations { "Debug", "Release" }
 
   -- A project defines one build target
   project "lua_test"
      kind "ConsoleApp"
      language "C"
      location ( "obj" )
      targetdir ( "bin" )
      libdirs { "/usr/lib" }
      links { "lua" }
      includedirs { "../lib/include", "usr/include" }

      files { "src/**.h", "src/**.c" }
 
      configuration "Debug"
         defines { "DEBUG" }
         flags { "Symbols", "ExtraWarnings" }
 
      configuration "Release"
         defines { "NDEBUG" }
         flags { "Optimize" }     
