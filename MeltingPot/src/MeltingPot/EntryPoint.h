#pragma once

#ifdef MP_PLATFORM_WINDOWS

extern MeltingPot::Application* MeltingPot::CreateApplication();

int main(int argc, char** argv)
{
	MeltingPot::Log::Init();
	MP_CORE_WARN("Initialized Log!");
	int a = 5;
	MP_INFO("Hello! Var={0}", a);

	auto app = MeltingPot::CreateApplication();
	app->Run();
	delete app;
}

#endif