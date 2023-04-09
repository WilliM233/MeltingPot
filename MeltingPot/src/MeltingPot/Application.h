#pragma once

#include "Core.h"
#include "Events/Events.h"

namespace MeltingPot {
	class MELTINGPOT_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}

