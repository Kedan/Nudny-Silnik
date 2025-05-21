#include <iostream>
#include <fstream>
#include <stdexcept>
#include <config.hpp>

namespace ns::silnik {
	
std::unique_ptr<Config> Config::instance;
std::mutex Config::mtx;

Config& Config::getInstance() {
	std::lock_guard<std::mutex> lock(mtx);
	if(!instance) {
		instance.reset(new Config());
	}
	return *instance;
}

bool Config::load(const std::string& t_filepath) {
	if(!loaded) {
		filepath = t_filepath;
		load();
		return true;
	}
	return false;
}

bool Config::save(const std::string& file = {}) {
	return false;
}

void Config::load() {
	try {
		std::lock_guard<std::mutex> lock(mtx);
		std::ifstream file(filepath, std::ios::binary);
		if(!file) {
			throw std::ios_base::failure("Could not load \""+filepath+"\" file.\n Default configuration loaded.\n");
		} else {
			nlohmann::json data;
			file >> data;
			load(data);
		}
	} catch( const std::exception& e) {
		std::cerr << "nudny::Config::load() - " << e.what() << "\n";
	}
}

void Config::load(const nlohmann::json& data) {
	try {
		name = data["name"];
		fps = data["fps"];
		volume = data["volume"]["master"];
		musicVolume = data["volume"]["music"];
		sfxVolume = data["volume"]["sfx"];
		windowWidth = data["resolution"][0];
		windowHeight = data["resolution"][1];
		fullscreen = data["fullscreen"];
		vsync = data["vsync"];
		loaded = true;
		if(data["implementation"]=="sfml3" )
			implementation = 0;
		if(data["implementation"]=="sdl3")
			implementation = 1;
		if(data["implementation"]=="glfw3")
			implementation = 2;
	} catch( const std::exception& e) {
		std::cerr << "Config::load(json) - " << e.what() << "\n";
	}
}

void Config::print() {
	std::cout << "Conf file: " << filepath << "\n"
		<< "App name: " << name << "\n"
		<< "FPS: " << fps << "\n"
		<< "Master Volume: " << volume << "\n"
		<< "Music Volume: " << musicVolume << "\n"
		<< "SFX Volume: " << sfxVolume << "\n"
		<< "Resolution: [" << windowWidth << ", " << windowHeight  << "] \n"
		<< "Fullscreen : " << fullscreen << "\n"
		<< "VSYNC: " << vsync << "\n"
		<< "Is loaded: " << loaded << "\n";
};
}; // namespace ns::silnik
