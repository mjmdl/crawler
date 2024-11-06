#include <iostream>

#include "application.hpp"

int knave::Application::run(void)
{
	window = Window::create();
	if (!window->initialize())
	{
		std::cerr << "Could not initialize the window." << std::endl;
		return 1;
	}
	
	bootstrap();

	is_running = true;
	while (is_running)
	{
		window->poll_events();
		if (window->should_close())
		{
			is_running = false;
		}
		
		window->refresh();
		window->present();
	}
	
	shutdown();

	window->terminate();
	
	return 0;
}
