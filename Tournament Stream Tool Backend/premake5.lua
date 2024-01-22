project "Tournament Stream Tool Backend"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    staticruntime "on"

    targetdir("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "src/**.h",
        "src/**.cpp",
        "vendor/rapidjson/include/**.h"
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS"
    }

    includedirs
    {
        "src",
        "%{IncludeDir.rapidjson}"
    }

    links
    {

    }

    filter "options:target=windows"
        systemversion "latest"

        defines
        {
            "WIN32_LEAN_AND_MEAN",
            "NOMINMAX"
        }

    filter "configurations:Debug"
        defines
        {
            "AL_DEBUG"
        }

        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines
        {
            "AL_RELEASE"
        }

        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "AL_DIST"
        runtime "Release"
        optimize "on"
        symbols "off"