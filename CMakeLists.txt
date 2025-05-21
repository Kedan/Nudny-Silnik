add_library(nudny-silnik
	src/config.cpp
	src/core/app.cpp
	src/core/input.cpp
	src/core/impl/sfml3/app.cpp
	src/core/impl/sfml3/input.cpp
	src/core/impl/glfw3/app.cpp
	src/core/impl/glfw3/input.cpp
	src/core/impl/sdl3/app.cpp
	src/core/impl/sdl3/input.cpp
	#	src/graph/impl/sfml3/renderer.cpp
)

target_include_directories(nudny-silnik PUBLIC
	include
	share	
	share/glad/include	
)

#include(FetchContent)
#FetchContent_Declare(
#	googletest
#	URL http://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
#)
#FetchContent_MakeAvailable(googletest)
#
#add_executable(
#	app_test
#)
#target_include_directories(app_test PRIVATE
#	./
#	inc
#	ext	
#)
#find_package(OpenGL REQUIRED)
#target_link_libraries(
#	app_test
#	stdc++fs
#	Xxf86vm
#	sfml-system
#	sfml-window
#	sfml-audio
#	sfml-graphics
#	sfml-network
#	SDL3::SDL3
#	glfw
#	OpenGL::GL
#	box2d
#	gtest
#	gmock
#	gtest_main
#)
#
#include(GoogleTest)
#gtest_discover_tests(app_test)
