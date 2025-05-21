#include <cstdlib>

#include <core/app.hpp>

namespace ns::silnik::core {
	
	//std::unique_ptr<ns::silnik::core::Input> App::input{nullptr};

	int App::run() {
		if(m_exit) {
			close();
			return EXIT_FAILURE;
		}
		runMainLoop();
		return EXIT_SUCCESS;
	}

	void App::runMainLoop() {
		while(isRunning()) {
			setupFrame();
			handleEvents();
			runFrame();
		}
	}

	bool App::isRunning() const {
		return !m_exit;
	}

}; // namespace
