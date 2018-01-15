#pragma once

#include <GL/glew.h>
#include "../math/Math.h"
#include "Renderable2D.h"

namespace Sparky
{
	namespace Graphics
	{
		/// An interface which defines a 2D renderer to render Renderable2Ds.
		class Renderer2D
		{
		// Methods
		public:
			/// Submits the renderable object for rendering.
			virtual void Submit(const Renderable2D* renderable) = 0;
			/// Renders the renderable objects in its collection.
			virtual void Flush() = 0;
		};
	}
}

