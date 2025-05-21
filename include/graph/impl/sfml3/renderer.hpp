#pragma once

#include <graph/renderer.hpp>

namespace ns::silnik::impl::sfml3::graph {
	
	class Renderer : public ns::silnik::graph::Rendeder {
		public:
			Renderer() = default;
			Renderer(const sf::RenderWindow& t_window ) : m_window{t_window} {}
			~Renderer() = default;

			void draw();
			void reset();
		protected:
			sf::RenderWindow& m_window;
	}; // class Renderer

} // namespace ns::silnik::impl::sfml3::graph
