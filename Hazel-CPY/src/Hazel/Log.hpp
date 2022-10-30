#pragma once


#include <memory>
#include "Core.hpp"
#include "spdlog/spdlog.h"

// CORE ENGINE LOG MACROS 
#define LOG_ENGINE_ERROR(...) ::Hazel::Log::getCoreLogger()->error(__VA_ARGS__)    // ERROR ENGINE SIDE MACRO DEFINITION 
#define LOG_ENGINE_WARN(...)  ::Hazel::Log::getCoreLogger()->warn(__VA_ARGS__)     // WARN ENGINE SIDE MACRO DEFINITION 
#define LOG_ENGINE_INFO(...)  ::Hazel::Log::getCoreLogger()->info(__VA_ARGS__)     // INFO ENGINE SIDE MACRO DEFINITION 
#define LOG_ENGINE_TRACE(...) ::Hazel::Log::getCoreLogger()->trace(__VA_ARGS__)    // TRACE ENGINE SIDE MACRO DEFINITION 
#define LOG_ENGINE_FATAL(...) ::Hazel::Log::getCoreLogger()->fatal(__VA_ARGS__)    // FATAL ENGINE SIDE MACRO DEFINITION 

// CORE CLIENT LOG MACROS 
#define LOG_CLIENT_ERROR(...) ::Hazel::Log::getClientLogger()->error(__VA_ARGS__)  // ERROR ENGINE SIDE MACRO DEFINITION 
#define LOG_CLIENT_WARN(...)  ::Hazel::Log::getClientLogger()->warn(__VA_ARGS__)   // WARN ENGINE SIDE MACRO DEFINITION 
#define LOG_CLIENT_INFO(...)  ::Hazel::Log::getClientLogger()->info(__VA_ARGS__)   // INFO ENGINE SIDE MACRO DEFINITION 
#define LOG_CLIENT_TRACE(...) ::Hazel::Log::getClientLogger()->trace(__VA_ARGS__)  // TRACE ENGINE SIDE MACRO DEFINITION 
#define LOG_CLIENT_FATAL(...) ::Hazel::Log::getClientLogger()->fatal(__VA_ARGS__)  // FATAL ENGINE SIDE MACRO DEFINITION 
 
namespace Hazel
{
	class HAZEL_API Log
	{
	private:
		static std::shared_ptr<spdlog::logger> coreLogger;
		static std::shared_ptr<spdlog::logger> clientLogger;

	public: 
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return clientLogger; }
	};

}