# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/emile/devel/pgms_repo/week4/cluster_hamming_loop

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/emile/devel/pgms_repo/week4/cluster_hamming_loop/build

# Include any dependencies generated for this target.
include src/CMakeFiles/cluster_hamming_loop.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/cluster_hamming_loop.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/cluster_hamming_loop.dir/flags.make

src/CMakeFiles/cluster_hamming_loop.dir/cluster_hamming_loop.cc.o: src/CMakeFiles/cluster_hamming_loop.dir/flags.make
src/CMakeFiles/cluster_hamming_loop.dir/cluster_hamming_loop.cc.o: ../src/cluster_hamming_loop.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/emile/devel/pgms_repo/week4/cluster_hamming_loop/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/cluster_hamming_loop.dir/cluster_hamming_loop.cc.o"
	cd /home/emile/devel/pgms_repo/week4/cluster_hamming_loop/build/src && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cluster_hamming_loop.dir/cluster_hamming_loop.cc.o -c /home/emile/devel/pgms_repo/week4/cluster_hamming_loop/src/cluster_hamming_loop.cc

src/CMakeFiles/cluster_hamming_loop.dir/cluster_hamming_loop.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cluster_hamming_loop.dir/cluster_hamming_loop.cc.i"
	cd /home/emile/devel/pgms_repo/week4/cluster_hamming_loop/build/src && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/emile/devel/pgms_repo/week4/cluster_hamming_loop/src/cluster_hamming_loop.cc > CMakeFiles/cluster_hamming_loop.dir/cluster_hamming_loop.cc.i

src/CMakeFiles/cluster_hamming_loop.dir/cluster_hamming_loop.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cluster_hamming_loop.dir/cluster_hamming_loop.cc.s"
	cd /home/emile/devel/pgms_repo/week4/cluster_hamming_loop/build/src && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/emile/devel/pgms_repo/week4/cluster_hamming_loop/src/cluster_hamming_loop.cc -o CMakeFiles/cluster_hamming_loop.dir/cluster_hamming_loop.cc.s

# Object files for target cluster_hamming_loop
cluster_hamming_loop_OBJECTS = \
"CMakeFiles/cluster_hamming_loop.dir/cluster_hamming_loop.cc.o"

# External object files for target cluster_hamming_loop
cluster_hamming_loop_EXTERNAL_OBJECTS =

src/cluster_hamming_loop: src/CMakeFiles/cluster_hamming_loop.dir/cluster_hamming_loop.cc.o
src/cluster_hamming_loop: src/CMakeFiles/cluster_hamming_loop.dir/build.make
src/cluster_hamming_loop: /home/emile/bin/libgLinear.so
src/cluster_hamming_loop: /home/emile/devel/emdw/build/src/libemdw.so
src/cluster_hamming_loop: /home/emile/devel/prlite/build/src/libprlite.so
src/cluster_hamming_loop: src/CMakeFiles/cluster_hamming_loop.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/emile/devel/pgms_repo/week4/cluster_hamming_loop/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cluster_hamming_loop"
	cd /home/emile/devel/pgms_repo/week4/cluster_hamming_loop/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cluster_hamming_loop.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/cluster_hamming_loop.dir/build: src/cluster_hamming_loop

.PHONY : src/CMakeFiles/cluster_hamming_loop.dir/build

src/CMakeFiles/cluster_hamming_loop.dir/clean:
	cd /home/emile/devel/pgms_repo/week4/cluster_hamming_loop/build/src && $(CMAKE_COMMAND) -P CMakeFiles/cluster_hamming_loop.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/cluster_hamming_loop.dir/clean

src/CMakeFiles/cluster_hamming_loop.dir/depend:
	cd /home/emile/devel/pgms_repo/week4/cluster_hamming_loop/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/emile/devel/pgms_repo/week4/cluster_hamming_loop /home/emile/devel/pgms_repo/week4/cluster_hamming_loop/src /home/emile/devel/pgms_repo/week4/cluster_hamming_loop/build /home/emile/devel/pgms_repo/week4/cluster_hamming_loop/build/src /home/emile/devel/pgms_repo/week4/cluster_hamming_loop/build/src/CMakeFiles/cluster_hamming_loop.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/cluster_hamming_loop.dir/depend

