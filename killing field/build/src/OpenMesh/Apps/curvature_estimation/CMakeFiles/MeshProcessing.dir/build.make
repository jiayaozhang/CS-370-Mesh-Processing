# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build

# Include any dependencies generated for this target.
include src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/depend.make

# Include the progress variables for this target.
include src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/progress.make

# Include the compile flags for this target's objects.
include src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/flags.make

src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/main.cc.o: src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/flags.make
src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/main.cc.o: ../src/OpenMesh/Apps/curvature_estimation/main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/main.cc.o"
	cd /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/src/OpenMesh/Apps/curvature_estimation && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MeshProcessing.dir/main.cc.o -c /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/src/OpenMesh/Apps/curvature_estimation/main.cc

src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MeshProcessing.dir/main.cc.i"
	cd /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/src/OpenMesh/Apps/curvature_estimation && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/src/OpenMesh/Apps/curvature_estimation/main.cc > CMakeFiles/MeshProcessing.dir/main.cc.i

src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MeshProcessing.dir/main.cc.s"
	cd /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/src/OpenMesh/Apps/curvature_estimation && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/src/OpenMesh/Apps/curvature_estimation/main.cc -o CMakeFiles/MeshProcessing.dir/main.cc.s

src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/main.cc.o.requires:

.PHONY : src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/main.cc.o.requires

src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/main.cc.o.provides: src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/main.cc.o.requires
	$(MAKE) -f src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/build.make src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/main.cc.o.provides.build
.PHONY : src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/main.cc.o.provides

src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/main.cc.o.provides.build: src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/main.cc.o


src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/MeshProcessing_autogen/mocs_compilation.cpp.o: src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/flags.make
src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/MeshProcessing_autogen/mocs_compilation.cpp.o: src/OpenMesh/Apps/curvature_estimation/MeshProcessing_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/MeshProcessing_autogen/mocs_compilation.cpp.o"
	cd /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/src/OpenMesh/Apps/curvature_estimation && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MeshProcessing.dir/MeshProcessing_autogen/mocs_compilation.cpp.o -c /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/src/OpenMesh/Apps/curvature_estimation/MeshProcessing_autogen/mocs_compilation.cpp

src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/MeshProcessing_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MeshProcessing.dir/MeshProcessing_autogen/mocs_compilation.cpp.i"
	cd /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/src/OpenMesh/Apps/curvature_estimation && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/src/OpenMesh/Apps/curvature_estimation/MeshProcessing_autogen/mocs_compilation.cpp > CMakeFiles/MeshProcessing.dir/MeshProcessing_autogen/mocs_compilation.cpp.i

src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/MeshProcessing_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MeshProcessing.dir/MeshProcessing_autogen/mocs_compilation.cpp.s"
	cd /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/src/OpenMesh/Apps/curvature_estimation && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/src/OpenMesh/Apps/curvature_estimation/MeshProcessing_autogen/mocs_compilation.cpp -o CMakeFiles/MeshProcessing.dir/MeshProcessing_autogen/mocs_compilation.cpp.s

src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/MeshProcessing_autogen/mocs_compilation.cpp.o.requires:

.PHONY : src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/MeshProcessing_autogen/mocs_compilation.cpp.o.requires

src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/MeshProcessing_autogen/mocs_compilation.cpp.o.provides: src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/MeshProcessing_autogen/mocs_compilation.cpp.o.requires
	$(MAKE) -f src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/build.make src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/MeshProcessing_autogen/mocs_compilation.cpp.o.provides.build
.PHONY : src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/MeshProcessing_autogen/mocs_compilation.cpp.o.provides

src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/MeshProcessing_autogen/mocs_compilation.cpp.o.provides.build: src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/MeshProcessing_autogen/mocs_compilation.cpp.o


# Object files for target MeshProcessing
MeshProcessing_OBJECTS = \
"CMakeFiles/MeshProcessing.dir/main.cc.o" \
"CMakeFiles/MeshProcessing.dir/MeshProcessing_autogen/mocs_compilation.cpp.o"

# External object files for target MeshProcessing
MeshProcessing_EXTERNAL_OBJECTS =

Build/bin/MeshProcessing: src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/main.cc.o
Build/bin/MeshProcessing: src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/MeshProcessing_autogen/mocs_compilation.cpp.o
Build/bin/MeshProcessing: src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/build.make
Build/bin/MeshProcessing: Build/lib/libOpenMeshTools.so.8.0
Build/bin/MeshProcessing: /usr/lib/x86_64-linux-gnu/libGL.so
Build/bin/MeshProcessing: src/OpenMesh/Apps/curvature_estimation/libimguizmo.a
Build/bin/MeshProcessing: src/OpenMesh/Apps/curvature_estimation/imgui/libimgui.a
Build/bin/MeshProcessing: src/OpenMesh/Apps/curvature_estimation/glad/libglad.a
Build/bin/MeshProcessing: src/OpenMesh/Apps/curvature_estimation/glfw/src/libglfw3.a
Build/bin/MeshProcessing: /usr/lib/x86_64-linux-gnu/librt.so
Build/bin/MeshProcessing: /usr/lib/x86_64-linux-gnu/libm.so
Build/bin/MeshProcessing: /usr/lib/x86_64-linux-gnu/libX11.so
Build/bin/MeshProcessing: Build/lib/libOpenMeshCore.so.8.0
Build/bin/MeshProcessing: src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../../../../Build/bin/MeshProcessing"
	cd /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/src/OpenMesh/Apps/curvature_estimation && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MeshProcessing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/build: Build/bin/MeshProcessing

.PHONY : src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/build

src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/requires: src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/main.cc.o.requires
src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/requires: src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/MeshProcessing_autogen/mocs_compilation.cpp.o.requires

.PHONY : src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/requires

src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/clean:
	cd /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/src/OpenMesh/Apps/curvature_estimation && $(CMAKE_COMMAND) -P CMakeFiles/MeshProcessing.dir/cmake_clean.cmake
.PHONY : src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/clean

src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/depend:
	cd /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/src/OpenMesh/Apps/curvature_estimation /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/src/OpenMesh/Apps/curvature_estimation /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/OpenMesh/Apps/curvature_estimation/CMakeFiles/MeshProcessing.dir/depend
