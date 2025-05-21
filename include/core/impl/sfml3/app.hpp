#pragma once

#include <SFML/Graphics.hpp>

#include <config.hpp>
#include <core/app.hpp>
#include <graph/impl/sfml3/rectangle.hpp>

namespace ns::silnik::impl::sfml3::core {
	
	using conf = ::ns::silnik::Config;
	using Rectangle = ::ns::silnik::impl::sfml3::graph::Rectangle;

	class App final : public ::ns::silnik::core::App {
		public:
			App();
			void handleEvents() override;
			bool isRunning() const override;
			void setupFrame() override;
			void runFrame() override;
			void close() override;
		public:
			sf::RenderWindow window;
		protected:
			sf::Clock m_clock;
			sf::Time m_time;
			sf::View m_view;
			std::optional<sf::Event> m_event;
			Rectangle rectangle;


	}; // class App
	   
	    
}; // namespace ns::silnik::impl::sfml3::core
