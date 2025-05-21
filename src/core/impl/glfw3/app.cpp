#include <iostream>

#include <core/impl/glfw3/input.hpp>
#include <core/impl/glfw3/app.hpp>


namespace ns::silnik::impl::glfw3::core {
	
	App::App() {
		rectangle.setData(rectangleData);
		m_exit = false;
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

		m_window = glfwCreateWindow(
				conf::getInstance().getScreenWidth()
				,conf::getInstance().getScreenHeight()
				,conf::getInstance().getName().c_str()
				,NULL
				,NULL);
		if(!m_window) {
			m_exit = true;
			std::cout << "Could not create GLFW window\n";
		} else {
			Input::getInstance().handleEvents(m_window);
			glfwMakeContextCurrent(m_window);
			glViewport(
					0.0f,
				   	0.0f,
				   	conf::getInstance().getScreenWidth(),
				   	conf::getInstance().getScreenHeight()
			);
			
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			glOrtho(
					0.0f,
					conf::getInstance().getScreenWidth(), 
					conf::getInstance().getScreenHeight(), 
					0.0f, 
					-1.0f,
				   	1.0f
			);
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
		}
	}
	
	void App::handleEvents() {
		Input::getInstance().reset();
		glfwPollEvents(); 
		m_exit = Input::getInstance().wasPressed(GLFW_KEY_ESCAPE);
	}

	bool App::isRunning() const { return !(m_exit || glfwWindowShouldClose(m_window)); 	}
	
	void App::setupFrame() {			
		glLoadIdentity();
		glClearColor(0.2f,0.0f,0.3f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void App::runFrame() {
		// render here

		rectangle.draw();
		glfwSwapBuffers(m_window);
	}

	void App::close() { glfwTerminate(); }	
}; // namespace ns::silnik::impl::glfw3::core

