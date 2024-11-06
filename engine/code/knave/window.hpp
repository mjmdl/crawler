#ifndef KNAVE__WINDOW_HPP
#define KNAVE__WINDOW_HPP

#include <memory>

namespace knave
{
	class Window
	{
	public:
		static std::unique_ptr<Window> create(void);

		virtual ~Window(void) = default;
		
		virtual bool initialize(void) = 0;
		virtual void terminate(void) = 0;
		virtual bool should_close(void) const = 0;
		virtual void poll_events(void) = 0;
		virtual void refresh(void) = 0;
		virtual void present(void) = 0;
		
	protected:
		Window(void) = default;
	};
} // knave

#endif // KNAVE__WINDOW_HPP
