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

# Utility rule file for QtViewer_autogen.

# Include the progress variables for this target.
include src/OpenMesh/Apps/QtViewer/CMakeFiles/QtViewer_autogen.dir/progress.make

src/OpenMesh/Apps/QtViewer/CMakeFiles/QtViewer_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC for target QtViewer"
	cd /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/src/OpenMesh/Apps/QtViewer && /usr/bin/cmake -E cmake_autogen /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/src/OpenMesh/Apps/QtViewer/CMakeFiles/QtViewer_autogen.dir Release

QtViewer_autogen: src/OpenMesh/Apps/QtViewer/CMakeFiles/QtViewer_autogen
QtViewer_autogen: src/OpenMesh/Apps/QtViewer/CMakeFiles/QtViewer_autogen.dir/build.make

.PHONY : QtViewer_autogen

# Rule to build all files generated by this target.
src/OpenMesh/Apps/QtViewer/CMakeFiles/QtViewer_autogen.dir/build: QtViewer_autogen

.PHONY : src/OpenMesh/Apps/QtViewer/CMakeFiles/QtViewer_autogen.dir/build

src/OpenMesh/Apps/QtViewer/CMakeFiles/QtViewer_autogen.dir/clean:
	cd /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/src/OpenMesh/Apps/QtViewer && $(CMAKE_COMMAND) -P CMakeFiles/QtViewer_autogen.dir/cmake_clean.cmake
.PHONY : src/OpenMesh/Apps/QtViewer/CMakeFiles/QtViewer_autogen.dir/clean

src/OpenMesh/Apps/QtViewer/CMakeFiles/QtViewer_autogen.dir/depend:
	cd /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/src/OpenMesh/Apps/QtViewer /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/src/OpenMesh/Apps/QtViewer /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/src/OpenMesh/Apps/QtViewer/CMakeFiles/QtViewer_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/OpenMesh/Apps/QtViewer/CMakeFiles/QtViewer_autogen.dir/depend

