#pragma once

#include <iostream>
#include <graph/interfaces.hpp>

namespace ns::silnik::impl::glfw3::graph {
	class Rectangle : public ::ns::silnik::graph::Rectangle {
		public:
			Rectangle() = default;
			~Rectangle() = default;
			void reset() {}
			inline void draw() {
				glPushMatrix();
				glTranslatef(m_data->position.x-m_size2.x, m_data->position.y-m_size2.y, 0.0f);
				glRotatef(m_data->rotation,0,0,1);
				glBegin(GL_QUADS);
				glColor4f(m_data->color.x, m_data->color.y, m_data->color.z, m_data->color.w);
				glVertex3f( -m_size2.x, -m_size2.y,-1.f );
				glVertex3f( -m_size2.x, m_size2.y, -1.f );
				glVertex3f( m_size2.x, m_size2.y, -1.f );
				glVertex3f( m_size2.x, -m_size2.y, -1.f );
				glEnd();
				glPopMatrix();
			}
			inline void setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) { m_data->color = {r/255,g/255,b/255,a/255}; }
			inline void setColor(float r, float g, float b, float a) { m_data->color = {r,g,b,a}; }
			inline void setColor(glm::vec4 color) {
				m_data->color = color;
			}
			inline glm::vec4 getColori() {
				return glm::vec4(static_cast<int>(m_data->color.x*255), static_cast<int>(m_data->color.y*255), static_cast<int>(m_data->color.z*255), static_cast<int>(m_data->color.w*255));
			}
			inline glm::vec4 getColorf() {
				return m_data->color;
			}
			inline void setPosition(float x,float y) {
				m_data->position = {x,y};
			}
			inline void setPosition(glm::vec2 v) {
				m_data->position = v;
			}
			inline void setRotation(float deg) {
				m_data->rotation = glm::radians(deg);
			}
			inline glm::vec2 getPosition() {
				return m_data->position;
			}
			inline float getX() { return m_data->position.x; }
			inline float getY() { return m_data->position.y; }
			inline float getRotation() { return glm::degrees(m_data->rotation); }
			inline void setSize(float w, float h) { m_data->size = {w,h}; setHalfSize();}
			inline void setSize(glm::vec2 t_size) { m_data->size = t_size; setHalfSize(); }
			inline glm::vec2 getSize() { return m_data->size; }
			inline float getWidth() { return m_data->size.x; }
			inline float getHeight() { return m_data->size.y; }
			inline void setHalfSize() { m_size2 = m_data->size*0.5f;  }
			inline glm::vec2 getHalfSize() { return m_size2; }
			inline void setData(::ns::silnik::graph::RectangleData& t_data) {
				m_data = &t_data;
				setHalfSize();
			}
		protected:
			glm::vec2 m_size2;
	};
};
