#pragma once

#include <GLFW/glfw3.h>

#include <util/singleton.hpp>
#include <core/input.hpp>

namespace ns::silnik::impl::glfw3::core {

	class Input 
		: public ::ns::silnik::core::Input
		, public ::ns::helper::Qsin<Input> {
			friend class ::ns::helper::Qsin<Input>;
		public:
			~Input() = default;
			void handleEvents(GLFWwindow* t_window);
			static void handleKeyboardEvents( GLFWwindow* t_window, int t_key, int t_scancode, int t_action, int t_mods);
			static void handleMouseButtonEvents(GLFWwindow* t_window, int t_button, int t_action, int t_mods);
			static void handleMouseMoveEvents(GLFWwindow* t_window, double x, double y);
		protected:
			Input() = default;


	}; // class Input

}; // namespace ns::silnik::impl::glfw3::core

