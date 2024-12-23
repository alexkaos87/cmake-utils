# cmake-utils
This repository is collecting cmake utilities files.

## Requirements
- cmake
- build-essential
- cppcheck
- catch2
- libgtest-dev, libgmock-dev
- libboost-all-dev
- doxygen, graphviz

## Instructions
In general, if you want to compile a program using _cmake_, you must do the following steps:
1) create a folder called _build_ at the same level of _CMakeLists.txt_ file
2) move inside the _build_ folder using **prompt**
3) run the command `cmake ..`
4) now, you are ready to compile with the command `make`

## Commands
- `make` will compile project(s) and tests and put output on bin folder
- `make all` will compile project(s) and tests and put output on bin folder
- `make build` will compile project(s) and put output on bin folder
- `make rebuild` will clean and compile project(s) and put output on bin folder
- `make clean` will clean project(s) and tests from bin folder
- `make static-check` will run cppcheck on src folder and log output on bin folder
- `make doc` will generate doxygen documentation on bin folder
- `make test` will compile and run whole tests suites (Boost, Catch2, gtest)
- `make test-boost` will compile and run tests using Boost Tests Framework
- `make test-catch2` will compile and run tests using Catch2 Framework
- `make test-gtest` will compile and run tests using Google Test Framework
