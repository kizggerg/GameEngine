#include "src/graphics/Window.h"

/*
These are here for testing purposes and
will be removed once the window is tested.
*/
using namespace Sparky;
using namespace Graphics;

int main()
{
	Window window("Sparky", 960, 540);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);
	
	while (!window.Closed())
	{
		window.Clear();
		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f,  0.5f);
		glVertex2f( 0.5f,  0.5f);
		glVertex2f( 0.5f, -0.5f);
		glEnd();
		window.Update();
	}

	return 0;
}