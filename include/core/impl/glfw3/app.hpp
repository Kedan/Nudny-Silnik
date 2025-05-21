#pragma once

#include <memory>

#include <GLFW/glfw3.h>

#include <config.hpp>
#include <core/app.hpp>
#include <graph/impl/glfw3/rectangle.hpp>

namespace ns::silnik::impl::glfw3::core {
	
class App : public ns::silnik::core::App {

		using conf = ::ns::silnik::Config;
		using Rectangle = ::ns::silnik::impl::glfw3::graph::Rectangle;

		public:
			App();
		
			void handleEvents() override;
			bool isRunning() const override;
			void setupFrame() override;
			void runFrame() override;
			void close() override;
		protected:
			int w, h;
			GLFWwindow* m_window{nullptr};
			Rectangle rectangle;

	}; //class

}; //namespace ns::silnik::impl::glfw3::core
