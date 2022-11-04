workspace "Hazel-CPY"
	architecture "x64"
	location "Hazel-CPY"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-x64"

project "Hazel-CPY"
	
	location "Hazel-CPY"
	kind "SharedLib"
	language "C++"

	targetdir ("%{prj.name}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{prj.name}/bin-intermediaries/" .. outputdir .. "/%{prj.name}")

	pchheader "hzpzh.hpp"
	pchsource "%{prj.name}/src/hzpzh.cpp"

	files
	{
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include;"
	}

	filter "system:windows"
		cppdialect "C++17"	
		staticruntime "On"
		systemversion "10.0"


		defines
		{
			"HZ_PLATFORM_WINDOWS",
			"HZ_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "HZ_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "HZ_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "HZ_DIST"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("Hazel-CPY/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("Hazel-CPY/bin-intermediaries/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Hazel-CPY/vendor/spdlog/include",
		"Hazel-CPY/src"
	}

	links
	{
		"Hazel-CPY"
	}

	filter "system:windows"
		cppdialect "C++17"	
		staticruntime "On"
		systemversion "10.0"


		defines
		{
			"HZ_PLATFORM_WINDOWS"
		}


	filter "configurations:Debug"
		defines "HZ_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "HZ_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "HZ_DIST"
		optimize "On"