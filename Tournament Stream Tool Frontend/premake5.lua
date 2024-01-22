project "Tournament Stream Tool Frontend"
    kind "ConsoleApp"
    language "C#"
    dotnetframework "4.8"

    targetdir("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "src/**.cs"
    }

    links
    {
        "Tournament Stream Tool Backend"
    }

    prebuildcommands
    {
        ("{COPY} \"%{wks.location}/bin/" .. outputdir .. "/Tournament Stream Tool Backend/Tournament Stream Tool Backend.dll\" \"%{wks.location}/bin/" .. outputdir .. "/%{prj.name}/\"")
    }

    filter "configurations:Debug"
		optimize "Off"
		symbols "Default"

	filter "configurations:Release"
		optimize "On"
		symbols "Default"

	filter "configurations:Dist"
		optimize "Full"
		symbols "Off"
