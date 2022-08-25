
workspace "EntityComponentSystem"
    architecture "x86_64"
    configurations {"Debug", "Release"}
    filter { "configurations:Debug" }
    symbols "On"

    filter { "configurations:Release" }
    optimize "On"

    flags
	{
		"MultiProcessorCompile"
	}

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "ECS"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"

    files 
    {
        "src/*.h",
        "src/*.cpp",
        "components/*.h",
        "components/*.cpp",
    }

    includedirs
    {
        "src",
        "src/components",
        "entt",
    }

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("obj/" .. outputdir .. "/%{prj.name}")
