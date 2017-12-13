#pragma once
#include "../utils/FileUtils.h"
#include "../math/Math.h"
#include <iostream>
#include <vector>
#include <GL/glew.h>

namespace Sparky
{
	namespace Graphics
	{
		class Shader
		{
		// Members
		private:
			/// The shader ID required by OpenGL to use
			/// this shader.
			GLuint m_ShaderID;

			/// The path to the current vertex
			const char* m_VertPath;

			/// The path to the current fragment
			const char* m_FragPath;

		// Methods
		public:
			/// Constructs a shader with the given vertex and fragment
			/// components.
			Shader(const char* vertPath, const char* fragPath);

			/// Deconstructs the shader.
			~Shader();

			/// Sets the GL uniform for a floating point number.
			void SetUniform1f(const GLchar* name, float value);

			/// Sets the GL uniform for an int.
			void SetUniform1i(const GLchar* name, int value);

			/// Sets the GL uniform for a 2D vector.
			void SetUniform2f(const GLchar* name, const Math::Vec2 &vector);

			/// Sets the GL uniform for a 3D vector.
			void SetUniform3f(const GLchar* name, const Math::Vec3 &vector);

			/// Sets the GL uniform for a 4D vector.
			void SetUniform4f(const GLchar* name, const Math::Vec4 &vector);

			/// Sets the GL uniform for a 4 x 4 matrix.
			void SetUniformMat4(const GLchar* name, const Math::Mat4 &matrix);

			/// Enables the shader in the program.
			void Enable() const;

			/// Disables the shader in the program.
			void Disable() const;

		private:
			/// Loads the fragment and vertex shaders into the GL program.
			GLuint Load();

			/// Gets the GL uniform location
			GLint GetUniformLocation(const GLchar* name);
		};
	}
}