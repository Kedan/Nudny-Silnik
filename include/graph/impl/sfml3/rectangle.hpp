#pragma once 

#include <graph/interfaces.hpp>

namespace ns::silnik::impl::sfml3::graph {
	class Rectangle : public ::ns::silnik::graph::Rectangle {
		public:
			Rectangle() = default;
			Rectangle(sf::RenderWindow& t_window) : m_window{&t_window} {}
			~Rectangle() = default;
			void reset() {}
			inline void draw() { m_window->draw(m_shape); }
			inline void setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) { 
				m_data->color = glm::vec4{r,g,b,a};
				m_shape.setFillColor(sf::Color(r,g,b,a)); 
			}
			inline void setColor(float r, float g, float b, float a) { 
				m_data->color = glm::vec4{255*r, 255*g, 255*b, 255*a};
				m_shape.setFillColor(sf::Color(static_cast<uint8_t>(255*r), static_cast<uint8_t>(255*g), static_cast<uint8_t>(255*b), static_cast<uint8_t>(255*a))); 
			}
			inline void setColor(glm::vec4 t_color) {
				m_data->color = t_color;
				m_shape.setFillColor(sf::Color(static_cast<uint8_t>(t_color.x), static_cast<uint8_t>(t_color.y), static_cast<uint8_t>(t_color.z), static_cast<uint8_t>(t_color.w))); 
			}
			inline glm::vec4 getColori() {
				sf::Color c = m_shape.getFillColor();
				return glm::vec4(c.r,c.g,c.b,c.a);
			}
			inline glm::vec4 getColorf() {
				sf::Color c = m_shape.getFillColor();
				return glm::vec4(c.r/255,c.g/255,c.b/255,c.a/255);
			}
			inline void setPosition(float x,float y) {
				m_data->position = glm::vec2{x, y};
				m_shape.setPosition(sf::Vector2f(x,y));
			}
			inline void setPosition(glm::vec2 v) {
				m_data->position = v;
				m_shape.setPosition(sf::Vector2f(v.x,v.y));
			}
			inline void setRotation(float deg) {
				m_data->rotation = deg;
				m_shape.setRotation(sf::degrees(deg));
			}
			inline glm::vec2 getPosition() {
				sf::Vector2f v = m_shape.getPosition();
				return glm::vec2(v.x, v.y);
			}
			inline float getX() { return m_shape.getPosition().x; }
			inline float getY() { return m_shape.getPosition().y; }
			inline float getRotation() { return m_shape.getRotation().asDegrees(); }
			inline void setSize( float w, float h) {
				m_data->size = glm::vec2{w, h};
				m_shape.setSize(sf::Vector2f(w,h));
				setHalfSize();
			}
			inline void setSize(glm::vec2 t_size) {
				m_data->size = glm::vec2{t_size.x, t_size.y};
				m_shape.setSize(sf::Vector2f(t_size.x, t_size.y));
				setHalfSize();
			}
			inline glm::vec2 getSize() {
				sf::Vector2f s = m_shape.getSize();
				return glm::vec2{s.x, s.y};
			}
			inline float getWidth() {
				return m_shape.getSize().x;
			}
			inline float getHeight() {
				return m_shape.getSize().y;
			}
			inline void setHalfSize() { m_size2 = m_data->size*0.5f;  }
			inline glm::vec2 getHalfSize() { return m_size2; }
			inline void setData(ns::silnik::graph::RectangleData& t_data) {
				m_data = &t_data;
				setPosition(m_data->position);
				setRotation(m_data->rotation);
				setColor(m_data->color);
				setSize(m_data->size);
			}
		public:
			inline void setRenderTarget(sf::RenderWindow& t_window) { m_window = &t_window; }
			inline void draw(const sf::Transform& t_transform) {
				m_window->draw(m_shape, t_transform);
			}
		protected:
			sf::RenderWindow* m_window{nullptr};
			sf::Transform m_initialTransform;
			sf::RectangleShape m_shape;
			glm::vec2 m_size2;
	};
};
