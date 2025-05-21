/*
 * Qsin<T> – Quasi Singleton.
 *
 * Provides a global instance of T.
 * If T has a private/protected constructor and declares Qsin<T> as friend,
 * then Qsin<T>::getInstance() acts as a true singleton.
 *
 * Otherwise, local instances of T are also possible.
 */

#pragma once

#include <memory>
#include <mutex>

namespace ns::helper {
	template<typename T>
	class Qsin {
		protected:
			Qsin() = default;
			virtual ~Qsin() = default;
			Qsin(const Qsin&) = delete;
			Qsin& operator=(const Qsin&) = delete;
			Qsin(const Qsin&&) = delete;
			Qsin& operator=(const Qsin&&) = delete;
		public:
			static T& getInstance() {
				static std::unique_ptr<T> instance;
				static std::once_flag flag;
				std::call_once(flag, []{
					instance.reset(new T());
				});
				return *instance;
			}
	};
}
