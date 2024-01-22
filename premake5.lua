include "./vendor/premake/customization/target.lua"
include "./Dependencies.lua"

workspace "Tournament Stream Tool"
    architecture "x86_64"
    startproject "Tournament Stream Tool Frontend"

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

include "Tournament Stream Tool Frontend"
