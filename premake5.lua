
workspace "ExCS"
    architecture "x86_64"
    configurations {"Debug", "Release"}
    filter { "configurations:Debug" }
        symbols "On"
    
    filter { "configurations:Release" }
        optimize "On"
    
    -- kind "ConsoleApp"
    -- language "C++"
    -- cppdialect "C++20"

    flags
	{
		"MultiProcessorCompile"
	}

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    -- files 
    -- {
    --     "src/*.h",
    --     "src/*.cpp",
    --     "components/*.h",
    --     "components/*.cpp",
    -- }

    -- includedirs
    -- {
    --     "src",
    --     "src/components",
    --     "entt",
    -- }

    -- targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    -- objdir ("obj/" .. outputdir .. "/%{prj.name}")


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
        "ecs",
        "entt",
        "utils",
    }

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("obj/" .. outputdir .. "/%{prj.name}")
