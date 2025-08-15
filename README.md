# concat_all

[![CI](https://github.com/donedgardo/stanford_cs107_solutions/actions/workflows/ci.yml/badge.svg)](https://github.com/donedgardo/stanford_cs107_solutions/actions/workflows/ci.yml)

A compact C/C++17 project from Stanford CS107 (Programming Paradigms). Implements ConcatAll: recursively traverse a heterogeneous cons-style list, concatenating all String nodes while ignoring non-strings. Returns a heap-allocated C-string.
## Highlights
- Recursive data structures: clean traversal of cons-style lists (head/tail, Nil terminator).
- Memory management: careful heap allocation, ownership, and freeing.
- C/C++ interop: C-style layout with a C++17 toolchain.
- Testing: cross-platform unit tests via CTest/GoogleTest.
- Portability: CMake build; CI on Linux, macOS, and Windows (GitHub Actions).

Conceptual example:
- Input: ["Frodo", ["Baggins", []]] → Output: "FrodoBaggins"
- Integers and Nil are ignored.

## Build and test
- Configure: cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
- Build: cmake --build build --config Release --parallel
- Test (Unix): ctest --test-dir build --output-on-failure
- Test (Windows): ctest --test-dir build -C Release --output-on-failure

The CI runs these steps across all three major OSes.
