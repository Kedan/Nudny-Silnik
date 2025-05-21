#pragma once

#include <memory>
#include <glm/glm.hpp>
#include <graph/rectangle_data.hpp>

namespace ns::silnik::graph {

	class Resetable {
		public:
			virtual void reset() = 0;
	};
	
	class Drawable {
		public:
			virtual void draw() = 0;
	};

	class Colorful {
		public:
			virtual void setColor(uint8_t,uint8_t,uint8_t,uint8_t) = 0;
			virtual void setColor(float,float,float,float) = 0;
			virtual void setColor(glm::vec4) = 0;
			virtual glm::vec4  getColori() = 0;
			virtual glm::vec4  getColorf() = 0;
	};

	class Transformable {
		public:
			virtual void setPosition(float,float) = 0;
			virtual void setPosition(glm::vec2) = 0;
			virtual void setRotation(float) = 0;
			virtual glm::vec2 getPosition() = 0;
			virtual float getX() = 0;
			virtual float getY() = 0;
			virtual float getRotation() = 0;
	};

	class Shape 
	: public Resetable
	, public Drawable
	, public Colorful
	, public Transformable 
	{
	};
	
	class Circle : public Shape {
		public:
			virtual void setRadius(float) = 0;
			virtual float getRadius() = 0;
	};

	class Rectangle : public Shape {
		public:
			virtual void setSize(float,float) = 0;
			virtual void setSize(glm::vec2) = 0;
			virtual glm::vec2 getSize() = 0;
			virtual float getWidth() = 0;
			virtual float getHeight() = 0;
			
			virtual void setData(RectangleData& t_data) = 0;
		protected:
			RectangleData* m_data;
	};
};
