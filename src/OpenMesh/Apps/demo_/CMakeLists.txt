include (ACGCommon)
include_directories (
  ../../..
  ${CMAKE_CURRENT_SOURCE_DIR}
)
set (targetName MyOwnProject)


set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# libigl
option(LIBIGL_WITH_OPENGL            "Use OpenGL"         ON)
option(LIBIGL_WITH_OPENGL_GLFW       "Use GLFW"           ON)
option(LIBIGL_WITH_OPENGL_GLFW_IMGUI "Use imgui"           ON)


find_package(LIBIGL REQUIRED QUIET)

acg_append_files (headers "*.hh" .)
acg_append_files (sources "*.cc" .)

acg_add_executable (${targetName} ${headers} ${sources})
set_property(TARGET ${targetName} PROPERTY CXX_STANDARD 17)

target_link_libraries (${targetName}
        igl::core
        igl::opengl
        igl::opengl_glfw
        igl::opengl_glfw_imgui
        OpenMeshCore
        OpenMeshTools
)
