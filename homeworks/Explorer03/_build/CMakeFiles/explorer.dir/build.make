# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.9.3_1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.9.3_1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/macbook/workspace/homework/hw03(ex)"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/macbook/workspace/homework/hw03(ex)/_build"

# Include any dependencies generated for this target.
include CMakeFiles/explorer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/explorer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/explorer.dir/flags.make

CMakeFiles/explorer.dir/sources/explorer.cpp.o: CMakeFiles/explorer.dir/flags.make
CMakeFiles/explorer.dir/sources/explorer.cpp.o: ../sources/explorer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/macbook/workspace/homework/hw03(ex)/_build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/explorer.dir/sources/explorer.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/explorer.dir/sources/explorer.cpp.o -c "/Users/macbook/workspace/homework/hw03(ex)/sources/explorer.cpp"

CMakeFiles/explorer.dir/sources/explorer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/explorer.dir/sources/explorer.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/macbook/workspace/homework/hw03(ex)/sources/explorer.cpp" > CMakeFiles/explorer.dir/sources/explorer.cpp.i

CMakeFiles/explorer.dir/sources/explorer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/explorer.dir/sources/explorer.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/macbook/workspace/homework/hw03(ex)/sources/explorer.cpp" -o CMakeFiles/explorer.dir/sources/explorer.cpp.s

CMakeFiles/explorer.dir/sources/explorer.cpp.o.requires:

.PHONY : CMakeFiles/explorer.dir/sources/explorer.cpp.o.requires

CMakeFiles/explorer.dir/sources/explorer.cpp.o.provides: CMakeFiles/explorer.dir/sources/explorer.cpp.o.requires
	$(MAKE) -f CMakeFiles/explorer.dir/build.make CMakeFiles/explorer.dir/sources/explorer.cpp.o.provides.build
.PHONY : CMakeFiles/explorer.dir/sources/explorer.cpp.o.provides

CMakeFiles/explorer.dir/sources/explorer.cpp.o.provides.build: CMakeFiles/explorer.dir/sources/explorer.cpp.o


# Object files for target explorer
explorer_OBJECTS = \
"CMakeFiles/explorer.dir/sources/explorer.cpp.o"

# External object files for target explorer
explorer_EXTERNAL_OBJECTS =

libexplorer.a: CMakeFiles/explorer.dir/sources/explorer.cpp.o
libexplorer.a: CMakeFiles/explorer.dir/build.make
libexplorer.a: CMakeFiles/explorer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/macbook/workspace/homework/hw03(ex)/_build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libexplorer.a"
	$(CMAKE_COMMAND) -P CMakeFiles/explorer.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/explorer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/explorer.dir/build: libexplorer.a

.PHONY : CMakeFiles/explorer.dir/build

CMakeFiles/explorer.dir/requires: CMakeFiles/explorer.dir/sources/explorer.cpp.o.requires

.PHONY : CMakeFiles/explorer.dir/requires

CMakeFiles/explorer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/explorer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/explorer.dir/clean

CMakeFiles/explorer.dir/depend:
	cd "/Users/macbook/workspace/homework/hw03(ex)/_build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/macbook/workspace/homework/hw03(ex)" "/Users/macbook/workspace/homework/hw03(ex)" "/Users/macbook/workspace/homework/hw03(ex)/_build" "/Users/macbook/workspace/homework/hw03(ex)/_build" "/Users/macbook/workspace/homework/hw03(ex)/_build/CMakeFiles/explorer.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/explorer.dir/depend

