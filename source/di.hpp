#ifndef SAVE_THROTTLE_DI_HPP
#define SAVE_THROTTLE_DI_HPP

#include "save_api.hpp"
#include <kangaru/kangaru.hpp>

namespace save_throttle {
	namespace detail {
		static kgr::container container;
	}

	template<typename T>
	kgr::service_type<T>& get_singleton() {
		return detail::container.service<T>();
	}

	template<typename T>
	kgr::service_type<T> get_transient() {
		return detail::container.service<T>();
	}

	struct SaveApiService final : kgr::single_service<SaveApi> {};
}

#endif
