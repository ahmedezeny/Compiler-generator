# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/zeny/Documents/programs/clion-2019.3.5/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/zeny/Documents/programs/clion-2019.3.5/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zeny/Documents/projects/Compiler/Compiler-generator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zeny/Documents/projects/Compiler/Compiler-generator/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Compiler_generator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Compiler_generator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Compiler_generator.dir/flags.make

CMakeFiles/Compiler_generator.dir/src/Controller.cpp.o: CMakeFiles/Compiler_generator.dir/flags.make
CMakeFiles/Compiler_generator.dir/src/Controller.cpp.o: ../src/Controller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zeny/Documents/projects/Compiler/Compiler-generator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Compiler_generator.dir/src/Controller.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Compiler_generator.dir/src/Controller.cpp.o -c /home/zeny/Documents/projects/Compiler/Compiler-generator/src/Controller.cpp

CMakeFiles/Compiler_generator.dir/src/Controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Compiler_generator.dir/src/Controller.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zeny/Documents/projects/Compiler/Compiler-generator/src/Controller.cpp > CMakeFiles/Compiler_generator.dir/src/Controller.cpp.i

CMakeFiles/Compiler_generator.dir/src/Controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Compiler_generator.dir/src/Controller.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zeny/Documents/projects/Compiler/Compiler-generator/src/Controller.cpp -o CMakeFiles/Compiler_generator.dir/src/Controller.cpp.s

CMakeFiles/Compiler_generator.dir/src/DFA.cpp.o: CMakeFiles/Compiler_generator.dir/flags.make
CMakeFiles/Compiler_generator.dir/src/DFA.cpp.o: ../src/DFA.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zeny/Documents/projects/Compiler/Compiler-generator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Compiler_generator.dir/src/DFA.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Compiler_generator.dir/src/DFA.cpp.o -c /home/zeny/Documents/projects/Compiler/Compiler-generator/src/DFA.cpp

CMakeFiles/Compiler_generator.dir/src/DFA.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Compiler_generator.dir/src/DFA.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zeny/Documents/projects/Compiler/Compiler-generator/src/DFA.cpp > CMakeFiles/Compiler_generator.dir/src/DFA.cpp.i

CMakeFiles/Compiler_generator.dir/src/DFA.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Compiler_generator.dir/src/DFA.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zeny/Documents/projects/Compiler/Compiler-generator/src/DFA.cpp -o CMakeFiles/Compiler_generator.dir/src/DFA.cpp.s

CMakeFiles/Compiler_generator.dir/src/DFAState.cpp.o: CMakeFiles/Compiler_generator.dir/flags.make
CMakeFiles/Compiler_generator.dir/src/DFAState.cpp.o: ../src/DFAState.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zeny/Documents/projects/Compiler/Compiler-generator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Compiler_generator.dir/src/DFAState.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Compiler_generator.dir/src/DFAState.cpp.o -c /home/zeny/Documents/projects/Compiler/Compiler-generator/src/DFAState.cpp

CMakeFiles/Compiler_generator.dir/src/DFAState.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Compiler_generator.dir/src/DFAState.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zeny/Documents/projects/Compiler/Compiler-generator/src/DFAState.cpp > CMakeFiles/Compiler_generator.dir/src/DFAState.cpp.i

CMakeFiles/Compiler_generator.dir/src/DFAState.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Compiler_generator.dir/src/DFAState.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zeny/Documents/projects/Compiler/Compiler-generator/src/DFAState.cpp -o CMakeFiles/Compiler_generator.dir/src/DFAState.cpp.s

CMakeFiles/Compiler_generator.dir/src/NFA.cpp.o: CMakeFiles/Compiler_generator.dir/flags.make
CMakeFiles/Compiler_generator.dir/src/NFA.cpp.o: ../src/NFA.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zeny/Documents/projects/Compiler/Compiler-generator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Compiler_generator.dir/src/NFA.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Compiler_generator.dir/src/NFA.cpp.o -c /home/zeny/Documents/projects/Compiler/Compiler-generator/src/NFA.cpp

CMakeFiles/Compiler_generator.dir/src/NFA.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Compiler_generator.dir/src/NFA.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zeny/Documents/projects/Compiler/Compiler-generator/src/NFA.cpp > CMakeFiles/Compiler_generator.dir/src/NFA.cpp.i

CMakeFiles/Compiler_generator.dir/src/NFA.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Compiler_generator.dir/src/NFA.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zeny/Documents/projects/Compiler/Compiler-generator/src/NFA.cpp -o CMakeFiles/Compiler_generator.dir/src/NFA.cpp.s

CMakeFiles/Compiler_generator.dir/src/State.cpp.o: CMakeFiles/Compiler_generator.dir/flags.make
CMakeFiles/Compiler_generator.dir/src/State.cpp.o: ../src/State.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zeny/Documents/projects/Compiler/Compiler-generator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Compiler_generator.dir/src/State.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Compiler_generator.dir/src/State.cpp.o -c /home/zeny/Documents/projects/Compiler/Compiler-generator/src/State.cpp

CMakeFiles/Compiler_generator.dir/src/State.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Compiler_generator.dir/src/State.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zeny/Documents/projects/Compiler/Compiler-generator/src/State.cpp > CMakeFiles/Compiler_generator.dir/src/State.cpp.i

CMakeFiles/Compiler_generator.dir/src/State.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Compiler_generator.dir/src/State.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zeny/Documents/projects/Compiler/Compiler-generator/src/State.cpp -o CMakeFiles/Compiler_generator.dir/src/State.cpp.s

CMakeFiles/Compiler_generator.dir/src/Token.cpp.o: CMakeFiles/Compiler_generator.dir/flags.make
CMakeFiles/Compiler_generator.dir/src/Token.cpp.o: ../src/Token.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zeny/Documents/projects/Compiler/Compiler-generator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Compiler_generator.dir/src/Token.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Compiler_generator.dir/src/Token.cpp.o -c /home/zeny/Documents/projects/Compiler/Compiler-generator/src/Token.cpp

CMakeFiles/Compiler_generator.dir/src/Token.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Compiler_generator.dir/src/Token.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zeny/Documents/projects/Compiler/Compiler-generator/src/Token.cpp > CMakeFiles/Compiler_generator.dir/src/Token.cpp.i

CMakeFiles/Compiler_generator.dir/src/Token.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Compiler_generator.dir/src/Token.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zeny/Documents/projects/Compiler/Compiler-generator/src/Token.cpp -o CMakeFiles/Compiler_generator.dir/src/Token.cpp.s

CMakeFiles/Compiler_generator.dir/src/zenyTest.cpp.o: CMakeFiles/Compiler_generator.dir/flags.make
CMakeFiles/Compiler_generator.dir/src/zenyTest.cpp.o: ../src/zenyTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zeny/Documents/projects/Compiler/Compiler-generator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Compiler_generator.dir/src/zenyTest.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Compiler_generator.dir/src/zenyTest.cpp.o -c /home/zeny/Documents/projects/Compiler/Compiler-generator/src/zenyTest.cpp

CMakeFiles/Compiler_generator.dir/src/zenyTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Compiler_generator.dir/src/zenyTest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zeny/Documents/projects/Compiler/Compiler-generator/src/zenyTest.cpp > CMakeFiles/Compiler_generator.dir/src/zenyTest.cpp.i

CMakeFiles/Compiler_generator.dir/src/zenyTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Compiler_generator.dir/src/zenyTest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zeny/Documents/projects/Compiler/Compiler-generator/src/zenyTest.cpp -o CMakeFiles/Compiler_generator.dir/src/zenyTest.cpp.s

CMakeFiles/Compiler_generator.dir/main.cpp.o: CMakeFiles/Compiler_generator.dir/flags.make
CMakeFiles/Compiler_generator.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zeny/Documents/projects/Compiler/Compiler-generator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Compiler_generator.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Compiler_generator.dir/main.cpp.o -c /home/zeny/Documents/projects/Compiler/Compiler-generator/main.cpp

CMakeFiles/Compiler_generator.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Compiler_generator.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zeny/Documents/projects/Compiler/Compiler-generator/main.cpp > CMakeFiles/Compiler_generator.dir/main.cpp.i

CMakeFiles/Compiler_generator.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Compiler_generator.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zeny/Documents/projects/Compiler/Compiler-generator/main.cpp -o CMakeFiles/Compiler_generator.dir/main.cpp.s

# Object files for target Compiler_generator
Compiler_generator_OBJECTS = \
"CMakeFiles/Compiler_generator.dir/src/Controller.cpp.o" \
"CMakeFiles/Compiler_generator.dir/src/DFA.cpp.o" \
"CMakeFiles/Compiler_generator.dir/src/DFAState.cpp.o" \
"CMakeFiles/Compiler_generator.dir/src/NFA.cpp.o" \
"CMakeFiles/Compiler_generator.dir/src/State.cpp.o" \
"CMakeFiles/Compiler_generator.dir/src/Token.cpp.o" \
"CMakeFiles/Compiler_generator.dir/src/zenyTest.cpp.o" \
"CMakeFiles/Compiler_generator.dir/main.cpp.o"

# External object files for target Compiler_generator
Compiler_generator_EXTERNAL_OBJECTS =

Compiler_generator: CMakeFiles/Compiler_generator.dir/src/Controller.cpp.o
Compiler_generator: CMakeFiles/Compiler_generator.dir/src/DFA.cpp.o
Compiler_generator: CMakeFiles/Compiler_generator.dir/src/DFAState.cpp.o
Compiler_generator: CMakeFiles/Compiler_generator.dir/src/NFA.cpp.o
Compiler_generator: CMakeFiles/Compiler_generator.dir/src/State.cpp.o
Compiler_generator: CMakeFiles/Compiler_generator.dir/src/Token.cpp.o
Compiler_generator: CMakeFiles/Compiler_generator.dir/src/zenyTest.cpp.o
Compiler_generator: CMakeFiles/Compiler_generator.dir/main.cpp.o
Compiler_generator: CMakeFiles/Compiler_generator.dir/build.make
Compiler_generator: CMakeFiles/Compiler_generator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zeny/Documents/projects/Compiler/Compiler-generator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable Compiler_generator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Compiler_generator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Compiler_generator.dir/build: Compiler_generator

.PHONY : CMakeFiles/Compiler_generator.dir/build

CMakeFiles/Compiler_generator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Compiler_generator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Compiler_generator.dir/clean

CMakeFiles/Compiler_generator.dir/depend:
	cd /home/zeny/Documents/projects/Compiler/Compiler-generator/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zeny/Documents/projects/Compiler/Compiler-generator /home/zeny/Documents/projects/Compiler/Compiler-generator /home/zeny/Documents/projects/Compiler/Compiler-generator/cmake-build-debug /home/zeny/Documents/projects/Compiler/Compiler-generator/cmake-build-debug /home/zeny/Documents/projects/Compiler/Compiler-generator/cmake-build-debug/CMakeFiles/Compiler_generator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Compiler_generator.dir/depend

