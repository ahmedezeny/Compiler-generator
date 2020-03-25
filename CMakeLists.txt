cmake_minimum_required(VERSION 3.15)
project(compiler2)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(compiler2
        include/Controller.h
        include/DFA.h
        include/NFA.h
        include/State.h
        include/Token.h
        include/DFAState.h
        src/Controller.cpp
        src/DFA.cpp
        src/NFA.cpp
        src/State.cpp
        src/Token.cpp
        src/DFAState.cpp
        main.cpp)
