#include "Log.hpp"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Hazel
{
	std::shared_ptr<spdlog::logger> Log::coreLogger;
	std::shared_ptr<spdlog::logger> Log::clientLogger;

	void Log::Init()
	{

		spdlog::set_pattern("%^[%T] %n: %v%$");
		coreLogger = spdlog::stdout_color_mt("HAZEL");	// One log console for the engine
		coreLogger->set_level(spdlog::level::trace);	// Trace everything

		clientLogger = spdlog::stdout_color_mt("APP");	// One log console for the app 
		clientLogger->set_level(spdlog::level::trace);

	}
}