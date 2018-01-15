#include "src/graphics/Window.h"
#include "src/graphics/Shader.h"
#include "src/math/Math.h"

#include "src/graphics/buffers/Buffer.h"
#include "src/graphics/buffers/IndexBuffer.h"
#include "src/graphics/buffers/VertexArray.h"

#include "src/graphics/Renderer2D.h"
#include "src/graphics/Simple2DRenderer.h"


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

	Mat4 ortho = Mat4::Orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.Enable();
	shader.SetUniformMat4("pr_matrix", ortho);
	shader.SetUniformMat4("ml_matrix", Mat4::Translation(Vec3(4, 3, 0)));

	Renderable2D sprite(Math::Vec3(5, 5, 0), Math::Vec2(4, 4), Math::Vec4(1, 0, 1, 1), shader);
	Renderable2D sprite2(Math::Vec3(7, 1, 0), Math::Vec2(2, 3), Math::Vec4(0.2f, 0, 1, 1), shader);
	Simple2DRenderer renderer;

	shader.SetUniform2f("light_pos", Vec2(4.0f, 1.5f));
	shader.SetUniform4f("colour", Vec4(0.2f, 0.3f, 0.8f, 1.0f));

	while (!window.Closed())
	{
		window.Clear();
		double x, y;
		window.GetMousePosition(x, y);
		shader.SetUniform2f("light_pos", Vec2((float)(x * 16.0f / 960.0f), (float)(9.0f - y * 9.0f / 540.0f)));
		renderer.Submit(&sprite);
		renderer.Submit(&sprite2);
		renderer.Flush();
		window.Update();
	}

	return 0;
}
