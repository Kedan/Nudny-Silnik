#include <iostream>
#include <core/impl/glfw3/input.hpp>

namespace ns::silnik::impl::glfw3::core {

	void Input::handleEvents(GLFWwindow* t_window) {
		glfwSetCursorPosCallback(t_window, Input::handleMouseMoveEvents);
		glfwSetKeyCallback(t_window, Input::handleKeyboardEvents);
		glfwSetMouseButtonCallback(t_window, Input::handleMouseButtonEvents);
	}

	void Input::handleKeyboardEvents(GLFWwindow* m_window, int t_key, int t_scancode, int t_action, int t_mods ) {
		switch(t_action) {
			case GLFW_PRESS:
				getInstance().press(t_key);
				break;
			case GLFW_RELEASE:
				getInstance().release(t_key);
				break;
		}
	};

	void Input::handleMouseButtonEvents(GLFWwindow* t_window, int t_button, int t_action, int t_mods) {
		switch(t_action) {
			case GLFW_PRESS:
				getInstance().pressMouseButton(t_button);
				break;
			case GLFW_RELEASE:
				getInstance().releaseMouseButton(t_button);
				break;
		}
	}

	void Input::handleMouseMoveEvents(GLFWwindow* t_window, double x, double y) {
		getInstance().m_mousePos[0] = static_cast<int>(x);
		getInstance().m_mousePos[1] = static_cast<int>(y);
	}
	
}; // namespace ns::silnik::impl::glfw3::core

