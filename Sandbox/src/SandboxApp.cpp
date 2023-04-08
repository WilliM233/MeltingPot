#include <MeltingPot.h>

class Sandbox : public MeltingPot::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

MeltingPot::Application* MeltingPot::CreateApplication()
{
	return new Sandbox();
}