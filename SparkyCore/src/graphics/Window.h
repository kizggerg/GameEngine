#pragma once

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>

#define MAX_KEYS 1024
#define MAX_BUTTONS 32


namespace Sparky
{
	namespace Graphics
	{
		/// Represents a window to render graphics.
		class Window
		{
		// Members:
		private:
			/// The title for the window.
			const char* m_Title;

			/// The window's width and height.
			int m_Width, m_Height;

			/// The GLFW window representation.
			GLFWwindow* m_Window;

			/// An array indicating when a key is 
			/// being pressed.
			bool m_Keys[MAX_KEYS];

			/// An array indicating when a mouse button
			/// is being pressed.
			bool m_MouseButtons[MAX_BUTTONS];

			/// The X and Y position of the mouse.
			double m_MouseX, m_MouseY;

		// Methods:
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
			int GetWidth() const;
			
			/// Returns the window's height.
			int GetHeight() const;

			/// True when the key corresponding to
			/// the given keycode being pressed.
			bool IsKeyPressed(unsigned int keycode) const;

			/// True when the mouse corresponding to
			/// the button being pressed.
			bool IsMousePressed(unsigned int button) const;

			/// Sets the given X and Y to the value of the
			/// mouse position.
			/// TODO: Refactor to return a Tuple.
			void GetMousePosition(double &x, double &y) const;

		private:
			/// Initializes the window.
			bool Init();

			/// Handles key inputs from the user.
			friend static void Key_Callback(GLFWwindow* window, int key,
				int scancode, int action, int mods);
			
			/// Handles mouse inputs from the user.
			friend static void Mouse_Callback(GLFWwindow* window, int button, 
				int action, int mods);

			/// Handles events relating to mouse position.
			friend static void Cursor_Position_Callback(GLFWwindow* window, double xPos,
				double yPos);
		};

		// Functions:
		/// A callback function which resizes the
		/// graphics in the window.
		void Window_Resize(GLFWwindow* window, int width, int height);
	}
}