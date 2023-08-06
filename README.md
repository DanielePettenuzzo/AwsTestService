# cpp-template

[![CI](https://github.com/Auterion/cpp-template/actions/workflows/default.yml/badge.svg?branch=main)](https://github.com/Auterion/cpp-template/actions/workflows/default.yml?query=branch%3Amain)
[![Coverage](https://sonarcloud.io/api/project_badges/measure?project=Auterion_cpp-template&metric=coverage&token=78b2753e4da7d31fb7d760e2d4cc12d19b9c3131)](https://sonarcloud.io/summary/new_code?id=Auterion_cpp-template)
[![Technical Debt](https://sonarcloud.io/api/project_badges/measure?project=Auterion_cpp-template&metric=sqale_index&token=78b2753e4da7d31fb7d760e2d4cc12d19b9c3131)](https://sonarcloud.io/summary/new_code?id=Auterion_cpp-template)

Template for a C++ project.

## What is this?

This is a template for a C++ project, with all the tooling set up.
It is meant to be used as a starting point for new projects.
To use it, simply click on the "Use this template" button on the top of the page and follow the instructions.
Once you have your new repository, you need to change all the occurrences of `cpp-template` to the name of your project.
You can do this with the following command:

```bash
find . -type f -exec sed -i 's/cpp-template/<your-project-name>/g' {} +
```

You will also need to change the class name in the `conanfile.py` to match your project name.
Finally, you will need to change the `README.md` to describe your project as well as the `meson.build` to match your project structure.
Make sure to check all files to make sure they are correct.
After that, you are ready to go!

## Prerequisites

We use [Conan](https://conan.io/), [Meson](https://mesonbuild.com/), [Ninja](https://ninja-build.org/), [pre-commit](https://pre-commit.com/), and [commitlint](https://commitlint.js.org/#/) as tooling.
To install them, run:

```bash
sudo apt install cppcheck clang-tidy clang-format
pip install conan meson ninja pre-commit
conan config install https://github.com/Auterion/conan-config.git
```

### To set up the pre-commit hooks

Make sure you have [docker](https://docs.docker.com/get-docker/) installed and running.
You can then install the pre-commit hooks with:

```bash
pre-commit install
```

## Building

The easiest way to get all dependencies and build it is as follows:

```bash
conan build -b missing .
```

This will install all dependencies and build the project.

To build the project and enable code coverage, run:

```bash
conan build -b missing -o cpp-template/*:build_coverage=True .
```

To build the project and enable sanitizers, run:

```bash
conan build -b missing -o cpp-template/*:sanitizers=<sanitizer name> .
```

where `<sanitizer name>` can be one of `address`, `thread`, `undefined`.

For more information on how to use Conan, see the [Conan documentation](https://docs.conan.io/2/).
