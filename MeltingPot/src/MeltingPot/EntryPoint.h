#pragma once

#ifdef MP_PLATFORM_WINDOWS

extern MeltingPot::Application* MeltingPot::CreateApplication();

int main(int argc, char** argv)
{
	auto app = MeltingPot::CreateApplication();
	app->Run();
	delete app;
}

#endif