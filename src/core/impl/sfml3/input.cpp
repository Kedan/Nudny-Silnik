#include <iostream>
#include <core/impl/sfml3/input.hpp>

namespace ns::silnik::impl::sfml3::core {

	void Input::handleEvents(std::optional<sf::Event> t_event) {
		if(t_event->is<sf::Event::MouseMoved>()) {	
			m_mousePosition = t_event->getIf<sf::Event::MouseMoved>()->position;
		}
		if(t_event->is<sf::Event::KeyPressed>()) {
			press(static_cast<uint32_t>(t_event->getIf<sf::Event::KeyPressed>()->code));
		}
		if(t_event->is<sf::Event::KeyReleased>()) {
			release(static_cast<uint32_t>(t_event->getIf<sf::Event::KeyReleased>()->code));
		}
		if(t_event->is<sf::Event::MouseButtonPressed>()) {
			pressMouseButton(static_cast<uint32_t>(t_event->getIf<sf::Event::MouseButtonPressed>()->button));
		}
		if(t_event->is<sf::Event::MouseButtonReleased>()) {
			releaseMouseButton(static_cast<uint32_t>(t_event->getIf<sf::Event::MouseButtonReleased>()->button));
		}
		if(t_event->is<sf::Event::MouseWheelScrolled>()) {
		}
	}

};
