#pragma once

#include "MeltingPot/Layer.h"

namespace MeltingPot {

	class MELTINGPOT_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);

	private:
		float m_Time = 0;

	};

}

