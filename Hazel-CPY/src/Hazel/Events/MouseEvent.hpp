#pragma once

#include "Event.hpp"

namespace Hazel
{
	class HAZEL_API MouseMovedEvent : public Event
	{
	private:
		float mouse_X, mouse_Y;

	public:
		MouseMovedEvent(float x, float y) : mouse_X(x), mouse_Y(y) {};

		inline float getX() const { return mouse_X; }
		inline float getY() const { return mouse_Y; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent " << mouse_X << ", " << mouse_Y;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved);
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);

	};

	class HAZEL_API MouseScrolledEvent : public Event
	{
	private:
		float mouse_XOffset, mouse_YOffset;

	public:
		MouseMovedEvent(float x, float y) : mouse_XOffset(x), mouse_YOffset(y) {};

		inline float getXOffset() const { return mouse_XOffset; }
		inline float getYOffset() const { return mouse_YOffset; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent " << mouse_XOffset << ", " << mouse_YOffset;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled);
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);
	};

	class HAZEL_API MouseButtonEvent : public Event
	{
	protected:
		int button;
		MouseButtonEvent(int button) : button(button) {};

	public:
		inline int getMouseButton() const { return button; }
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);
	};

	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {};

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent " << button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed);
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {};

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent " << button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleasedEvent);
	};

}
