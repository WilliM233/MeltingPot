workspace "MeltingPot"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	-- Include directories relative to root folder (solution directory)
	IncludeDir = {}
	IncludeDir["GLFW"] = "MeltingPot/vendor/GLFW/include"
	IncludeDir["Glad"] = "MeltingPot/vendor/Glad/include"
	IncludeDir["ImGui"] = "MeltingPot/vendor/imgui"
	IncludeDir["glm"] = "MeltingPot/vendor/glm"

	include "MeltingPot/vendor/GLFW"
	include "MeltingPot/vendor/Glad"
	include "MeltingPot/vendor/imgui"

	project "MeltingPot"
		location "MeltingPot"
		kind "StaticLib"
		language "C++"
		cppdialect "C++17"
		staticruntime "on"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

		pchheader "mppch.h"
		pchsource "MeltingPot/src/mppch.cpp"

		files
		{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp",
			"%{prj.name}/vendor/glm/glm/**.hpp",
			"%{prj.name}/vendor/glm/glm/**.inl"
		}

		defines
		{
			"_CRT_SECURE_NO_WARNINGS"
		}

		includedirs
		{
			"%{prj.name}/src",
			"%{prj.name}/vendor/spdlog/include",
			"%{IncludeDir.GLFW}",
			"%{IncludeDir.Glad}",
			"%{IncludeDir.ImGui}",
			"%{IncludeDir.glm}"
		}

		links
		{
			"GLFW",
			"Glad",
			"ImGui",
			"opengl32.lib"
		}

		filter "system:windows"
			systemversion "latest"

			defines
			{
				"MP_PLATFORM_WINDOWS",
				"MP_BUILD_DLL",
				"GLFW_INCLUDE_NONE"
			}

		filter "configurations:Debug"
			defines "MP_DEBUG"
			runtime "Debug"
			symbols "on"

		filter "configurations:Release"
			defines "MP_RELEASE"
			runtime "Release"
			optimize "on"

		filter "configurations:Dist"
			defines "MP_DIST"
			runtime "Release"
			optimize "on"	
			

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

		files
		{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp",
		}

		includedirs
		{
			"MeltingPot/vendor/spdlog/include",
			"MeltingPot/src",
			"MeltingPot/vendor",
			"%{IncludeDir.glm}"
		}

		links
		{
			"MeltingPot"
		}

		filter "system:windows"
			systemversion "latest"

			defines
			{
				"MP_PLATFORM_WINDOWS",
			}

		filter "configurations:Debug"
			defines "MP_DEBUG"
			runtime "Debug"
			symbols "on"

		filter "configurations:Release"
			defines "MP_RELEASE"
			runtime "Release"
			optimize "on"

		filter "configurations:Dist"
			defines "MP_DIST"
			runtime "Release"
			optimize "on"	