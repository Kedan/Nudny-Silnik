#pragma once

#include <SDL3/SDL_events.h>

#include <util/singleton.hpp>
#include <core/input.hpp>

namespace ns::silnik::impl::sdl3::core {

	class Input 
		: public ::ns::silnik::core::Input
		, public ::ns::helper::Qsin<Input> {
			friend class ::ns::helper::Qsin<Input>;
		public:
			~Input() = default;
		//	bool wasPressed(uint32_t t_key) override;
		//	bool wasReleased(uint32_t t_key) override;
		//	bool isHeld(uint32_t t_key) override;
		//	std::optional<uint32_t> getKey() override;
		//	
		//	std::array<int,2> getMousePos() override;
		//	bool isMouseMove() override;
		//	bool wasMouseButtonPressed(uint32_t t_button) override;
		//	bool wasMouseButtonReleased(uint32_t t_button) override;
		//	bool isMouseButtonHeld(uint32_t t_button) override;
		//	std::optional<uint32_t> getMouseButton() override;
		//	
		//	bool wasScrolled() override;
		//	bool wasScrolledUp() override;
		//	bool wasScrolledDown() override;
		//	float getScrollValue() override;

		//	void reset() override;

			void handleEvents(const SDL_Event& t_event);
		protected:
			Input() = default;
			
	}; // class Input
} // namespace nd::silnik::impl::sdl3::core
