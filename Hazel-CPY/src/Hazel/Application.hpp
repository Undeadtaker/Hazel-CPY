#pragma once

#include "Core.hpp"
#include "Events/Event.hpp"

namespace Hazel
{
	class HAZEL_API Application
	{
	public:

		// Constructors
		Application();
		virtual ~Application();

		// Functions
		void Run();
	};

	// THE FUNCTION IS DEFINED IN CLIENT AKA SANDBOXAPP.CPP
	Application* CreateApplication();

}

