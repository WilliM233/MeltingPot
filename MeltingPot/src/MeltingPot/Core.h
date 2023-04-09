#pragma once

#ifdef MP_PLATFORM_WINDOWS
	#ifdef MP_BUILD_DLL
		#define MELTINGPOT_API __declspec(dllexport)
	#else
		#define MELTINGPOT_API __declspec(dllimport)
	#endif // MP_BUILD_DLL
#else
	#error MeltingPot only supports Windows!
#endif // MP_PLATFORM_WINDOWS

#define BIT(x) (1 << x)
