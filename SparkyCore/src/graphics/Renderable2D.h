#pragma once

#include "buffers/Buffer.h"
#include "buffers/IndexBuffer.h"
#include "buffers/VertexArray.h"

#include "../math/Math.h"
#include "Shader.h"

namespace Sparky
{
	namespace Graphics
	{
		/// Defines a 2D object that is renderable to OpenGL
		class Renderable2D
		{
		// Memebers
		protected:
			/// The Position of the object.
			Math::Vec3 m_Position;

			/// The size of the object.
			Math::Vec2 m_Size;

			/// The color of the object.
			Math::Vec4 m_Color;

			/// Holds the vertices of the object.
			VertexArray* m_VertexArray;

			/// Holds the index of the object.
			IndexBuffer* m_IndexBuffer;

			/// The shader on which to render
			Shader& m_Shader;

		// Methods
		public:
			/// Constructs a new 2D renderable object with the given size and color
			/// at the given position.
			Renderable2D(Math::Vec3 position, Math::Vec2 size, Math::Vec4 color, Shader& shader)
				: m_Position(position), m_Size(size), m_Color(color), m_Shader(shader)
			{
				m_VertexArray = new VertexArray();
				GLfloat vertices[] = 
				{ 
					0, 0, 0,
					0, size.y, 0,
					size.x, size.y, 0,
					size.x, 0, 0
				};

				GLfloat colors[] =
				{
					color.x, color.y, color.z, color.w,
					color.x, color.y, color.z, color.w,
					color.x, color.y, color.z, color.w,
					color.x, color.y, color.z, color.w
				};

				m_VertexArray->AddBuffer(new Buffer(vertices, 4 * 3, 3), 0);
				m_VertexArray->AddBuffer(new Buffer(colors, 4 * 4, 4), 1);

				GLushort indices[] = { 0, 1, 2, 2, 3, 0 };
				m_IndexBuffer = new IndexBuffer(indices, 6);
			}

			/// Deconstructs the 2D renderable object.
			~Renderable2D()
			{
				delete m_VertexArray;
				delete m_IndexBuffer;
			}

			/// Gets the vertex array of the renderable object.
			inline const VertexArray* GetVertexArray() const { return m_VertexArray; }

			/// Gets the index buffer of the renderable object.
			inline const IndexBuffer* GetIndexBuffer() const { return m_IndexBuffer; }

			/// Gets the shader on which to render this object.
			inline Shader& GetShader() const { return m_Shader; }

			/// Gets the position of the renderable object.
			inline const Math::Vec3& GetPosition() const { return m_Position; }

			/// Gets the size of the renderable object.
			inline const Math::Vec2& GetSize() const { return m_Size; }

			/// Gets the color of the renderable object.
			inline const Math::Vec4& GetColor() const { return m_Color; }
		};
	}
}