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
include src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/depend.make

# Include the progress variables for this target.
include src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/progress.make

# Include the compile flags for this target's objects.
include src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/flags.make

src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/ProgViewerWidget.cc.o: src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/flags.make
src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/ProgViewerWidget.cc.o: ../src/OpenMesh/Apps/ProgViewer/ProgViewerWidget.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/ProgViewerWidget.cc.o"
	cd /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/src/OpenMesh/Apps/ProgViewer && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ProgViewer.dir/ProgViewerWidget.cc.o -c /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/src/OpenMesh/Apps/ProgViewer/ProgViewerWidget.cc

src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/ProgViewerWidget.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProgViewer.dir/ProgViewerWidget.cc.i"
	cd /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/src/OpenMesh/Apps/ProgViewer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/src/OpenMesh/Apps/ProgViewer/ProgViewerWidget.cc > CMakeFiles/ProgViewer.dir/ProgViewerWidget.cc.i

src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/ProgViewerWidget.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProgViewer.dir/ProgViewerWidget.cc.s"
	cd /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/src/OpenMesh/Apps/ProgViewer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/src/OpenMesh/Apps/ProgViewer/ProgViewerWidget.cc -o CMakeFiles/ProgViewer.dir/ProgViewerWidget.cc.s

src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/ProgViewerWidget.cc.o.requires:

.PHONY : src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/ProgViewerWidget.cc.o.requires

src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/ProgViewerWidget.cc.o.provides: src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/ProgViewerWidget.cc.o.requires
	$(MAKE) -f src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/build.make src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/ProgViewerWidget.cc.o.provides.build
.PHONY : src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/ProgViewerWidget.cc.o.provides

src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/ProgViewerWidget.cc.o.provides.build: src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/ProgViewerWidget.cc.o


src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/progviewer.cc.o: src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/flags.make
src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/progviewer.cc.o: ../src/OpenMesh/Apps/ProgViewer/progviewer.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/progviewer.cc.o"
	cd /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/src/OpenMesh/Apps/ProgViewer && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ProgViewer.dir/progviewer.cc.o -c /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/src/OpenMesh/Apps/ProgViewer/progviewer.cc

src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/progviewer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProgViewer.dir/progviewer.cc.i"
	cd /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/src/OpenMesh/Apps/ProgViewer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/src/OpenMesh/Apps/ProgViewer/progviewer.cc > CMakeFiles/ProgViewer.dir/progviewer.cc.i

src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/progviewer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProgViewer.dir/progviewer.cc.s"
	cd /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/src/OpenMesh/Apps/ProgViewer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/src/OpenMesh/Apps/ProgViewer/progviewer.cc -o CMakeFiles/ProgViewer.dir/progviewer.cc.s

src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/progviewer.cc.o.requires:

.PHONY : src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/progviewer.cc.o.requires

src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/progviewer.cc.o.provides: src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/progviewer.cc.o.requires
	$(MAKE) -f src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/build.make src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/progviewer.cc.o.provides.build
.PHONY : src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/progviewer.cc.o.provides

src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/progviewer.cc.o.provides.build: src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/progviewer.cc.o


src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/__/QtViewer/QGLViewerWidget.cc.o: src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/flags.make
src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/__/QtViewer/QGLViewerWidget.cc.o: ../src/OpenMesh/Apps/QtViewer/QGLViewerWidget.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/__/QtViewer/QGLViewerWidget.cc.o"
	cd /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/src/OpenMesh/Apps/ProgViewer && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ProgViewer.dir/__/QtViewer/QGLViewerWidget.cc.o -c /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/src/OpenMesh/Apps/QtViewer/QGLViewerWidget.cc

src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/__/QtViewer/QGLViewerWidget.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProgViewer.dir/__/QtViewer/QGLViewerWidget.cc.i"
	cd /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/src/OpenMesh/Apps/ProgViewer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/src/OpenMesh/Apps/QtViewer/QGLViewerWidget.cc > CMakeFiles/ProgViewer.dir/__/QtViewer/QGLViewerWidget.cc.i

src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/__/QtViewer/QGLViewerWidget.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProgViewer.dir/__/QtViewer/QGLViewerWidget.cc.s"
	cd /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/src/OpenMesh/Apps/ProgViewer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/src/OpenMesh/Apps/QtViewer/QGLViewerWidget.cc -o CMakeFiles/ProgViewer.dir/__/QtViewer/QGLViewerWidget.cc.s

src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/__/QtViewer/QGLViewerWidget.cc.o.requires:

.PHONY : src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/__/QtViewer/QGLViewerWidget.cc.o.requires

src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/__/QtViewer/QGLViewerWidget.cc.o.provides: src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/__/QtViewer/QGLViewerWidget.cc.o.requires
	$(MAKE) -f src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/build.make src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/__/QtViewer/QGLViewerWidget.cc.o.provides.build
.PHONY : src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/__/QtViewer/QGLViewerWidget.cc.o.provides

src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/__/QtViewer/QGLViewerWidget.cc.o.provides.build: src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/__/QtViewer/QGLViewerWidget.cc.o


src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/ProgViewer_autogen/mocs_compilation.cpp.o: src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/flags.make
src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/ProgViewer_autogen/mocs_compilation.cpp.o: src/OpenMesh/Apps/ProgViewer/ProgViewer_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/ProgViewer_autogen/mocs_compilation.cpp.o"
	cd /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/src/OpenMesh/Apps/ProgViewer && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ProgViewer.dir/ProgViewer_autogen/mocs_compilation.cpp.o -c /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/src/OpenMesh/Apps/ProgViewer/ProgViewer_autogen/mocs_compilation.cpp

src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/ProgViewer_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProgViewer.dir/ProgViewer_autogen/mocs_compilation.cpp.i"
	cd /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/src/OpenMesh/Apps/ProgViewer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/src/OpenMesh/Apps/ProgViewer/ProgViewer_autogen/mocs_compilation.cpp > CMakeFiles/ProgViewer.dir/ProgViewer_autogen/mocs_compilation.cpp.i

src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/ProgViewer_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProgViewer.dir/ProgViewer_autogen/mocs_compilation.cpp.s"
	cd /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/src/OpenMesh/Apps/ProgViewer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/src/OpenMesh/Apps/ProgViewer/ProgViewer_autogen/mocs_compilation.cpp -o CMakeFiles/ProgViewer.dir/ProgViewer_autogen/mocs_compilation.cpp.s

src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/ProgViewer_autogen/mocs_compilation.cpp.o.requires:

.PHONY : src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/ProgViewer_autogen/mocs_compilation.cpp.o.requires

src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/ProgViewer_autogen/mocs_compilation.cpp.o.provides: src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/ProgViewer_autogen/mocs_compilation.cpp.o.requires
	$(MAKE) -f src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/build.make src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/ProgViewer_autogen/mocs_compilation.cpp.o.provides.build
.PHONY : src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/ProgViewer_autogen/mocs_compilation.cpp.o.provides

src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/ProgViewer_autogen/mocs_compilation.cpp.o.provides.build: src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/ProgViewer_autogen/mocs_compilation.cpp.o


# Object files for target ProgViewer
ProgViewer_OBJECTS = \
"CMakeFiles/ProgViewer.dir/ProgViewerWidget.cc.o" \
"CMakeFiles/ProgViewer.dir/progviewer.cc.o" \
"CMakeFiles/ProgViewer.dir/__/QtViewer/QGLViewerWidget.cc.o" \
"CMakeFiles/ProgViewer.dir/ProgViewer_autogen/mocs_compilation.cpp.o"

# External object files for target ProgViewer
ProgViewer_EXTERNAL_OBJECTS =

Build/bin/ProgViewer: src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/ProgViewerWidget.cc.o
Build/bin/ProgViewer: src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/progviewer.cc.o
Build/bin/ProgViewer: src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/__/QtViewer/QGLViewerWidget.cc.o
Build/bin/ProgViewer: src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/ProgViewer_autogen/mocs_compilation.cpp.o
Build/bin/ProgViewer: src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/build.make
Build/bin/ProgViewer: Build/lib/libOpenMeshTools.so.8.0
Build/bin/ProgViewer: /home/zhangj0o/anaconda3/lib/libQt5OpenGL.so.5.12.9
Build/bin/ProgViewer: /usr/lib/x86_64-linux-gnu/libGL.so
Build/bin/ProgViewer: /usr/lib/x86_64-linux-gnu/libGLU.so
Build/bin/ProgViewer: Build/lib/libOpenMeshCore.so.8.0
Build/bin/ProgViewer: /home/zhangj0o/anaconda3/lib/libQt5Widgets.so.5.12.9
Build/bin/ProgViewer: /home/zhangj0o/anaconda3/lib/libQt5Gui.so.5.12.9
Build/bin/ProgViewer: /home/zhangj0o/anaconda3/lib/libQt5Core.so.5.12.9
Build/bin/ProgViewer: src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable ../../../../Build/bin/ProgViewer"
	cd /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/src/OpenMesh/Apps/ProgViewer && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ProgViewer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/build: Build/bin/ProgViewer

.PHONY : src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/build

src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/requires: src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/ProgViewerWidget.cc.o.requires
src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/requires: src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/progviewer.cc.o.requires
src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/requires: src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/__/QtViewer/QGLViewerWidget.cc.o.requires
src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/requires: src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/ProgViewer_autogen/mocs_compilation.cpp.o.requires

.PHONY : src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/requires

src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/clean:
	cd /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/src/OpenMesh/Apps/ProgViewer && $(CMAKE_COMMAND) -P CMakeFiles/ProgViewer.dir/cmake_clean.cmake
.PHONY : src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/clean

src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/depend:
	cd /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/src/OpenMesh/Apps/ProgViewer /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/src/OpenMesh/Apps/ProgViewer /home/zhangj0o/Documents/codefiles/CS272-Geometrci-Processing-Curvature-Estimation/build/src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/OpenMesh/Apps/ProgViewer/CMakeFiles/ProgViewer.dir/depend

