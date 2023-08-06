#define DOCTEST_CONFIG_IMPLEMENT
#include <doctest/doctest.h>
#include <spdlog/cfg/env.h>
#include <spdlog/spdlog.h>

int main(int argc, char** argv)
{
  // Turn log level off, since we don't want to see the log messages during our tests.
  spdlog::set_level(spdlog::level::off);
  spdlog::cfg::load_env_levels();

  doctest::Context context;
  context.applyCommandLine(argc, argv);
  return context.run();
}
