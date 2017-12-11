#include "Window.h"

namespace Sparky
{
	namespace Graphics
	{
		Window::Window(const char* title, int width, int height)
		{
			m_Title = title;
			m_Width = width;
			m_Height = height;

			if (!Init())
			{
				glfwTerminate();
			}
		}

		Window::~Window()
		{
			glfwTerminate();
		}

		bool Window::Init()
		{
			if (!glfwInit())
			{
				std::cout << "Failed to initialize GLFW!" << std::endl;
				return false;
			}

			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);

			if (!m_Window)
			{
				std::cout << "Failed to create GLFW window!" << std::endl;
				return false;
			}

			glfwMakeContextCurrent(m_Window);
			glfwSetWindowSizeCallback(m_Window, WindowResize);


			if (glewInit() != GLEW_OK)
			{
				std::cout << "Could not initialize GLEW!" << std::endl;
				return false;
			}

			std::cout << "OPENGL: " << glGetString(GL_VERSION) << std::endl;

			return true;
		}

		int Window::getWidth() const
		{
			return m_Width;
		}

		int Window::getHeight() const
		{
			return m_Height;
		}

		bool Window::Closed() const
		{
			return glfwWindowShouldClose(m_Window) == 1;
		}

		void Window::Clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::Update()
		{
			glfwPollEvents();
			glfwSwapBuffers(m_Window);
		}

		void WindowResize(GLFWwindow* window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}
	}
}