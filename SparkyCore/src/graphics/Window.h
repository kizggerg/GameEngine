#pragma once

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>

namespace Sparky
{
	namespace Graphics
	{
		/// Represents a window to render graphics.
		class Window
		{
			// Members
		private:
			/// The title for the window.
			const char* m_Title;

			/// The window's width and height.
			int m_Width, m_Height;

			/// The GLFW window representation.
			GLFWwindow* m_Window;

			// Methods
		public:
			/// Constructs a window
			Window(const char* title, int width, int height);

			/// Deconstructs a window
			~Window();

			/// True when the window is closed
			/// by the user, false otherwise.
			bool Closed() const;

			/// Clears the graphics per frame.
			void Clear() const;

			/// Updates the graphics per frame.
			void Update();

			/// Returns the window's width.
			int getWidth() const;
			
			/// Returns the window's height.
			int getHeight() const;

		private:
			/// Initializes the window.
			bool Init();
		};

		/// A callback function which resizes the
		/// graphics in the window.
		void WindowResize(GLFWwindow* window, int width, int height);
	}
}