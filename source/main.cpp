#include <gtkmm.h>
#include "main_window.hpp"
#include "taskflow/core/executor.hpp"
#include "taskflow/core/taskflow.hpp"
#include <taskflow/taskflow.hpp>

using namespace save_throttle;

int main(int argc, char** argv) {
	tf::Executor executor;
	tf::Taskflow taskflow;

	auto app = Gtk::Application::create("lucasm.save_throttle");
	return app->make_window_and_run<MainWindow>(argc, argv);
}
