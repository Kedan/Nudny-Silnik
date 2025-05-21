#include <SDL3/SDL_opengl.h>
#include <graph/inc/drawable.hpp>

namespace ns::silnik::impl::sfml3::graph {
	
	void Circle::reset(CircleData& t_data) {
		m_data = &t_data;
		m_circle.setRadius(t_data.radius);
		m_circle.setPosition(t_data.position.x, t_data.position.y);
		m_circle.setRotation(sf::degrees(t_data.rotation));
		m_circle.setFillColor(sf::Color(
						static_cast<uint8_t>(t_data.color.x)
						,static_cast<uint8_t>(t_data.color.y)
						,static_cast<uint8_t>(t_data.color.z)
						,static_cast<uint8_t>(t_data.color.w)
					));
	}

	void Circle::reset(CircleData& t_data, sf::RenderWindow& t_window) {
		m_terget = &t_window;
		reset(t_data);
	}

	void Circle::draw() {
		m_target->draw(m_circle);
	}

	void Circle::draw(sf::Transform& t_transform) {
		m_target->draw(m_circle, t_transform)
	}

	void draw(::ns::silnik::graph::Circle& t_circle, sf::RenderWindow& t_window) {
		t_window.draw(m_circle);
	}
};

namespace ns::silnik::impl::glfw3::graph {
	
	void Circle::reset() {
		m_vertices.clear();
		m_vertices.emplace_back({potition.x,position.y});
		for(int i=0; i<segments; ++i) {
			float theta = 2.0f * 3.1415926f * float(i) / float(segmants);
			float x = t_circle.radius * cos(theta);
			float y = t_circle.radius * sin(theta);
			m_vertices.emplace_back({position.x+x, position.y+y});
		}
	}

	void draw(::ns::silnik::graph::Circle& t_circle) {
		glColor3f( 255/t_circle.color[0], 255/t_circle.color[1], 255/t_circle.color[2], 255/t_circle.color[3]);
		glBegin(GL_TRIANGLE_FAN);
		for(auto v : m_verices) {
			glVertex2f(v[0],v[1]);
		}
		glEnd();
	}
}
