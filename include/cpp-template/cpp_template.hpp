#pragma once
#if defined _WIN32 || defined __CYGWIN__
#ifdef BUILDING_CPP_TEMPLATE
#define CPP_TEMPLATE_PUBLIC __declspec(dllexport)
#else
#define CPP_TEMPLATE_PUBLIC __declspec(dllimport)
#endif
#else
#ifdef BUILDING_CPP_TEMPLATE
#define CPP_TEMPLATE_PUBLIC __attribute__((visibility("default")))
#else
#define CPP_TEMPLATE_PUBLIC
#endif
#endif

namespace cpp_template {

/**
 * @brief A class that does something.
 *
 * This class does something.
 */
class CPP_TEMPLATE_PUBLIC CppTemplate {
 public:
  /**
   * @brief Construct a new `CppTemplate` object.
   */
  CppTemplate() = default;

  /**
   * @brief Get the number 42.
   *
   * This is a simple function that returns the number 42.
   *
   * @returns The number 42.
   */
  [[nodiscard]] int getNumber() const;

 private:
  const int number_{42};
};

}  // namespace cpp_template
