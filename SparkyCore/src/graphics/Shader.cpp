#include "Shader.h"

namespace Sparky
{
	namespace Graphics
	{
		Shader::Shader(const char* vertPath, const char* fragPath)
			: m_VertPath(vertPath), m_FragPath(fragPath)
		{
			m_ShaderID = Load();
		}

		Shader::~Shader()
		{
			glDeleteProgram(m_ShaderID);
		}

		void Shader::Enable() const
		{
			glUseProgram(m_ShaderID);
		}

		void Shader::Disable() const
		{
			glUseProgram(0);
		}

		GLuint Shader::Load()
		{
			GLuint program = glCreateProgram();
			GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
			GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

			std::string vertSourceString = FileUtils::ReadFile(m_VertPath);
			std::string fragSourceString = FileUtils::ReadFile(m_FragPath);
			const char* vertSource = vertSourceString.c_str();
			const char* fragSource = fragSourceString.c_str();

			// Initialize the vertex shader
			glShaderSource(vertex, 1, &vertSource, NULL);
			glCompileShader(vertex);

			GLint result;
			glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);

			if (result == GL_FALSE)
			{
				GLint length;
				glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(vertex, length, &length, &error[0]);
				std::cout << "Failed to compile vertex shader: " << &error[0] << std::endl;
				glDeleteShader(vertex);
				return 0;
			}

			// Initialize the fragment shader
			glShaderSource(fragment, 1, &fragSource, NULL);
			glCompileShader(fragment);

			glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);

			if (result == GL_FALSE)
			{
				GLint length;
				glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(fragment, length, &length, &error[0]);
				std::cout << "Failed to compile fragment shader: " << &error[0] << std::endl;
				glDeleteShader(fragment);
				return 0;
			}

			glAttachShader(program, vertex);
			glAttachShader(program, fragment);

			glLinkProgram(program);
			glValidateProgram(program);

			glDeleteShader(vertex);
			glDeleteShader(fragment);

			return program;
		}

		GLint Shader::GetUniformLocation(const GLchar* name)
		{
			return glGetUniformLocation(m_ShaderID, name);
		}

		void Shader::SetUniform1f(const GLchar* name, float value)
		{
			glUniform1f(GetUniformLocation(name), value);
		}

		void Shader::SetUniform1i(const GLchar* name, int value)
		{
			glUniform1i(GetUniformLocation(name), value);
		}

		void Shader::SetUniform2f(const GLchar* name, const Math::Vec2 &vector)
		{
			glUniform2f(GetUniformLocation(name), vector.x, vector.y);
		}

		void Shader::SetUniform3f(const GLchar* name, const Math::Vec3 &vector)
		{
			glUniform3f(GetUniformLocation(name), vector.x, vector.y, vector.z);
		}

		void Shader::SetUniform4f(const GLchar* name, const Math::Vec4 &vector)
		{
			glUniform4f(GetUniformLocation(name), vector.x, vector.y, vector.z, vector.w);
		}

		void Shader::SetUniformMat4(const GLchar* name, const Math::Mat4 &matrix)
		{
			glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, matrix.m_Elements);
		}

	}
}