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
CMAKE_SOURCE_DIR = "/home/ivan/Рабочий стол/unitest-st_ivan"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/ivan/Рабочий стол/unitest-st_ivan/Build"

# Include any dependencies generated for this target.
include src/GUI/CMakeFiles/gui.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/GUI/CMakeFiles/gui.dir/compiler_depend.make

# Include the progress variables for this target.
include src/GUI/CMakeFiles/gui.dir/progress.make

# Include the compile flags for this target's objects.
include src/GUI/CMakeFiles/gui.dir/flags.make

src/GUI/CMakeFiles/gui.dir/gui.cc.o: src/GUI/CMakeFiles/gui.dir/flags.make
src/GUI/CMakeFiles/gui.dir/gui.cc.o: ../src/GUI/gui.cc
src/GUI/CMakeFiles/gui.dir/gui.cc.o: src/GUI/CMakeFiles/gui.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ivan/Рабочий стол/unitest-st_ivan/Build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/GUI/CMakeFiles/gui.dir/gui.cc.o"
	cd "/home/ivan/Рабочий стол/unitest-st_ivan/Build/src/GUI" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/GUI/CMakeFiles/gui.dir/gui.cc.o -MF CMakeFiles/gui.dir/gui.cc.o.d -o CMakeFiles/gui.dir/gui.cc.o -c "/home/ivan/Рабочий стол/unitest-st_ivan/src/GUI/gui.cc"

src/GUI/CMakeFiles/gui.dir/gui.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gui.dir/gui.cc.i"
	cd "/home/ivan/Рабочий стол/unitest-st_ivan/Build/src/GUI" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ivan/Рабочий стол/unitest-st_ivan/src/GUI/gui.cc" > CMakeFiles/gui.dir/gui.cc.i

src/GUI/CMakeFiles/gui.dir/gui.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gui.dir/gui.cc.s"
	cd "/home/ivan/Рабочий стол/unitest-st_ivan/Build/src/GUI" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ivan/Рабочий стол/unitest-st_ivan/src/GUI/gui.cc" -o CMakeFiles/gui.dir/gui.cc.s

# Object files for target gui
gui_OBJECTS = \
"CMakeFiles/gui.dir/gui.cc.o"

# External object files for target gui
gui_EXTERNAL_OBJECTS =

src/GUI/gui: src/GUI/CMakeFiles/gui.dir/gui.cc.o
src/GUI/gui: src/GUI/CMakeFiles/gui.dir/build.make
src/GUI/gui: src/GUI/CMakeFiles/gui.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/ivan/Рабочий стол/unitest-st_ivan/Build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable gui"
	cd "/home/ivan/Рабочий стол/unitest-st_ivan/Build/src/GUI" && /usr/bin/cmake -E copy_directory /home/ivan/Рабочий\ стол/unitest-st_ivan/src/GUI/svg /home/ivan/Рабочий\ стол/unitest-st_ivan/Build/src/GUI/svg
	cd "/home/ivan/Рабочий стол/unitest-st_ivan/Build/src/GUI" && /usr/bin/cmake -E copy /home/ivan/Рабочий\ стол/unitest-st_ivan/src/GUI/test.glade /home/ivan/Рабочий\ стол/unitest-st_ivan/Build/src/GUI
	cd "/home/ivan/Рабочий стол/unitest-st_ivan/Build/src/GUI" && /usr/bin/cmake -E copy /home/ivan/Рабочий\ стол/unitest-st_ivan/src/GUI/configure.xml /home/ivan/Рабочий\ стол/unitest-st_ivan/Build/src/GUI
	cd "/home/ivan/Рабочий стол/unitest-st_ivan/Build/src/GUI" && /usr/bin/cmake -E copy /home/ivan/Рабочий\ стол/unitest-st_ivan/src/GUI/start_fg.sh /home/ivan/Рабочий\ стол/unitest-st_ivan/Build/src/GUI
	cd "/home/ivan/Рабочий стол/unitest-st_ivan/Build/src/GUI" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gui.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/GUI/CMakeFiles/gui.dir/build: src/GUI/gui
.PHONY : src/GUI/CMakeFiles/gui.dir/build

src/GUI/CMakeFiles/gui.dir/clean:
	cd "/home/ivan/Рабочий стол/unitest-st_ivan/Build/src/GUI" && $(CMAKE_COMMAND) -P CMakeFiles/gui.dir/cmake_clean.cmake
.PHONY : src/GUI/CMakeFiles/gui.dir/clean

src/GUI/CMakeFiles/gui.dir/depend:
	cd "/home/ivan/Рабочий стол/unitest-st_ivan/Build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/ivan/Рабочий стол/unitest-st_ivan" "/home/ivan/Рабочий стол/unitest-st_ivan/src/GUI" "/home/ivan/Рабочий стол/unitest-st_ivan/Build" "/home/ivan/Рабочий стол/unitest-st_ivan/Build/src/GUI" "/home/ivan/Рабочий стол/unitest-st_ivan/Build/src/GUI/CMakeFiles/gui.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : src/GUI/CMakeFiles/gui.dir/depend
