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
include main/CMakeFiles/pmvs2.dir/depend.make

# Include the progress variables for this target.
include main/CMakeFiles/pmvs2.dir/progress.make

# Include the compile flags for this target's objects.
include main/CMakeFiles/pmvs2.dir/flags.make

main/CMakeFiles/pmvs2.dir/pmvs2.cc.o: main/CMakeFiles/pmvs2.dir/flags.make
main/CMakeFiles/pmvs2.dir/pmvs2.cc.o: ../main/pmvs2.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hzx/pmvs2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object main/CMakeFiles/pmvs2.dir/pmvs2.cc.o"
	cd /home/hzx/pmvs2/cmake-build-debug/main && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pmvs2.dir/pmvs2.cc.o -c /home/hzx/pmvs2/main/pmvs2.cc

main/CMakeFiles/pmvs2.dir/pmvs2.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pmvs2.dir/pmvs2.cc.i"
	cd /home/hzx/pmvs2/cmake-build-debug/main && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hzx/pmvs2/main/pmvs2.cc > CMakeFiles/pmvs2.dir/pmvs2.cc.i

main/CMakeFiles/pmvs2.dir/pmvs2.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pmvs2.dir/pmvs2.cc.s"
	cd /home/hzx/pmvs2/cmake-build-debug/main && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hzx/pmvs2/main/pmvs2.cc -o CMakeFiles/pmvs2.dir/pmvs2.cc.s

# Object files for target pmvs2
pmvs2_OBJECTS = \
"CMakeFiles/pmvs2.dir/pmvs2.cc.o"

# External object files for target pmvs2
pmvs2_EXTERNAL_OBJECTS =

main/pmvs2: main/CMakeFiles/pmvs2.dir/pmvs2.cc.o
main/pmvs2: main/CMakeFiles/pmvs2.dir/build.make
main/pmvs2: base/pmvs/libpmvs_lib.a
main/pmvs2: base/image/libimage_lib.a
main/pmvs2: base/numeric/libnumeric_lib.a
main/pmvs2: /usr/lib/x86_64-linux-gnu/libjpeg.so
main/pmvs2: thirdParty/nlopt-2.4.2/libnlopt.a
main/pmvs2: thirdParty/tinycthread/libtinycthread.a
main/pmvs2: /usr/local/lib/libopencv_dnn.so.3.4.2
main/pmvs2: /usr/local/lib/libopencv_ml.so.3.4.2
main/pmvs2: /usr/local/lib/libopencv_objdetect.so.3.4.2
main/pmvs2: /usr/local/lib/libopencv_shape.so.3.4.2
main/pmvs2: /usr/local/lib/libopencv_stitching.so.3.4.2
main/pmvs2: /usr/local/lib/libopencv_superres.so.3.4.2
main/pmvs2: /usr/local/lib/libopencv_videostab.so.3.4.2
main/pmvs2: /usr/local/lib/libopencv_viz.so.3.4.2
main/pmvs2: /usr/local/lib/libopencv_calib3d.so.3.4.2
main/pmvs2: /usr/local/lib/libopencv_features2d.so.3.4.2
main/pmvs2: /usr/local/lib/libopencv_flann.so.3.4.2
main/pmvs2: /usr/local/lib/libopencv_highgui.so.3.4.2
main/pmvs2: /usr/local/lib/libopencv_photo.so.3.4.2
main/pmvs2: /usr/local/lib/libopencv_video.so.3.4.2
main/pmvs2: /usr/local/lib/libopencv_videoio.so.3.4.2
main/pmvs2: /usr/local/lib/libopencv_imgcodecs.so.3.4.2
main/pmvs2: /usr/local/lib/libopencv_imgproc.so.3.4.2
main/pmvs2: /usr/local/lib/libopencv_core.so.3.4.2
main/pmvs2: main/CMakeFiles/pmvs2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hzx/pmvs2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable pmvs2"
	cd /home/hzx/pmvs2/cmake-build-debug/main && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pmvs2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
main/CMakeFiles/pmvs2.dir/build: main/pmvs2

.PHONY : main/CMakeFiles/pmvs2.dir/build

main/CMakeFiles/pmvs2.dir/clean:
	cd /home/hzx/pmvs2/cmake-build-debug/main && $(CMAKE_COMMAND) -P CMakeFiles/pmvs2.dir/cmake_clean.cmake
.PHONY : main/CMakeFiles/pmvs2.dir/clean

main/CMakeFiles/pmvs2.dir/depend:
	cd /home/hzx/pmvs2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hzx/pmvs2 /home/hzx/pmvs2/main /home/hzx/pmvs2/cmake-build-debug /home/hzx/pmvs2/cmake-build-debug/main /home/hzx/pmvs2/cmake-build-debug/main/CMakeFiles/pmvs2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : main/CMakeFiles/pmvs2.dir/depend
