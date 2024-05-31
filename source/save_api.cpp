#include "save_api.hpp"
#include <chrono>
#include <utility>

using namespace std::literals;

namespace save_throttle {
	void SaveApi::save() {
		auto now = SaveApi::Clock::now();
		auto duration = now - _last_timestamp;
		_last_timestamp = now;

		if (duration > 1s) {
			_actually_save(std::move(now));
			return;
		}
	}

	void SaveApi::set_on_save_handler(SaveApi::OnSave handler) {
		_on_save = handler;
	}

	void SaveApi::_actually_save(Timestamp&& timestamp) {
		if (_on_save) { (*_on_save)(std::move(timestamp)); }
	}
}
