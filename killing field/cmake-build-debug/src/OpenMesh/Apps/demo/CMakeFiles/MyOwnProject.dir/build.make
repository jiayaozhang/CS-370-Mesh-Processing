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
CMAKE_COMMAND = /home/qiang/softwares/clion-2019.2.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/qiang/softwares/clion-2019.2.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/qiang/Documents/codefiles/geo/OpenMesh-8.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/qiang/Documents/codefiles/geo/OpenMesh-8.0/cmake-build-debug

# Include any dependencies generated for this target.
include src/OpenMesh/Apps/demo/CMakeFiles/MyOwnProject.dir/depend.make

# Include the progress variables for this target.
include src/OpenMesh/Apps/demo/CMakeFiles/MyOwnProject.dir/progress.make

# Include the compile flags for this target's objects.
include src/OpenMesh/Apps/demo/CMakeFiles/MyOwnProject.dir/flags.make

src/OpenMesh/Apps/demo/CMakeFiles/MyOwnProject.dir/MyOwnProject_autogen/mocs_compilation.cpp.o: src/OpenMesh/Apps/demo/CMakeFiles/MyOwnProject.dir/flags.make
src/OpenMesh/Apps/demo/CMakeFiles/MyOwnProject.dir/MyOwnProject_autogen/mocs_compilation.cpp.o: src/OpenMesh/Apps/demo/MyOwnProject_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qiang/Documents/codefiles/geo/OpenMesh-8.0/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/OpenMesh/Apps/demo/CMakeFiles/MyOwnProject.dir/MyOwnProject_autogen/mocs_compilation.cpp.o"
	cd /home/qiang/Documents/codefiles/geo/OpenMesh-8.0/cmake-build-debug/src/OpenMesh/Apps/demo && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyOwnProject.dir/MyOwnProject_autogen/mocs_compilation.cpp.o -c /home/qiang/Documents/codefiles/geo/OpenMesh-8.0/cmake-build-debug/src/OpenMesh/Apps/demo/MyOwnProject_autogen/mocs_compilation.cpp

src/OpenMesh/Apps/demo/CMakeFiles/MyOwnProject.dir/MyOwnProject_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyOwnProject.dir/MyOwnProject_autogen/mocs_compilation.cpp.i"
	cd /home/qiang/Documents/codefiles/geo/OpenMesh-8.0/cmake-build-debug/src/OpenMesh/Apps/demo && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qiang/Documents/codefiles/geo/OpenMesh-8.0/cmake-build-debug/src/OpenMesh/Apps/demo/MyOwnProject_autogen/mocs_compilation.cpp > CMakeFiles/MyOwnProject.dir/MyOwnProject_autogen/mocs_compilation.cpp.i

src/OpenMesh/Apps/demo/CMakeFiles/MyOwnProject.dir/MyOwnProject_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyOwnProject.dir/MyOwnProject_autogen/mocs_compilation.cpp.s"
	cd /home/qiang/Documents/codefiles/geo/OpenMesh-8.0/cmake-build-debug/src/OpenMesh/Apps/demo && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qiang/Documents/codefiles/geo/OpenMesh-8.0/cmake-build-debug/src/OpenMesh/Apps/demo/MyOwnProject_autogen/mocs_compilation.cpp -o CMakeFiles/MyOwnProject.dir/MyOwnProject_autogen/mocs_compilation.cpp.s

src/OpenMesh/Apps/demo/CMakeFiles/MyOwnProject.dir/main.cc.o: src/OpenMesh/Apps/demo/CMakeFiles/MyOwnProject.dir/flags.make
src/OpenMesh/Apps/demo/CMakeFiles/MyOwnProject.dir/main.cc.o: ../src/OpenMesh/Apps/demo/main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qiang/Documents/codefiles/geo/OpenMesh-8.0/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/OpenMesh/Apps/demo/CMakeFiles/MyOwnProject.dir/main.cc.o"
	cd /home/qiang/Documents/codefiles/geo/OpenMesh-8.0/cmake-build-debug/src/OpenMesh/Apps/demo && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyOwnProject.dir/main.cc.o -c /home/qiang/Documents/codefiles/geo/OpenMesh-8.0/src/OpenMesh/Apps/demo/main.cc

src/OpenMesh/Apps/demo/CMakeFiles/MyOwnProject.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyOwnProject.dir/main.cc.i"
	cd /home/qiang/Documents/codefiles/geo/OpenMesh-8.0/cmake-build-debug/src/OpenMesh/Apps/demo && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qiang/Documents/codefiles/geo/OpenMesh-8.0/src/OpenMesh/Apps/demo/main.cc > CMakeFiles/MyOwnProject.dir/main.cc.i

src/OpenMesh/Apps/demo/CMakeFiles/MyOwnProject.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyOwnProject.dir/main.cc.s"
	cd /home/qiang/Documents/codefiles/geo/OpenMesh-8.0/cmake-build-debug/src/OpenMesh/Apps/demo && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qiang/Documents/codefiles/geo/OpenMesh-8.0/src/OpenMesh/Apps/demo/main.cc -o CMakeFiles/MyOwnProject.dir/main.cc.s

# Object files for target MyOwnProject
MyOwnProject_OBJECTS = \
"CMakeFiles/MyOwnProject.dir/MyOwnProject_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/MyOwnProject.dir/main.cc.o"

# External object files for target MyOwnProject
MyOwnProject_EXTERNAL_OBJECTS =

Build/bin/MyOwnProject: src/OpenMesh/Apps/demo/CMakeFiles/MyOwnProject.dir/MyOwnProject_autogen/mocs_compilation.cpp.o
Build/bin/MyOwnProject: src/OpenMesh/Apps/demo/CMakeFiles/MyOwnProject.dir/main.cc.o
Build/bin/MyOwnProject: src/OpenMesh/Apps/demo/CMakeFiles/MyOwnProject.dir/build.make
Build/bin/MyOwnProject: Build/lib/libOpenMeshToolsd.so.8.0
Build/bin/MyOwnProject: /usr/lib/x86_64-linux-gnu/libGL.so
Build/bin/MyOwnProject: src/OpenMesh/Apps/demo/imgui/libimguid.a
Build/bin/MyOwnProject: src/OpenMesh/Apps/demo/glad/libgladd.a
Build/bin/MyOwnProject: src/OpenMesh/Apps/demo/glfw/src/libglfw3d.a
Build/bin/MyOwnProject: /usr/lib/x86_64-linux-gnu/librt.so
Build/bin/MyOwnProject: /usr/lib/x86_64-linux-gnu/libm.so
Build/bin/MyOwnProject: /usr/lib/x86_64-linux-gnu/libX11.so
Build/bin/MyOwnProject: Build/lib/libOpenMeshCored.so.8.0
Build/bin/MyOwnProject: src/OpenMesh/Apps/demo/CMakeFiles/MyOwnProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/qiang/Documents/codefiles/geo/OpenMesh-8.0/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../../../../Build/bin/MyOwnProject"
	cd /home/qiang/Documents/codefiles/geo/OpenMesh-8.0/cmake-build-debug/src/OpenMesh/Apps/demo && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MyOwnProject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/OpenMesh/Apps/demo/CMakeFiles/MyOwnProject.dir/build: Build/bin/MyOwnProject

.PHONY : src/OpenMesh/Apps/demo/CMakeFiles/MyOwnProject.dir/build

src/OpenMesh/Apps/demo/CMakeFiles/MyOwnProject.dir/clean:
	cd /home/qiang/Documents/codefiles/geo/OpenMesh-8.0/cmake-build-debug/src/OpenMesh/Apps/demo && $(CMAKE_COMMAND) -P CMakeFiles/MyOwnProject.dir/cmake_clean.cmake
.PHONY : src/OpenMesh/Apps/demo/CMakeFiles/MyOwnProject.dir/clean

src/OpenMesh/Apps/demo/CMakeFiles/MyOwnProject.dir/depend:
	cd /home/qiang/Documents/codefiles/geo/OpenMesh-8.0/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/qiang/Documents/codefiles/geo/OpenMesh-8.0 /home/qiang/Documents/codefiles/geo/OpenMesh-8.0/src/OpenMesh/Apps/demo /home/qiang/Documents/codefiles/geo/OpenMesh-8.0/cmake-build-debug /home/qiang/Documents/codefiles/geo/OpenMesh-8.0/cmake-build-debug/src/OpenMesh/Apps/demo /home/qiang/Documents/codefiles/geo/OpenMesh-8.0/cmake-build-debug/src/OpenMesh/Apps/demo/CMakeFiles/MyOwnProject.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/OpenMesh/Apps/demo/CMakeFiles/MyOwnProject.dir/depend
