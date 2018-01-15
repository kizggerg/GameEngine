#pragma once

#include <deque>
#include "Renderer2D.h"

namespace Sparky
{
	namespace Graphics
	{
		/// A simple renderer to render 2D objects in OpenGL.
		class Simple2DRenderer : public Renderer2D
		{
		// Members
		private:
			/// A queue to store the object yet to render.
			std::deque<const Renderable2D*> m_RenderQueue;

		// Methods
		public:
			/// Submits the renderable object for rendering.
			void Submit(const Renderable2D* renderable) override;
			/// Renders the rendable objects in its deque.
			void Flush() override;
		};
	}
}
