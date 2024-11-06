#include <iostream>

#include "game.hpp"

void crawler::Game::bootstrap(void)
{
	std::cout << "Game Boostrap'd" << std::endl;
}

void crawler::Game::shutdown(void)
{
	std::cout << "Game Shutdown'd" << std::endl;
}

knave::Application *knave::create_application(void)
{
	return new crawler::Game;
}
