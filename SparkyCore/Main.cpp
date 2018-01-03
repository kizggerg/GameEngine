#include "src/graphics/Window.h"
#include "src/graphics/Shader.h"
#include "src/math/Math.h"

#include "src/graphics/buffers/Buffer.h"
#include "src/graphics/buffers/IndexBuffer.h"
#include "src/graphics/buffers/VertexArray.h"

/*
These are here for testing purposes and
will be removed once the window is tested.
*/
using namespace Sparky;
using namespace Graphics;
using namespace Math;

int main()
{
	Window window("Sparky", 960, 540);
	//glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	
#if 0
	GLfloat vertices[] = 
	{
		0, 0, 0,
		8, 0, 0,
		0, 3, 0,
		0, 3, 0,
		8, 3, 0,
		8, 0, 0
	};
	
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
#else 

	GLfloat vertices[] =
	{
		0, 0, 0,
		0, 3, 0,
		8, 3, 0,
		8, 0, 0
	};

	GLushort indeces[] = 
	{
		0, 1, 2,
		2, 3, 0
	};

	GLfloat colorsA[] = 
	{
		1, 0, 1, 1,
		1, 0, 1, 1,
		1, 0, 1, 1,
		1, 0, 1, 1
	};

	GLfloat colorsB[] =
	{
		0.2f, 0.3f, 0.8f, 1,
		0.2f, 0.3f, 0.8f, 1,
		0.2f, 0.3f, 0.8f, 1,
		0.2f, 0.3f, 0.8f, 1
	};

	VertexArray sprite1, sprite2;
	IndexBuffer ibo(indeces, 6);

	sprite1.AddBuffer(new Buffer(vertices, 4*3, 3), 0);
	sprite1.AddBuffer(new Buffer(colorsA, 4*4, 4), 1);

	sprite2.AddBuffer(new Buffer(vertices, 4 * 3, 3), 0);
	sprite2.AddBuffer(new Buffer(colorsB, 4 * 4, 4), 1);


#endif

	Mat4 ortho = Mat4::Orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.Enable();
	shader.SetUniformMat4("pr_matrix", ortho);
	shader.SetUniformMat4("ml_matrix", Mat4::Translation(Vec3(4, 3, 0)));

	shader.SetUniform2f("light_pos", Vec2(4.0f, 1.5f));
	shader.SetUniform4f("colour", Vec4(0.2f, 0.3f, 0.8f, 1.0f));

	while (!window.Closed())
	{
		window.Clear();
		double x, y;
		window.GetMousePosition(x, y);
		shader.SetUniform2f("light_pos", Vec2((float)(x * 16.0f / 960.0f), (float)(9.0f - y * 9.0f / 540.0f)));
#if 0
		glDrawArrays(GL_TRIANGLES, 0, 6);
#else
		sprite1.Bind();
		ibo.Bind();
		shader.SetUniformMat4("ml_matrix", Mat4::Translation(Vec3(4, 3, 0)));
		glDrawElements(GL_TRIANGLES, ibo.GetCount(), GL_UNSIGNED_SHORT, 0);
		ibo.Bind();
		sprite1.Unbind();


		sprite2.Bind();
		ibo.Bind();
		shader.SetUniformMat4("ml_matrix", Mat4::Translation(Vec3(0, 0, 0)));
		glDrawElements(GL_TRIANGLES, ibo.GetCount(), GL_UNSIGNED_SHORT, 0);
		ibo.Bind();
		sprite2.Unbind();
#endif
		window.Update();
	}

	return 0;
}
