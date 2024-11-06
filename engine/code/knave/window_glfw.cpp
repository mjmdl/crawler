#ifdef KNAVE_GLFW

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "logger.hpp"
#include "window_glfw.hpp"

static void print_glfw_error(int error, const char *description)
{
	knave::KERROR("GLFW error #{}: {}", error, description);
}

static void request_window_to_close(GLFWwindow *window)
{
	auto self = (knave::Window_Glfw *)glfwGetWindowUserPointer(window);
	self->is_close_request = true;
}

std::unique_ptr<knave::Window> knave::Window::create(void)
{
	return std::make_unique<Window_Glfw>();
}

bool knave::Window_Glfw::initialize(void)
{
	glfwSetErrorCallback(print_glfw_error);
	
	if (!glfwInit())
	{
		KERROR("Could not initialize GLFW!");
		return false;
	}

	glfwWindowHint(GLFW_CONTEXT_DEBUG, GLFW_TRUE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	handle = glfwCreateWindow(960, 540, "Knave", NULL, NULL);
	if (!handle)
	{
		KERROR("Could not create the GLFW window!");
		return false;
	}

	glfwMakeContextCurrent(handle);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		KERROR("Could not load GLAD!");
		return false;
	}
	
	glfwSetWindowUserPointer(handle, this);
	glfwSetWindowCloseCallback(handle, request_window_to_close);

	GLenum error = glGetError();
	if (error != GL_NO_ERROR)
	{
		KERROR("OpenGL error: #{}.", error);
	}
	
	return true;
}

void knave::Window_Glfw::terminate(void)
{
	glfwTerminate();
}

bool knave::Window_Glfw::should_close(void) const
{
	return is_close_request;
}

void knave::Window_Glfw::poll_events(void)
{
	glfwPollEvents();
}

void knave::Window_Glfw::refresh(void)
{
	glClearColor(0.17f, 0.17f, 0.17f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void knave::Window_Glfw::present(void)
{
	glfwSwapBuffers(handle);
}

#endif // KNAVE_GLFW
