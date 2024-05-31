#ifndef SAVE_THROTTLE_SAVE_API_HPP
#define SAVE_THROTTLE_SAVE_API_HPP

#include <chrono>
#include <functional>
#include <optional>

namespace save_throttle {
	class SaveApi final {
	public:
		using Clock = std::chrono::high_resolution_clock;
		using Timestamp = Clock::time_point;
		using OnSave = std::function<void(Timestamp&& timestamp)>;

	private:
		Timestamp _last_timestamp;
		std::optional<OnSave> _on_save;

	public:
		void save();
		void set_on_save_handler(OnSave handler);

	private:
		void _actually_save(Timestamp&& timestamp);
	};
}

#endif
