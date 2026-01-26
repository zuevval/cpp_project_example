# C++ project example: Graph Converter

![Cpp CI](https://github.com/zuevval/cpp_project_example/actions/workflows/cpp-ci.yml/badge.svg)
[![CodeFactor](https://www.codefactor.io/repository/github/zuevval/cpp_project_example/badge)](https://www.codefactor.io/repository/github/zuevval/cpp_project_example)

## Prerequisites

* Linux or MacOS
* g++ or clang
* CMake >= 3.10

## Downloading and building from source

```bash
git clone git@github.com:zuevval/cpp_project_example.git
cd cpp_project_example
cmake -S . -B build
cmake --build build
```

## Example usage

```bash
./build/graphConverter data/example/input.json data/output.txt
```

## Tests

```bash
cd build
ctest
```

---

Style guide:

https://gist.github.com/azoyan/b545f7b926f1f7fb40f8c285e3f5c545
