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
CMAKE_COMMAND = /home/zhangj0o/Documents/apps/CLion-2020.2.4/clion-2020.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/zhangj0o/Documents/apps/CLion-2020.2.4/clion-2020.2.4/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/cmake-build-debug

# Include any dependencies generated for this target.
include src/OpenMesh/Apps/curvature_estimation/glad/CMakeFiles/glad.dir/depend.make

# Include the progress variables for this target.
include src/OpenMesh/Apps/curvature_estimation/glad/CMakeFiles/glad.dir/progress.make

# Include the compile flags for this target's objects.
include src/OpenMesh/Apps/curvature_estimation/glad/CMakeFiles/glad.dir/flags.make

src/OpenMesh/Apps/curvature_estimation/glad/CMakeFiles/glad.dir/glad_autogen/mocs_compilation.cpp.o: src/OpenMesh/Apps/curvature_estimation/glad/CMakeFiles/glad.dir/flags.make
src/OpenMesh/Apps/curvature_estimation/glad/CMakeFiles/glad.dir/glad_autogen/mocs_compilation.cpp.o: src/OpenMesh/Apps/curvature_estimation/glad/glad_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/OpenMesh/Apps/curvature_estimation/glad/CMakeFiles/glad.dir/glad_autogen/mocs_compilation.cpp.o"
	cd /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/cmake-build-debug/src/OpenMesh/Apps/curvature_estimation/glad && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/glad.dir/glad_autogen/mocs_compilation.cpp.o -c /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/cmake-build-debug/src/OpenMesh/Apps/curvature_estimation/glad/glad_autogen/mocs_compilation.cpp

src/OpenMesh/Apps/curvature_estimation/glad/CMakeFiles/glad.dir/glad_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/glad.dir/glad_autogen/mocs_compilation.cpp.i"
	cd /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/cmake-build-debug/src/OpenMesh/Apps/curvature_estimation/glad && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/cmake-build-debug/src/OpenMesh/Apps/curvature_estimation/glad/glad_autogen/mocs_compilation.cpp > CMakeFiles/glad.dir/glad_autogen/mocs_compilation.cpp.i

src/OpenMesh/Apps/curvature_estimation/glad/CMakeFiles/glad.dir/glad_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/glad.dir/glad_autogen/mocs_compilation.cpp.s"
	cd /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/cmake-build-debug/src/OpenMesh/Apps/curvature_estimation/glad && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/cmake-build-debug/src/OpenMesh/Apps/curvature_estimation/glad/glad_autogen/mocs_compilation.cpp -o CMakeFiles/glad.dir/glad_autogen/mocs_compilation.cpp.s

src/OpenMesh/Apps/curvature_estimation/glad/CMakeFiles/glad.dir/src/glad.c.o: src/OpenMesh/Apps/curvature_estimation/glad/CMakeFiles/glad.dir/flags.make
src/OpenMesh/Apps/curvature_estimation/glad/CMakeFiles/glad.dir/src/glad.c.o: /home/zhangj0o/Documents/codefiles/libigl/external/glad/src/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/OpenMesh/Apps/curvature_estimation/glad/CMakeFiles/glad.dir/src/glad.c.o"
	cd /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/cmake-build-debug/src/OpenMesh/Apps/curvature_estimation/glad && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glad.dir/src/glad.c.o   -c /home/zhangj0o/Documents/codefiles/libigl/external/glad/src/glad.c

src/OpenMesh/Apps/curvature_estimation/glad/CMakeFiles/glad.dir/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glad.dir/src/glad.c.i"
	cd /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/cmake-build-debug/src/OpenMesh/Apps/curvature_estimation/glad && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/zhangj0o/Documents/codefiles/libigl/external/glad/src/glad.c > CMakeFiles/glad.dir/src/glad.c.i

src/OpenMesh/Apps/curvature_estimation/glad/CMakeFiles/glad.dir/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glad.dir/src/glad.c.s"
	cd /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/cmake-build-debug/src/OpenMesh/Apps/curvature_estimation/glad && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/zhangj0o/Documents/codefiles/libigl/external/glad/src/glad.c -o CMakeFiles/glad.dir/src/glad.c.s

# Object files for target glad
glad_OBJECTS = \
"CMakeFiles/glad.dir/glad_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/glad.dir/src/glad.c.o"

# External object files for target glad
glad_EXTERNAL_OBJECTS =

src/OpenMesh/Apps/curvature_estimation/glad/libgladd.a: src/OpenMesh/Apps/curvature_estimation/glad/CMakeFiles/glad.dir/glad_autogen/mocs_compilation.cpp.o
src/OpenMesh/Apps/curvature_estimation/glad/libgladd.a: src/OpenMesh/Apps/curvature_estimation/glad/CMakeFiles/glad.dir/src/glad.c.o
src/OpenMesh/Apps/curvature_estimation/glad/libgladd.a: src/OpenMesh/Apps/curvature_estimation/glad/CMakeFiles/glad.dir/build.make
src/OpenMesh/Apps/curvature_estimation/glad/libgladd.a: src/OpenMesh/Apps/curvature_estimation/glad/CMakeFiles/glad.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libgladd.a"
	cd /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/cmake-build-debug/src/OpenMesh/Apps/curvature_estimation/glad && $(CMAKE_COMMAND) -P CMakeFiles/glad.dir/cmake_clean_target.cmake
	cd /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/cmake-build-debug/src/OpenMesh/Apps/curvature_estimation/glad && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glad.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/OpenMesh/Apps/curvature_estimation/glad/CMakeFiles/glad.dir/build: src/OpenMesh/Apps/curvature_estimation/glad/libgladd.a

.PHONY : src/OpenMesh/Apps/curvature_estimation/glad/CMakeFiles/glad.dir/build

src/OpenMesh/Apps/curvature_estimation/glad/CMakeFiles/glad.dir/clean:
	cd /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/cmake-build-debug/src/OpenMesh/Apps/curvature_estimation/glad && $(CMAKE_COMMAND) -P CMakeFiles/glad.dir/cmake_clean.cmake
.PHONY : src/OpenMesh/Apps/curvature_estimation/glad/CMakeFiles/glad.dir/clean

src/OpenMesh/Apps/curvature_estimation/glad/CMakeFiles/glad.dir/depend:
	cd /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation /home/zhangj0o/Documents/codefiles/libigl/external/glad /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/cmake-build-debug /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/cmake-build-debug/src/OpenMesh/Apps/curvature_estimation/glad /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/cmake-build-debug/src/OpenMesh/Apps/curvature_estimation/glad/CMakeFiles/glad.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/OpenMesh/Apps/curvature_estimation/glad/CMakeFiles/glad.dir/depend

