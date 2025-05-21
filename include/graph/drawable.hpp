#pragma once 

#include <iostream>
#include <array>
#include <glm/glm.hpp>
#include <SFML/Graphics.hpp>
#include <SDL3/SDL.h>

namespace ns::silnik::graph {

	class Drawable {
		public:
			virtual void draw() = 0;
	};

	struct ShapeData {
		glm::vec4 color;
		glm::vec2 position;
		float rotation;
	};

	struct CircleData : public ShapeData {
		float radius;
		int segments;
	};
	
	struct RectData : public ShapeData {
		glm::vec2 size;
	};

};

namespace ns::silnik::impl::sfml3::graph {
	using CircleData = ::ns::silnik::graph::CircleData;

	class Circle : public ns::silnik::graph::Circle {
		public:
			void reset(CircleData& t_data);
			void reset(CircleData& t_data, sf::RenderWindow&);
		protected:
			CircleData*	m_data;
			sf::RenderWindow* m_target;
			sf::Transform m_transform;
			sf::CircleShape m_circle;
	};

	void draw(::ns::silnik::graph::Circle& t_circle, sf::RenderWindow& t_window);
};

namespace ns::silnik::impl::glfw3::graph {
	class Circle : public ns::silnik::graph::Circle {
		public:
			void reset();
			void draw();
			int segments{60};
		protected:
			std::vector<std::array<float,2>> m_vertices;
	};
};
