#include <core/input.hpp>

namespace ns::silnik::core {
	
	bool Input::wasPressed(uint32_t t_key){ return m_keyPressed[t_key]; };
	bool Input::wasReleased(uint32_t t_key){ return m_keyReleased[t_key];};
	bool Input::isHeld(uint32_t t_key){ return m_keyHeld[t_key];};
	std::optional<uint32_t> Input::getKey(){ return std::nullopt; };
	
	std::array<int,2> Input::getMousePos(){ return std::array<int,2>{0,0}; };
	bool Input::isMouseMove(){ return false; };
	bool Input::wasMouseButtonPressed(uint32_t t_button){ return false;};
	bool Input::wasMouseButtonReleased(uint32_t t_button){ return false; };
	bool Input::isMouseButtonHeld(uint32_t t_button){ return false; };
	std::optional<uint32_t> Input::getMouseButton(){ return std::nullopt; };
	
	bool Input::wasScrolled(){ return false; };
	bool Input::wasScrolledUp(){ return false; };
	bool Input::wasScrolledDown(){ return false; };
	float Input::getScrollValue(){ return 0.0f; };

	void Input::reset(){
		m_keyPressed.clear();
		m_keyReleased.clear();

		m_mousePressed.clear();
		m_mouseReleased.clear();
	};
} // namespace ns::silnik::core
