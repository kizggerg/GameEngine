#pragma once
#include <GL/glew.h>

 namespace Sparky
 {
	namespace Graphics
	{
		class IndexBuffer
		{
		private:
		// Members
			/// The GL ID for this buffer.
			GLuint m_BufferID;

			/// The number of indeces passed into the index buffer
			GLuint m_Count;

		public:
		// Methods
			/// Constructs an index buffer bound to the given data.
			IndexBuffer(GLushort* data, GLsizei count);

			/// Bind the GL Array Buffer to this buffer.
			void Bind() const;

			/// Unbind the GL Array Buffer from this buffer.
			void Unbind() const;

			/// Returns tne number of indeces bound in this index buffer.
			GLuint GetCount() const { return m_Count; }

		};
	}
}


