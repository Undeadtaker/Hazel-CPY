#include "hzpzh.hpp"
#pragma once

#include "../Core.hpp"

namespace Hazel
{
	/*
		Events in Hazel are currently blocking, meaning when an event occurs it
		immediately gets dispatched and must be dealt with right then and there.
		For the future, a better strategy might be to buffer events in an event
		bus and process them during the 'event' part of the update stage.
	*/

	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	// The category of the event defines to which category the event belongs to. One 
	// event can belong to multiple categories. BIT macro defined in core.hpp
	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

	// Since the event is a base class, we can define a macro for the rest 
	// of the derived classes to deduce their types and their category
#define EVENT_CLASS_TYPE(type) static EventType getStaticType() { return EventType::##type; } \
									virtual EventType getEventType() const override { return getStaticType(); } \
									virtual const char* getName() const override {return #type;}

#define EVENT_CLASS_CATEGORY(category) virtual int getCategoryFlags() const override { return category; }

	class HAZEL_API Event
	{

	private:
		friend class EventDispatcher;

	protected:

		// This variable is to check whether the event (for example mouse click) has already been handled
		// by another class, for example the Button class so that it isn't propagated further.
		bool b_Handled = false;

	public:
		virtual EventType getEventType() const = 0;
		virtual const char* getName() const = 0;
		virtual int getCategoryFlags() const = 0;
		virtual std::string toString() { return getName(); }

		// This method calls the category flag of the base Event class and compares it 
		// to the subset and checks whether the event is within that set.
		inline bool isInCategory(EventCategory event) { return this->getCategoryFlags() & event; }
	};

	class EventDispatcher
	{
	private:
		Event& event;

		template<typename T>
		using EventFn = std::function<bool(T&)>;

		inline friend std::ostream& operator<<(std::ostream& os, Event& e) { return os << e.toString(); }

	public:
		EventDispatcher(Event& event) : event(event) {};

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (event.getEventType() == T::getStaticType())
			{
				event.b_Handled = func(*(T*)&event);
				return true;
			}
			return false;
		}

	};
}