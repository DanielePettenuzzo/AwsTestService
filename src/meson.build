spdlog_dep = dependency('spdlog')

sources = ['cpp_template.cpp']

# These arguments are only used to build the shared library
# not the executables that use the library.
lib_args = ['-DBUILDING_CPP_TEMPLATE']

template_lib = library(
    'cpp_template',
    sources,
    include_directories: inc_dir,
    dependencies: spdlog_dep,
    install: true,
    cpp_args: lib_args,
    gnu_symbol_visibility: 'hidden',
)

# Make this library usable as a Meson subproject.
cpp_template_dep = declare_dependency(
    include_directories: inc_dir,
    link_with: template_lib,
)
