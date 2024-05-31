#ifndef SAVE_THROTTLE_MAIN_WINDOW_HPP
#define SAVE_THROTTLE_MAIN_WINDOW_HPP

#include <gtkmm.h>
#include <chrono>

namespace save_throttle {
	class MainWindow final : public Gtk::Window {
	private:
		Gtk::Label _timestamp_label;
		Gtk::Button _save_button;
		Gtk::Box _box;
		std::chrono::high_resolution_clock::time_point _last_save_attempt_timestamp;

	public:
		MainWindow();
	};
}

#endif
