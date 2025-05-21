#pragma once

#include <graph/drawable.hpp>

namespace ns::silnik::graph {

	class Renderer : public Drawable {
		protected:
			std::vector<std::shared_ptr<Drawable>> m_drawQueue;
		public:
			Render() = default;
			~Render() = default;
		
	}; //class Renderer
	   
}; // namespace ns::silnk:graph
