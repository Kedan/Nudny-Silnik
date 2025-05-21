#pragma once

#include <SDL3/SDL.h>
#include <core/app.hpp>

namespace ns::silnik::impl::sdl3::core {
	class App : public ::ns::silnik::core::App {
		public:
			App();
		public:
			SDL_Window* window{nullptr};
			SDL_Renderer* renderer{nullptr};
		protected:
			SDL_Event m_event;

			bool isRunning() const override;
			void handleEvents() override;
			void setupFrame() override;
			void runFrame() override;
			void close() override;

	};
};
