#include <core/impl/sdl3/input.hpp>

namespace ns::silnik::impl::sdl3::core {

	void Input::handleEvents(const SDL_Event& t_event) {
		switch(t_event.type) {
			case SDL_EVENT_MOUSE_MOTION:
				m_mousePos[0] = t_event.motion.x;	
				m_mousePos[1] = t_event.motion.y;	
				break;
			case SDL_EVENT_MOUSE_BUTTON_DOWN:
				pressMouseButton(static_cast<uint32_t>(t_event.button.button));
				break;
			case SDL_EVENT_MOUSE_BUTTON_UP:
				releaseMouseButton(static_cast<uint32_t>(t_event.button.button));
				break;
			case SDL_EVENT_KEY_DOWN:
				press(static_cast<uint32_t>(t_event.key.key));
				break;
			case SDL_EVENT_KEY_UP:
				release(static_cast<uint32_t>(t_event.key.key));
				break;
		};
	}

} // namespace ns::silnik::impl::sdl3::core
