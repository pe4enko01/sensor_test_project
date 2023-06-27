# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ivan/projects/test_projects/sensor_test_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ivan/projects/test_projects/sensor_test_project/Build

# Include any dependencies generated for this target.
include src/Algorithms/ControlProcess/CMakeFiles/controlprocess.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/Algorithms/ControlProcess/CMakeFiles/controlprocess.dir/compiler_depend.make

# Include the progress variables for this target.
include src/Algorithms/ControlProcess/CMakeFiles/controlprocess.dir/progress.make

# Include the compile flags for this target's objects.
include src/Algorithms/ControlProcess/CMakeFiles/controlprocess.dir/flags.make

../src/Algorithms/ControlProcess/ControlProcess_SK.cc:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ivan/projects/test_projects/sensor_test_project/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating ../../../../src/Algorithms/ControlProcess/ControlProcess_SK.cc"
	cd /home/ivan/projects/test_projects/sensor_test_project/src/Algorithms/ControlProcess && uniset2-codegen -n ControlProcess --topdir $(top_builddir)/ --ask --no-main controlprocess.src.xml

src/Algorithms/ControlProcess/CMakeFiles/controlprocess.dir/ControlProcess_SK.cc.o: src/Algorithms/ControlProcess/CMakeFiles/controlprocess.dir/flags.make
src/Algorithms/ControlProcess/CMakeFiles/controlprocess.dir/ControlProcess_SK.cc.o: ../src/Algorithms/ControlProcess/ControlProcess_SK.cc
src/Algorithms/ControlProcess/CMakeFiles/controlprocess.dir/ControlProcess_SK.cc.o: src/Algorithms/ControlProcess/CMakeFiles/controlprocess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivan/projects/test_projects/sensor_test_project/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/Algorithms/ControlProcess/CMakeFiles/controlprocess.dir/ControlProcess_SK.cc.o"
	cd /home/ivan/projects/test_projects/sensor_test_project/Build/src/Algorithms/ControlProcess && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/Algorithms/ControlProcess/CMakeFiles/controlprocess.dir/ControlProcess_SK.cc.o -MF CMakeFiles/controlprocess.dir/ControlProcess_SK.cc.o.d -o CMakeFiles/controlprocess.dir/ControlProcess_SK.cc.o -c /home/ivan/projects/test_projects/sensor_test_project/src/Algorithms/ControlProcess/ControlProcess_SK.cc

src/Algorithms/ControlProcess/CMakeFiles/controlprocess.dir/ControlProcess_SK.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/controlprocess.dir/ControlProcess_SK.cc.i"
	cd /home/ivan/projects/test_projects/sensor_test_project/Build/src/Algorithms/ControlProcess && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/projects/test_projects/sensor_test_project/src/Algorithms/ControlProcess/ControlProcess_SK.cc > CMakeFiles/controlprocess.dir/ControlProcess_SK.cc.i

src/Algorithms/ControlProcess/CMakeFiles/controlprocess.dir/ControlProcess_SK.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/controlprocess.dir/ControlProcess_SK.cc.s"
	cd /home/ivan/projects/test_projects/sensor_test_project/Build/src/Algorithms/ControlProcess && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/projects/test_projects/sensor_test_project/src/Algorithms/ControlProcess/ControlProcess_SK.cc -o CMakeFiles/controlprocess.dir/ControlProcess_SK.cc.s

src/Algorithms/ControlProcess/CMakeFiles/controlprocess.dir/ControlProcess.cc.o: src/Algorithms/ControlProcess/CMakeFiles/controlprocess.dir/flags.make
src/Algorithms/ControlProcess/CMakeFiles/controlprocess.dir/ControlProcess.cc.o: ../src/Algorithms/ControlProcess/ControlProcess.cc
src/Algorithms/ControlProcess/CMakeFiles/controlprocess.dir/ControlProcess.cc.o: src/Algorithms/ControlProcess/CMakeFiles/controlprocess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivan/projects/test_projects/sensor_test_project/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/Algorithms/ControlProcess/CMakeFiles/controlprocess.dir/ControlProcess.cc.o"
	cd /home/ivan/projects/test_projects/sensor_test_project/Build/src/Algorithms/ControlProcess && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/Algorithms/ControlProcess/CMakeFiles/controlprocess.dir/ControlProcess.cc.o -MF CMakeFiles/controlprocess.dir/ControlProcess.cc.o.d -o CMakeFiles/controlprocess.dir/ControlProcess.cc.o -c /home/ivan/projects/test_projects/sensor_test_project/src/Algorithms/ControlProcess/ControlProcess.cc

src/Algorithms/ControlProcess/CMakeFiles/controlprocess.dir/ControlProcess.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/controlprocess.dir/ControlProcess.cc.i"
	cd /home/ivan/projects/test_projects/sensor_test_project/Build/src/Algorithms/ControlProcess && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/projects/test_projects/sensor_test_project/src/Algorithms/ControlProcess/ControlProcess.cc > CMakeFiles/controlprocess.dir/ControlProcess.cc.i

src/Algorithms/ControlProcess/CMakeFiles/controlprocess.dir/ControlProcess.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/controlprocess.dir/ControlProcess.cc.s"
	cd /home/ivan/projects/test_projects/sensor_test_project/Build/src/Algorithms/ControlProcess && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/projects/test_projects/sensor_test_project/src/Algorithms/ControlProcess/ControlProcess.cc -o CMakeFiles/controlprocess.dir/ControlProcess.cc.s

src/Algorithms/ControlProcess/CMakeFiles/controlprocess.dir/controlprocess.cc.o: src/Algorithms/ControlProcess/CMakeFiles/controlprocess.dir/flags.make
src/Algorithms/ControlProcess/CMakeFiles/controlprocess.dir/controlprocess.cc.o: ../src/Algorithms/ControlProcess/controlprocess.cc
src/Algorithms/ControlProcess/CMakeFiles/controlprocess.dir/controlprocess.cc.o: src/Algorithms/ControlProcess/CMakeFiles/controlprocess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivan/projects/test_projects/sensor_test_project/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/Algorithms/ControlProcess/CMakeFiles/controlprocess.dir/controlprocess.cc.o"
	cd /home/ivan/projects/test_projects/sensor_test_project/Build/src/Algorithms/ControlProcess && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/Algorithms/ControlProcess/CMakeFiles/controlprocess.dir/controlprocess.cc.o -MF CMakeFiles/controlprocess.dir/controlprocess.cc.o.d -o CMakeFiles/controlprocess.dir/controlprocess.cc.o -c /home/ivan/projects/test_projects/sensor_test_project/src/Algorithms/ControlProcess/controlprocess.cc

src/Algorithms/ControlProcess/CMakeFiles/controlprocess.dir/controlprocess.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/controlprocess.dir/controlprocess.cc.i"
	cd /home/ivan/projects/test_projects/sensor_test_project/Build/src/Algorithms/ControlProcess && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/projects/test_projects/sensor_test_project/src/Algorithms/ControlProcess/controlprocess.cc > CMakeFiles/controlprocess.dir/controlprocess.cc.i

src/Algorithms/ControlProcess/CMakeFiles/controlprocess.dir/controlprocess.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/controlprocess.dir/controlprocess.cc.s"
	cd /home/ivan/projects/test_projects/sensor_test_project/Build/src/Algorithms/ControlProcess && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/projects/test_projects/sensor_test_project/src/Algorithms/ControlProcess/controlprocess.cc -o CMakeFiles/controlprocess.dir/controlprocess.cc.s

# Object files for target controlprocess
controlprocess_OBJECTS = \
"CMakeFiles/controlprocess.dir/ControlProcess_SK.cc.o" \
"CMakeFiles/controlprocess.dir/ControlProcess.cc.o" \
"CMakeFiles/controlprocess.dir/controlprocess.cc.o"

# External object files for target controlprocess
controlprocess_EXTERNAL_OBJECTS =

src/Algorithms/ControlProcess/controlprocess: src/Algorithms/ControlProcess/CMakeFiles/controlprocess.dir/ControlProcess_SK.cc.o
src/Algorithms/ControlProcess/controlprocess: src/Algorithms/ControlProcess/CMakeFiles/controlprocess.dir/ControlProcess.cc.o
src/Algorithms/ControlProcess/controlprocess: src/Algorithms/ControlProcess/CMakeFiles/controlprocess.dir/controlprocess.cc.o
src/Algorithms/ControlProcess/controlprocess: src/Algorithms/ControlProcess/CMakeFiles/controlprocess.dir/build.make
src/Algorithms/ControlProcess/controlprocess: src/Algorithms/ControlProcess/CMakeFiles/controlprocess.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ivan/projects/test_projects/sensor_test_project/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable controlprocess"
	cd /home/ivan/projects/test_projects/sensor_test_project/Build/src/Algorithms/ControlProcess && /usr/bin/cmake -E copy /home/ivan/projects/test_projects/sensor_test_project/src/Algorithms/ControlProcess/configure.xml /home/ivan/projects/test_projects/sensor_test_project/Build/src/Algorithms/ControlProcess
	cd /home/ivan/projects/test_projects/sensor_test_project/Build/src/Algorithms/ControlProcess && /usr/bin/cmake -E copy /home/ivan/projects/test_projects/sensor_test_project/src/Algorithms/ControlProcess/start_fg.sh /home/ivan/projects/test_projects/sensor_test_project/Build/src/Algorithms/ControlProcess
	cd /home/ivan/projects/test_projects/sensor_test_project/Build/src/Algorithms/ControlProcess && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/controlprocess.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/Algorithms/ControlProcess/CMakeFiles/controlprocess.dir/build: src/Algorithms/ControlProcess/controlprocess
.PHONY : src/Algorithms/ControlProcess/CMakeFiles/controlprocess.dir/build

src/Algorithms/ControlProcess/CMakeFiles/controlprocess.dir/clean:
	cd /home/ivan/projects/test_projects/sensor_test_project/Build/src/Algorithms/ControlProcess && $(CMAKE_COMMAND) -P CMakeFiles/controlprocess.dir/cmake_clean.cmake
.PHONY : src/Algorithms/ControlProcess/CMakeFiles/controlprocess.dir/clean

src/Algorithms/ControlProcess/CMakeFiles/controlprocess.dir/depend: ../src/Algorithms/ControlProcess/ControlProcess_SK.cc
	cd /home/ivan/projects/test_projects/sensor_test_project/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ivan/projects/test_projects/sensor_test_project /home/ivan/projects/test_projects/sensor_test_project/src/Algorithms/ControlProcess /home/ivan/projects/test_projects/sensor_test_project/Build /home/ivan/projects/test_projects/sensor_test_project/Build/src/Algorithms/ControlProcess /home/ivan/projects/test_projects/sensor_test_project/Build/src/Algorithms/ControlProcess/CMakeFiles/controlprocess.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/Algorithms/ControlProcess/CMakeFiles/controlprocess.dir/depend

