[![Build Status](https://travis-ci.org/X4Ker/vector_example.svg?branch=master)](https://travis-ci.org/X4Ker/vector_example)
```
cmake -H. -B_builds -DBUILD_TESTS=ON
cmake --build _builds
cmake --build _builds --target test -- ARGS=--verbose
```
