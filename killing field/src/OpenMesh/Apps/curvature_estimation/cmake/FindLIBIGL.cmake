# - Try to find the LIBIGL library
# Once done this will define
#
#  LIBIGL_FOUND - system has LIBIGL
#  LIBIGL_INCLUDE_DIR - **the** LIBIGL include directory

set ( LIBIGL_INCLUDE_DIR /home/zhangj0o/Documents/codefiles/libigl/include)
list(APPEND CMAKE_MODULE_PATH "${LIBIGL_INCLUDE_DIR}/../cmake")
#message( ${LIBIGL_INCLUDE_DIR} )

include(libigl)
