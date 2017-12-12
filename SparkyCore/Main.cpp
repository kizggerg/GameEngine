#include "src/graphics/Window.h"
#include "src/math/Math.h"

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
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);
	
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	
	Vec2 a(1.0f, 2.0f);
	Vec2 b(2.0f, 4.0f);
	
	Vec2 c = a / b;

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
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