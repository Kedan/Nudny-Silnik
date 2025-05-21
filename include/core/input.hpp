#pragma once

#include <map>
#include <optional>
#include <array>
#include <memory>

namespace ns::silnik::core {
	class Input {
		public:
			virtual ~Input() = default;

			virtual bool wasPressed(uint32_t t_key);
			virtual bool wasReleased(uint32_t t_key);
			virtual bool isHeld(uint32_t t_key);
			virtual std::optional<uint32_t> getKey();
			
			virtual std::array<int,2> getMousePos();
			virtual bool isMouseMove();
			virtual bool wasMouseButtonPressed(uint32_t t_button);
			virtual bool wasMouseButtonReleased(uint32_t t_button);
			virtual bool isMouseButtonHeld(uint32_t t_button);
			virtual std::optional<uint32_t> getMouseButton();
			
			virtual bool wasScrolled();
			virtual bool wasScrolledUp();
			virtual bool wasScrolledDown();
			virtual float getScrollValue();

			virtual void reset();
		protected:
			Input() = default;	
			
			inline void press(uint32_t t_key) {
				m_keyPressed[t_key] = true;
				m_keyHeld[t_key] = true;
				m_keyReleased[t_key] = false;
			}

			inline void release(uint32_t t_key) {
				m_keyPressed[t_key] = false;
				m_keyHeld[t_key] = false;
				m_keyReleased[t_key] = true;
			}
			
			inline void pressMouseButton(uint32_t t_mouse) {
				m_mousePressed[t_mouse] = true;
				m_mouseHeld[t_mouse] = true;
				m_mouseReleased[t_mouse] = false;
			}

			inline void releaseMouseButton(uint32_t t_mouse) {
				m_mousePressed[t_mouse] = false;
				m_mouseHeld[t_mouse] = false;
				m_mouseReleased[t_mouse] = true;
			}

			std::map<uint32_t,bool> m_keyPressed;
			std::map<uint32_t,bool> m_keyReleased;
			std::map<uint32_t,bool> m_keyHeld;

			std::map<uint32_t,bool> m_mousePressed;
			std::map<uint32_t,bool> m_mouseReleased;
			std::map<uint32_t,bool> m_mouseHeld;

			std::array<int,2> m_mousePos;


	}; // class Input
}; // namespace ns::core
