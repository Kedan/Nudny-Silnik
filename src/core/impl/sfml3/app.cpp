#include <iostream>

#include <core/app.hpp>
#include <core/impl/sfml3/app.hpp>
#include <core/impl/sfml3/input.hpp>

namespace ns::silnik::impl::sfml3::core {

	App::App() {
		rectangle.setData(rectangleData);
		rectangle.setRenderTarget(window);
		window.create(sf::VideoMode({conf::getInstance().getScreenWidth(),conf::getInstance().getScreenHeight()}),
				conf::getInstance().getName());
		m_exit = false;
	};

	void App::handleEvents() {
		Input::getInstance().reset();
		while(m_event = window.pollEvent()) {
			Input::getInstance().handleEvents(m_event);
			m_exit = m_event->is<sf::Event::Closed>() || Input::getInstance().wasPressed(static_cast<uint32_t>(sf::Keyboard::Key::Escape));
		}
	}

	bool App::isRunning() const { 
		return !m_exit && window.isOpen();  
	}
	void App::setupFrame() {
		m_time = m_clock.reset();
	}
	void App::runFrame() {
		if(Input::getInstance().isHeld(0)) {
			std::cout << "A held\n";
		}
		if(Input::getInstance().wasReleased(0)) {
			std::cout << "A Released\n";
		}	
		window.clear(sf::Color::Black);
		rectangle.draw();
		window.display();
	}
	void App::close() { window.close(); }
};
