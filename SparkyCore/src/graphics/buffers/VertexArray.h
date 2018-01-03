#pragma once

#include <vector>
#include <GL\glew.h>

#include "buffer.h"

namespace Sparky
{
	namespace Graphics
	{

		class VertexArray
		{
			private:
				/// The GL ID for this vertex array.
				GLuint m_ArrayID;
				
				/// The buffers managed by this array.
				std::vector<Buffer*> m_Buffers;

			public:
				/// Constructs a vertex array.
				VertexArray();

				/// Deconstructs a vertex array.
				~VertexArray();

				/// Adds a buffer to the array at the given shader index.
				void AddBuffer(Buffer* buffer, GLuint index);

				/// Binds the Vertex Array 
				void Bind() const;

				/// Unbinds the Vertex Array
				void Unbind() const;
		};


	}
}