#pragma once

#include <string>
#include <thread>
#include <memory>
#include <nlohmann/json.hpp>

namespace ns::silnik {
	class Config final {
		public:
			Config(){};
			Config( const std::string& t_filepath ) : filepath{t_filepath} {
				load();	
			}
			Config(const Config&) = delete;
			Config& operator=(const Config&) = delete;
			bool load(const std::string& t_filepath); 
			bool save(const std::string& filepath);
			
			static Config& getInstance();

			inline std::string getName() const { return name; }
			inline std::string getFilepath() const { return filepath; }
			inline unsigned int getFps() const { return fps; }
			inline float getMasterVolume() const { return volume; }
			inline float getMusicVolume() const { return musicVolume; }
			inline float getSfxVolume() const { return sfxVolume; }
			inline unsigned int getScreenWidth() const { return windowWidth; }
			inline unsigned int getScreenHeight() const { return windowHeight; }
			inline int getImplementation() const { return implementation; }
			inline std::array<unsigned int,2> getResolution() const { return std::array<unsigned int,2>{ windowWidth, windowHeight }; }
			inline bool isFullscreen() const { return fullscreen; }
			inline bool isVsync() const { return vsync; }
			inline bool isLoaded() const { return loaded; }

			inline void setFps(unsigned int f) { fps = f; vsync = false; }
			inline void setMasterVolume(float v) { volume = v; }
			inline void setMusicVolume(float v) { musicVolume = v; }
			inline void setSfxVolume(float v) { sfxVolume = v; }
			inline void setResolution(int w, int h) { windowWidth = w; windowHeight = h; }
			inline void setFullscreen(bool f) { fullscreen = f; }
			inline void setVsync(bool f) { vsync = f; }

			void print();
		private:
			void load();
			void load(const nlohmann::json& data);
		private:
			static std::mutex mtx;
			std::string filepath;
			std::string name{"Nudny Silnik"};
			static std::unique_ptr<Config> instance;
			unsigned int fps{60};
			float volume{0.75f};
			float musicVolume{0.75f};
			float sfxVolume{0.75f};
			int implementation{-1};
			int major{0};
			int minor{0};
			int patch{0};
			unsigned int windowWidth{800};
			unsigned int windowHeight{600};
			bool fullscreen{false};
			bool vsync{false};
			bool loaded{false};
	}; //class Config
 }; // namesapce ns::silnik
