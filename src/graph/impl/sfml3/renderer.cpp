#include <graph/impl/sfml3/renderer.hpp>

namespace ns::silnik::impl::sfml3::graph {
	
	void Renderer::draw() {
		for(auto o : m_drawQueue) {
			o->draw(m_window);
		}
	}

	void Renderer::reset() {
		m_drawQueue.clear();
	}

} // namespace ns::silnik::impl::sfml3::graph
