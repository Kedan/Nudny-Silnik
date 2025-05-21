#pragma once

namespace ns::silnik::graph {
	struct ShapeData {
		ShapeData(glm::vec4 c, glm::vec2 p, float r) 
			: color{c}, position{p}, rotation{r} {}
		glm::vec4 color;
		glm::vec2 position;
		float rotation;
	};
	struct RectangleData : public ShapeData {
		RectangleData(glm::vec4 c, glm::vec2 p, float r, glm::vec2 s)
			: ShapeData{c, p, r}, size{s} {}
		glm::vec2 size;
	};
};
