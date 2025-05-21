#include <exception>
#include <config.hpp>
#include <core/impl/sdl3/app.hpp>
#include <core/impl/sdl3/input.hpp>

namespace ns::silnik::impl::sdl3::core {

	using conf = ::ns::silnik::Config;

	App::App() {
		if(SDL_Init(SDL_INIT_VIDEO)) {
			window = SDL_CreateWindow(
					conf::getInstance().getName().c_str(),
					conf::getInstance().getScreenWidth(),
					conf::getInstance().getScreenHeight(),
					0
					);
			if(!window) {
				throw std::runtime_error(SDL_GetError());
				SDL_Quit();
			} else {
				renderer = SDL_CreateRenderer(window, NULL);
				if(!renderer) {
					throw std::runtime_error(SDL_GetError());
					SDL_DestroyWindow(window);
					SDL_Quit();
				} else {
					m_exit = false;
				}
			}
		} else {
			throw std::runtime_error(SDL_GetError());
		}
	};

	bool App::isRunning() const {
		return !m_exit;
	}

	void App::handleEvents() {
		Input::getInstance().reset();
		while(SDL_PollEvent(&m_event)) {
			Input::getInstance().handleEvents(m_event);
			m_exit = (m_event.type == SDL_EVENT_QUIT) || Input::getInstance().wasPressed(SDLK_ESCAPE);
		}
	}

	void App::setupFrame() {
		SDL_RenderClear(renderer);
	}

	void App::runFrame() {
		SDL_RenderPresent(renderer);
	}

	void App::close() {
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
	}

};
