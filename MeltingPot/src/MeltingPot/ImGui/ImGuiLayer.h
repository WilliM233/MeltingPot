#pragma once

#include "MeltingPot/Layer.h"

#include "MeltingPot/Events/ApplicationEvent.h"
#include "MeltingPot/Events/KeyEvent.h"
#include "MeltingPot/Events/MouseEvent.h"

namespace MeltingPot {

	class MELTINGPOT_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:
		float m_Time = 0;

	};

}

