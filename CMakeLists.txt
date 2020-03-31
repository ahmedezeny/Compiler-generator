cmake_minimum_required(VERSION 3.15)
project(Compiler_generator)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(Compiler_generator
        include/Controller.h
        include/DFA.h
        include/DFAState.h
        include/NFA.h
        include/State.h
        include/Token.h
        src/Controller.cpp
        src/DFA.cpp
        src/DFAState.cpp
        src/NFA.cpp
        src/State.cpp
        src/Token.cpp
        src/zenyTest.cpp
        main.cpp)
