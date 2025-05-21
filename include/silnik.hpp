#pragma once

#include <memory>
#include <vector>
#include <string>
#include <iostream>

#include "util/singleton.hpp"
#include "util/callback_queue.hpp"

#include "config.hpp"
#include "core/input.hpp"
#include "core/impl/sfml3/input.hpp"
//#include "core/inc/input_sdl3_impl.hpp"
#include "core/app.hpp"
#include "core/impl/sfml3/app.hpp"
#include "core/impl/sdl3/app.hpp"
#include "core/impl/glfw3/app.hpp"

namespace ns {

class Parser final {
	public:
		Parser(int t_argc, char* t_argv[]) {
			std::string config_file;
			if( t_argc != 1 ) {
				for(int i=1; i<t_argc; ++i) {
					std::string s{t_argv[i]};
					if(!(s!="-c" && s!="--config")) {
						config_file = std::string{t_argv[i+1]};
					}
				}	
			}
			if(config_file.empty()) {
				config_file = "data/config/default.json";
			}
			m_result = silnik::Config::getInstance().load(config_file); 
			if(!m_result) {
				std::cout << "Nudny Silnik ERROR - Could'n load config!\n";
			}
		}
		inline bool result() const { return m_result; }
	protected:
		bool m_result{false};
};

namespace silnik {

	int run(int t_argc, char* t_argv[]) {
		::ns::Parser parser(t_argc, t_argv);
		if(!parser.result()) {
			return EXIT_FAILURE;
		}

		int impl = ::ns::silnik::Config::getInstance().getImplementation();
		std::unique_ptr<::ns::silnik::core::App> app;
		
		switch(impl) {
			case 0:
				app = std::make_unique<::ns::silnik::impl::sfml3::core::App>();
				break;
			case 1:
				app = std::make_unique<::ns::silnik::impl::sdl3::core::App>();
				break;
			case 2:
				app = std::make_unique<::ns::silnik::impl::glfw3::core::App>();
				break;
			default:
				std::cout << "Nudny Silnik ERROR - Unknown implementation set in config.\n";
				return EXIT_FAILURE;
		}
		return app->run();
	}
}; // namespace silnik

}; // namespace ns
