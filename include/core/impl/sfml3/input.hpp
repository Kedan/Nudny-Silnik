#pragma once

#include <map>
#include <SFML/Window/Event.hpp>

#include <util/singleton.hpp>
#include <core/input.hpp>

namespace ns::silnik::impl::sfml3::core {
	class Input 
		: public ::ns::silnik::core::Input
		, public ::ns::helper::Qsin<Input>	{
			friend class ::ns::helper::Qsin<Input>;
		public:
			~Input() = default;
			void handleEvents(std::optional<sf::Event>);
		protected:
			Input() = default;
			
			sf::Vector2i m_mousePosition;
	}; // class Input
}; // namespace ns::silnik::impl::sfml3::core
  
