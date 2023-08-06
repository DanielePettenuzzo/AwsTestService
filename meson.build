project(
    'cpp-template',
    'cpp',
    version: '0.1',
    default_options: ['warning_level=3', 'cpp_std=c++17'],
)

# Add include folder with public headers
subdir('include')

# Add source folder with private headers and sources for the library
subdir('src')

# Add test folder with unit and integration tests
subdir('tests')

# Add appd folder with applications and examples
subdir('apps')

pkg_mod = import('pkgconfig')
pkg_mod.generate(
    name: 'cpp-template',
    filebase: 'cpp_template',
    description: 'A template for C++ projects',
    subdirs: 'cpp_template',
    libraries: template_lib,
    version: '0.1',
)
