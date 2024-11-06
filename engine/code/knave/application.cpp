#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include "application.hpp"
#include "logger.hpp"

std::shared_ptr<spdlog::logger> knave::Logger::engine;
std::shared_ptr<spdlog::logger> knave::Logger::game;

void knave::Logger::initialize(void)
{
    engine = std::make_shared<spdlog::logger>("Knave", std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
    engine->set_level(spdlog::level::trace);

    game = std::make_shared<spdlog::logger>("Game", std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
    game->set_level(spdlog::level::trace);

    spdlog::set_pattern("%T --- %^%n: %v%$");
}

int knave::Application::run(void)
{
	Logger::initialize();
	
	window = Window::create();
	if (!window->initialize())
	{
		KFATAL("Could not initialize the window.");
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
