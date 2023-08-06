doctest_dep = dependency('doctest')
spdlog_dep = dependency('spdlog')

sources = ['main.cpp', 'cpp_template_test.cpp']

test_exe = executable(
    'cpp_template_test',
    sources,
    dependencies: [cpp_template_dep, doctest_dep, spdlog_dep],
)
test('cpp_template', test_exe)
