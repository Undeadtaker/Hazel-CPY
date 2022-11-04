#include "hzpzh.hpp"
#include "Application.hpp"

#include "Events/ApplicationEvent.hpp"
#include "Log.hpp"

namespace Hazel
{
	Application::Application() {};
	Application::~Application() {};

	void Application::Run() 
	{ 
		WindowResizeEvent e(1280, 720);
		LOG_ENGINE_TRACE(e.toString());

		while (true);
	}
}
