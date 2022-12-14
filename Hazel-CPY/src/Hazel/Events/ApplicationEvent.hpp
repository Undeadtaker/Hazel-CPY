#pragma once

#include "Event.hpp"

namespace Hazel
{
	class HAZEL_API WindowResizeEvent : public Event
	{

	private:
		unsigned int window_Width, window_Height;

	public:
		WindowResizeEvent(unsigned int width, unsigned int height) 
			: window_Width(width), window_Height(height) {};

		inline unsigned int getWidth() const { return window_Width; }
		inline unsigned int getHeight() const { return window_Height; }

		std::string toString() override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent " << window_Width << ", " << window_Height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);

	};

	class HAZEL_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {};
		
		EVENT_CLASS_TYPE(WindowClose);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);
	};

	class HAZEL_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() {};

		EVENT_CLASS_TYPE(AppTick);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);
	};

	class HAZEL_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() {};

		EVENT_CLASS_TYPE(AppUpdate);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);
	};

	class HAZEL_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() {};

		EVENT_CLASS_TYPE(AppRender);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);
	};

}