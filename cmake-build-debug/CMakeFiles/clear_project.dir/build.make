# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /cygdrive/c/Users/Bohdan/AppData/Local/JetBrains/CLion2020.2/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/Bohdan/AppData/Local/JetBrains/CLion2020.2/cygwin_cmake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/d/GitKraken/convex_hull

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/d/GitKraken/convex_hull/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/clear_project.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/clear_project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/clear_project.dir/flags.make

CMakeFiles/clear_project.dir/main.cpp.o: CMakeFiles/clear_project.dir/flags.make
CMakeFiles/clear_project.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/d/GitKraken/convex_hull/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/clear_project.dir/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/clear_project.dir/main.cpp.o -c /cygdrive/d/GitKraken/convex_hull/main.cpp

CMakeFiles/clear_project.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/clear_project.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/d/GitKraken/convex_hull/main.cpp > CMakeFiles/clear_project.dir/main.cpp.i

CMakeFiles/clear_project.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/clear_project.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/d/GitKraken/convex_hull/main.cpp -o CMakeFiles/clear_project.dir/main.cpp.s

# Object files for target clear_project
clear_project_OBJECTS = \
"CMakeFiles/clear_project.dir/main.cpp.o"

# External object files for target clear_project
clear_project_EXTERNAL_OBJECTS =

clear_project.exe: CMakeFiles/clear_project.dir/main.cpp.o
clear_project.exe: CMakeFiles/clear_project.dir/build.make
clear_project.exe: CMakeFiles/clear_project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/d/GitKraken/convex_hull/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable clear_project.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/clear_project.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/clear_project.dir/build: clear_project.exe

.PHONY : CMakeFiles/clear_project.dir/build

CMakeFiles/clear_project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/clear_project.dir/cmake_clean.cmake
.PHONY : CMakeFiles/clear_project.dir/clean

CMakeFiles/clear_project.dir/depend:
	cd /cygdrive/d/GitKraken/convex_hull/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/d/GitKraken/convex_hull /cygdrive/d/GitKraken/convex_hull /cygdrive/d/GitKraken/convex_hull/cmake-build-debug /cygdrive/d/GitKraken/convex_hull/cmake-build-debug /cygdrive/d/GitKraken/convex_hull/cmake-build-debug/CMakeFiles/clear_project.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/clear_project.dir/depend

