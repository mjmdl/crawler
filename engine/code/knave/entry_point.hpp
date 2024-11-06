#ifndef KNAVE__ENTRY_POINT_HPP
#define KNAVE__ENTRY_POINT_HPP

#include "application.hpp"

namespace knave
{
	int entry_point(int argc, char *argv[])
	{
		Application *app = create_application();
		int status = app->run();
		delete app;
		return status;
	}
} // knave

#ifdef KNAVE_GLFW

int main(int argc, char *argv[])
{
	return knave::entry_point(argc, argv);
}

#endif

#endif // KNAVE__ENTRY_POINT_HPP
