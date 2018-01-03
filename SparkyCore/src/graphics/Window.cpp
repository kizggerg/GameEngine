#include "Window.h"

namespace Sparky
{
	namespace Graphics
	{
	// Methods:
		Window::Window(const char* title, int width, int height)
		{
			m_Title = title;
			m_Width = width;
			m_Height = height;

			if (!Init())
			{
				glfwTerminate();
			}

			for (int i = 0; i < MAX_KEYS; i++)
			{
				m_Keys[i] = false;
			}

			for (int i = 0; i < MAX_BUTTONS; i++)
			{
				m_MouseButtons[i] = false;
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
			glfwSetWindowUserPointer(m_Window, this);
			glfwSetWindowSizeCallback(m_Window, Window_Resize);
			glfwSetKeyCallback(m_Window, Key_Callback);
			glfwSetMouseButtonCallback(m_Window, Mouse_Callback);
			glfwSetCursorPosCallback(m_Window, Cursor_Position_Callback);

			if (glewInit() != GLEW_OK)
			{
				std::cout << "Could not initialize GLEW!" << std::endl;
				return false;
			}

			std::cout << "OPENGL: " << glGetString(GL_VERSION) << std::endl;

			return true;
		}

		int Window::GetWidth() const
		{
			return m_Width;
		}

		int Window::GetHeight() const
		{
			return m_Height;
		}


		bool Window::Closed() const
		{
			return glfwWindowShouldClose(m_Window) == 1;
		}

		bool Window::IsKeyPressed(unsigned int keycode) const
		{
			if (keycode < MAX_KEYS)
			{
				return m_Keys[keycode];
			}
			else
			{
				// TODO: Log this error.
				return false;
			}	
		}

		bool Window::IsMousePressed(unsigned int button) const
		{
			if (button < MAX_BUTTONS)
			{
				return m_MouseButtons[button];
			}
			else
			{
				// TODO: Log this error.
				return false;
			}
		}

		void Window::GetMousePosition(double &x, double &y) const
		{
			x = m_MouseX;
			y = m_MouseY;
		}

		void Window::Clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::Update()
		{
			GLenum error = glGetError();
			if (error != GL_NO_ERROR)
			{
				std::cout << "OpenGL Error: " << error << std::endl;
			}

			glfwPollEvents();
			glfwSwapBuffers(m_Window);
		}

		static void Key_Callback(GLFWwindow* window, int key,
			int scancode, int action, int mods)
		{
			Window* theWindow = (Window*)glfwGetWindowUserPointer(window);
			theWindow->m_Keys[key] = (action != GLFW_RELEASE);
		}

		static void Mouse_Callback(GLFWwindow* window, int button,
			int action, int mods)
		{
			Window* theWindow = (Window*)glfwGetWindowUserPointer(window);
			theWindow->m_MouseButtons[button] = (action != GLFW_RELEASE);
		}

		static void Cursor_Position_Callback(GLFWwindow* window, double xPos,
			double yPos)
		{
			Window* theWindow = (Window*)glfwGetWindowUserPointer(window);
			theWindow->m_MouseX = xPos;
			theWindow->m_MouseY = yPos;
		}

	// Functions:
		void Window_Resize(GLFWwindow* window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}
	}
}