#pragma once
#include<GL/glew.h>

namespace Sparky
{
	namespace Graphics
	{
		class Buffer
		{
		private:
		// Members
			/// The GL ID for the this buffer.
			GLuint m_BufferID;

			/// The number of components in the data bound to
			/// this buffer.
			GLuint m_ComponentCount;
		public:
		// Methods
			/// Constructs a buffer bound to the given data.
			Buffer(GLfloat* data, GLsizei count, GLuint componentCount);

			/// Bind the GL Array Buffer to this buffer.
			void Bind() const;

			/// Unbind the GL Array Buffer from this buffer.
			void Unbind() const;

			/// Returns tne number of components in data bound to this buffer.
			GLuint GetComponentCount() const { return m_ComponentCount; }
		};
	}
}