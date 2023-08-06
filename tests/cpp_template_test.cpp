
#include <doctest/doctest.h>

#include <cpp-template/cpp_template.hpp>

TEST_SUITE_BEGIN("[CppTemplate]");

TEST_CASE("get_number")
{
  cpp_template::CppTemplate cpp_template;
  CHECK_EQ(cpp_template.getNumber(), 42);
}

TEST_SUITE_END();
