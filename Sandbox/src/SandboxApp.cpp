#include <MeltingPot.h>

#include "imgui/imgui.h"

class ExampleLayer : public MeltingPot::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
		
	}

	void OnUpdate() override
	{
		if (MeltingPot::Input::IsKeyPressed(MP_KEY_TAB))
			MP_TRACE("Tab key is pressed (poll)!");
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}

	void OnEvent(MeltingPot::Event& event) override
	{
		if (event.GetEventType() == MeltingPot::EventType::KeyPressed)
		{
			MeltingPot::KeyPressedEvent& e = (MeltingPot::KeyPressedEvent&)event;
			if (e.GetKeyCode() == MP_KEY_TAB)
				MP_TRACE("Tab key is pressed (event)!");
			MP_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};

class Sandbox : public MeltingPot::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

MeltingPot::Application* MeltingPot::CreateApplication()
{
	return new Sandbox();
}