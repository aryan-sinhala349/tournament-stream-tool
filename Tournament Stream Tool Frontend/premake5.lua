project "Tournament Stream Tool Frontend"
    kind "WindowedApp"
    language "C#"
    dotnetframework "4.8"
    namespace "TST"

    targetdir("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "src/**.cs",
        "src/**.xaml"
    }

    links
    {
        "Tournament Stream Tool Backend",
        "PresentationCore",
        "PresentationFramework",
        "System.Xaml",
        "WindowsBase",
        "System"
    }

    flags
    {
        "WPF"
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
