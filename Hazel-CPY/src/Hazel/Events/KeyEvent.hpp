#pragma once

#include "Event.hpp"
#include <sstream>

namespace Hazel
{

	/* 
		This is a base class for any key event that is pressed.By default we shouldn't be
		able to construct this class ourselves hence why it is in the protected field. Rather,
		this class should be able to be constructed when we either call the class which 
		is either active on key press or release. Kind of an abstract key event.
	*/
	class HAZEL_API KeyEvent : public Event
	{
	protected:
		int key_Code;
		KeyEvent(int keycode) : key_Code(keycode) {};

	public:
		inline int getKeyCode() const { return key_Code };
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	};

	// Class that is derived from the KeyEvent class and is the key press event
	class HAZEL_API KeyPressedEvent : public KeyEvent
	{
	private:
		int repeat_Count;

	public:
		KeyPressedEvent(int keycode, int repeatCount) : key_Code(keycode), repeat_Count(repeatCount) {};

		inline int getRepeatCount() const { return repeat_Count; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent" << key_Code << " (" << repeat_Count << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed);
	};

	// Class that is derived from the KeyEvent class and is the key release event
	class HAZEL_API KeyReleasedEvent : public KeyEvent
	{

	public:
		KeyPressedEvent(int keycode) : key_Code(keycode) {};

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent" << key_Code;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased);
	};

}