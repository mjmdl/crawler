#ifdef KNAVE_GLFW
#ifndef KNAVE__WINDOW_GLFW_HPP
#define KNAVE__WINDOW_GLFW_HPP

#include "window.hpp"

typedef struct GLFWwindow GLFWwindow;

namespace knave
{
	class Window_Glfw final : public Window
	{
	public:
		bool is_close_request;
		
	private:
		GLFWwindow *handle;
		
	public:
		Window_Glfw(void) = default;
		virtual ~Window_Glfw(void) override = default;
		
		virtual bool initialize(void) override;
		virtual void terminate(void) override;
		virtual bool should_close(void) const override;
		virtual void poll_events(void) override;
		virtual void refresh(void) override;
		virtual void present(void) override;
	};
} // knave

#endif // KNAVE__WINDOW_GLFW_HPP
#endif // KNAVE_GLFW
