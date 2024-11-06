#include <iostream>

#include "game.hpp"

void crawler::Game::bootstrap(void)
{
	LOG_TRACE("Game Boostrap'd");
}

void crawler::Game::shutdown(void)
{
	LOG_TRACE("Game Shutdown'd");
}

knave::Application *knave::create_application(void)
{
	return new crawler::Game;
}
