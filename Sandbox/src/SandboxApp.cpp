#include <MeltingPot.h>

class ExampleLayer : public MeltingPot::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{

	}

	void OnUpdate() override
	{
		MP_INFO("ExampleLayer::Update");
	}

	void OnEvent(MeltingPot::Event& event) override
	{
		MP_TRACE("{0}", event);
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