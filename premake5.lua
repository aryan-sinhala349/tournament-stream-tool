include "./vendor/premake/customization/target.lua"

workspace "Tournament Stream Tool"
    architecture "x86_64"
    startproject "Tournament Stream Tool Backend"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

    flags
    {
        "MultiProcessorCompile"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
    include "vendor/premake"
group ""

group "Core"
    include "Tournament Stream Tool Backend"
group ""
