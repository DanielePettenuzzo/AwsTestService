import os
from conan import ConanFile
from conan.tools.meson import MesonToolchain, Meson
from conan.tools.cmake import cmake_layout


class CppTemplateConan(ConanFile):
    name = "cpp-template"
    version = "0.1.0"
    license = "<Put the package license here>"
    author = "Jakob Widauer jakob@auterion.com"
    url = "https://github.com/Auterion/cpp-template"
    description = "A template for C++ projects"
    topics = "template"
    settings = "os", "compiler", "build_type", "arch"
    options = {
        "shared": [True, False],
        "fPIC": [True, False],
        "build_coverage": [True, False],
        "sanitizer": ["none", "address", "thread", "undefined"],
    }
    default_options = {
        "shared": False,
        "fPIC": True,
        "build_coverage": False,
        "sanitizer": "none",
    }
    exports_sources = "*", "!build*", "!docs*"
    generators = "PkgConfigDeps"
    requires = "spdlog/1.11.0"
    test_requires = ["doctest/2.4.10"]

    def layout(self):
        cmake_layout(self)

    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC

    def generate(self):
        tc = MesonToolchain(self)
        tc.project_options["b_coverage"] = self.options.build_coverage

        sanitizer = str(self.options.sanitizer)
        tc.project_options["b_sanitize"] = sanitizer

        if sanitizer in ["address", "thread", "undefined"]:
            tc.project_options["b_lundef"] = False

        tc.generate()

    def build(self):
        meson = Meson(self)
        meson.configure()
        if not os.getenv("CONFIGURE_ONLY"):
            meson.build()

    def package(self):
        meson = Meson(self)
        meson.install()

    def package_info(self):
        self.cpp_info.libs = tools.collect_libs(self)
