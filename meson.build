project('save_throttle', 'cpp', default_options: [
	'cpp_std=c++20',
	'warning_level=3',
	'werror=true',
])
gtkmm = dependency('gtkmm-4.0')
taskflow = dependency('taskflow')
kangaru = dependency('kangaru')
subdir('source')
executable('save_throttle', sources, dependencies: [gtkmm, taskflow, kangaru])
