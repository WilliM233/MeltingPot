#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace MeltingPot {
	class MELTINGPOT_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

// Core log macros
#define MP_CORE_TRACE(...)     ::MeltingPot::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MP_CORE_INFO(...)      ::MeltingPot::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MP_CORE_WARN(...)      ::MeltingPot::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MP_CORE_ERROR(...)     ::MeltingPot::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MP_CORE_FATAL(...)     ::MeltingPot::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define MP_TRACE(...)          ::MeltingPot::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MP_INFO(...)           ::MeltingPot::Log::GetClientLogger()->info(__VA_ARGS__)
#define MP_WARN(...)           ::MeltingPot::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MP_ERROR(...)          ::MeltingPot::Log::GetClientLogger()->error(__VA_ARGS__)
#define MP_FATAL(...)          ::MeltingPot::Log::GetClientLogger()->fatal(__VA_ARGS__)