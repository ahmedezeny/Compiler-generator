cmake_minimum_required(VERSION 3.15)
project(Compiler)

set(CMAKE_CXX_STANDARD 14)

add_executable(Compiler main.cpp Token.cpp Token.h State.cpp State.h NFAState.cpp NFAState.h NFA.cpp NFA.h)