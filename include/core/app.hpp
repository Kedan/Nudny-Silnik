#pragma once

#include <memory>

#include <core/input.hpp>
#include <graph/interfaces.hpp>
#include <graph/rectangle_data.hpp>

namespace ns::silnik::core {

	class App {
		public:
			App() = default;
			virtual ~App() = default ;
			int run();

			//static std::unique_ptr<Input> input;
		protected:
		//	ns::silnik::graph::RectangleData rectangleData{
		//		{255,0,0,255}
		//		,{0.0f, 0.f}
		//		,0.0f
		//		,{0.25f,0.25f}
		//	};
			ns::silnik::graph::RectangleData rectangleData{
				{255,0,0,255}
				,{100.0f, 100.f}
				,45.0f
				,{25.f,75.f}
			};

			bool m_exit{true};

			void runMainLoop();
			virtual bool isRunning() const;
			virtual void handleEvents() = 0;
			virtual void setupFrame() = 0;
			virtual void runFrame() = 0;
			virtual void close() = 0;
	};

};
