#ifndef KNAVE__APPLICATION_HPP
#define KNAVE__APPLICATION_HPP

#include "window.hpp"

namespace knave
{
	class Application
	{
		friend int entry_point(int argc, char *argv[]);
	private:
		bool is_running;
		std::unique_ptr<Window> window;
		
	protected:
		virtual ~Application(void) = default;
		Application(void) = default;
		
		virtual void bootstrap(void) = 0;
		virtual void shutdown(void) = 0;

	private:
		int run(void);
	};

	extern Application *create_application(void);
} // knave

#endif // KNAVE__APPLICATION_HPP
