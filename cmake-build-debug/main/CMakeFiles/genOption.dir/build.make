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
CMAKE_SOURCE_DIR = /home/hzx/pmvs2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hzx/pmvs2/cmake-build-debug

# Include any dependencies generated for this target.
include main/CMakeFiles/genOption.dir/depend.make

# Include the progress variables for this target.
include main/CMakeFiles/genOption.dir/progress.make

# Include the compile flags for this target's objects.
include main/CMakeFiles/genOption.dir/flags.make

main/CMakeFiles/genOption.dir/genOption.cc.o: main/CMakeFiles/genOption.dir/flags.make
main/CMakeFiles/genOption.dir/genOption.cc.o: ../main/genOption.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hzx/pmvs2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object main/CMakeFiles/genOption.dir/genOption.cc.o"
	cd /home/hzx/pmvs2/cmake-build-debug/main && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/genOption.dir/genOption.cc.o -c /home/hzx/pmvs2/main/genOption.cc

main/CMakeFiles/genOption.dir/genOption.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/genOption.dir/genOption.cc.i"
	cd /home/hzx/pmvs2/cmake-build-debug/main && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hzx/pmvs2/main/genOption.cc > CMakeFiles/genOption.dir/genOption.cc.i

main/CMakeFiles/genOption.dir/genOption.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/genOption.dir/genOption.cc.s"
	cd /home/hzx/pmvs2/cmake-build-debug/main && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hzx/pmvs2/main/genOption.cc -o CMakeFiles/genOption.dir/genOption.cc.s

# Object files for target genOption
genOption_OBJECTS = \
"CMakeFiles/genOption.dir/genOption.cc.o"

# External object files for target genOption
genOption_EXTERNAL_OBJECTS =

main/genOption: main/CMakeFiles/genOption.dir/genOption.cc.o
main/genOption: main/CMakeFiles/genOption.dir/build.make
main/genOption: main/CMakeFiles/genOption.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hzx/pmvs2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable genOption"
	cd /home/hzx/pmvs2/cmake-build-debug/main && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/genOption.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
main/CMakeFiles/genOption.dir/build: main/genOption

.PHONY : main/CMakeFiles/genOption.dir/build

main/CMakeFiles/genOption.dir/clean:
	cd /home/hzx/pmvs2/cmake-build-debug/main && $(CMAKE_COMMAND) -P CMakeFiles/genOption.dir/cmake_clean.cmake
.PHONY : main/CMakeFiles/genOption.dir/clean

main/CMakeFiles/genOption.dir/depend:
	cd /home/hzx/pmvs2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hzx/pmvs2 /home/hzx/pmvs2/main /home/hzx/pmvs2/cmake-build-debug /home/hzx/pmvs2/cmake-build-debug/main /home/hzx/pmvs2/cmake-build-debug/main/CMakeFiles/genOption.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : main/CMakeFiles/genOption.dir/depend

