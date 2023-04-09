#include "Application.h"

#include "MeltingPot/Events/ApplicationEvent.h"
#include "MeltingPot/Log.h"

namespace MeltingPot {
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			MP_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			MP_TRACE(e);
		}

		while (true);
	}
}
