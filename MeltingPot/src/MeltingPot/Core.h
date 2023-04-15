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

#ifdef MP_ENABLE_ASSERTS
	#define MP_ASSERT(x, ...) { if(!(x)) { MP_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define MP_CORE_ASSERT(x, ...) {if(!(x)) {MP_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define MP_ASSERT(x, ...)
	#define MP_CORE_ASSERT(x, ...)
#endif // MP_ENABLE_ASSERTS

#define BIT(x) (1 << x)
