#include "main_window.hpp"
#include <gtkmm.h>
#include "di.hpp"
#include "save_api.hpp"

using namespace std::literals;

namespace save_throttle {
	MainWindow::MainWindow() :
		_timestamp_label("Not saved yet"),
		_save_button("Save")
	{
		set_title("Save Throttling");
		set_default_size(300, -1);
		set_resizable(false);
		_timestamp_label.set_margin(3);
		_save_button.set_margin(3);
		_box.set_margin(3);
		_box.set_orientation(Gtk::Orientation::VERTICAL);
		_box.set_halign(Gtk::Align::FILL);
		_box.set_valign(Gtk::Align::FILL);
		_box.set_expand(true);
		_box.append(_timestamp_label);
		_box.append(_save_button);
		set_child(_box);

		SaveApi& save_api = get_singleton<SaveApiService>();
		save_api.set_on_save_handler([&](SaveApi::Timestamp&& timestamp) {
			_timestamp_label.set_label(std::format("Saved: {}", timestamp));
		});
		_save_button.signal_clicked().connect([&] {
			save_api.save();
		});
	}
}
