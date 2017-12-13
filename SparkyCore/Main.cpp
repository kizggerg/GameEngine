#include "src/graphics/Window.h"
#include "src/math/Math.h"

/*
These are here for testing purposes and
will be removed once the window is tested.
*/
using namespace Sparky;
using namespace Graphics;
using namespace Math;

float* Multiply(float m_Elements[16], float otherm_Elements[16]);

int main()
{
	Window window("Sparky", 960, 540);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);
	
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	
	Mat4 position = Mat4::Translation(Vec3(2, 3, 4));
	position *= Mat4::Identity();

	Vec4 column = position.columns[3];
	std::cout << column << std::endl;
	while (!window.Closed())
	{
		
#if 1
		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f,  0.5f);
		glVertex2f( 0.5f,  0.5f);
		glVertex2f( 0.5f, -0.5f);
		glEnd();
#else
		glDrawArrays(GL_ARRAY_BUFFER, 0, 0);
#endif
		window.Update();
	}

	return 0;
}
