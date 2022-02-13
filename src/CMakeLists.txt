cmake_minimum_required(VERSION 3.14)

project(ale)
include(FetchContent)
include(ExternalProject)

set(LIBRARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/library/)

SET(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "${LIBRARY_DIR}/lib")
SET(COMMON_CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${LIBRARY_DIR} -DCMAKE_PREFIX_PATH=${CMAKE_PREFIX_PATH})

ExternalProject_Add(zlib
    GIT_REPOSITORY https://github.com/madler/zlib.git
    GIT_TAG v1.2.11
    PREFIX "${CMAKE_CURRENT_BINARY_DIR}/zlib"
    CMAKE_ARGS ${COMMON_CMAKE_ARGS} -DHAVE_UNISTD_H=off
)
ExternalProject_Add(SDL
  GIT_REPOSITORY https://github.com/libsdl-org/SDL
  GIT_TAG release-2.0.18
  PREFIX "${CMAKE_CURRENT_BINARY_DIR}/sdl"
  CMAKE_ARGS ${COMMON_CMAKE_ARGS}
)

ExternalProject_Add(ALE
  GIT_REPOSITORY "https://github.com/mgbellemare/Arcade-Learning-Environment"
  GIT_TAG "v0.7.3"
  PREFIX "${CMAKE_CURRENT_BINARY_DIR}/ALE"
  CMAKE_ARGS ${COMMON_CMAKE_ARGS} -DSDL_SUPPORT=ON -DBUILD_PYTHON_LIB=OFF -DCMAKE_CXX_FLAGS="-D__USE_SDL"
)

add_dependencies(ALE zlib SDL)


#set(SDL_SUPPORT ON)
#set(SDL_DYNLOAD ON)
#set(BUILD_PYTHON_LIB OFF)
#FetchContent_Declare(
#  ALE
#  GIT_REPOSITORY "https://github.com/mgbellemare/Arcade-Learning-Environment"
#  GIT_TAG "v0.7.3"
#)
#FetchContent_MakeAvailable(ALE)

add_library(libzlib SHARED IMPORTED)
add_library(libzlib::library ALIAS libzlib)
set_target_properties(libzlib PROPERTIES IMPORTED_LOCATION ${LIBRARY_DIR}/lib/libz.dylib)

add_library(libale SHARED IMPORTED)
add_library(libale::library ALIAS libale)
set_target_properties(libale PROPERTIES IMPORTED_LOCATION ${LIBRARY_DIR}/lib/libale.a)

add_library(libsdl SHARED IMPORTED)
add_library(libsdl::library ALIAS libsdl)
set_target_properties(libsdl PROPERTIES IMPORTED_LOCATION ${LIBRARY_DIR}/lib/libSDL2.dylib)

execute_process (
    COMMAND Rscript -e "cat(R.home())"
    OUTPUT_VARIABLE R_HOME_DIR
)

execute_process (
    COMMAND Rscript -e "cat(system.file(package = 'Rcpp'))"
    OUTPUT_VARIABLE RCPP_HOME_DIR
)

add_library(Rcpp SHARED IMPORTED)
add_library(Rcpp::library ALIAS Rcpp)
set_target_properties(Rcpp PROPERTIES IMPORTED_LOCATION ${RCPP_HOME_DIR}/libs/Rcpp.so)

add_library(RLib SHARED IMPORTED)
add_library(RLib::library ALIAS RLib)
set_target_properties(RLib PROPERTIES IMPORTED_LOCATION ${R_HOME_DIR}/lib/libR.dylib)

include_directories(${R_HOME_DIR}/include)
include_directories(${RCPP_HOME_DIR}/include)
include_directories(${LIBRARY_DIR}/include/ale)
include_directories(${LIBRARY_DIR}/include/SDL2)

add_library(aler SHARED code.cpp RcppExports.cpp)
target_link_libraries(aler libale Rcpp RLib libzlib libsdl)
ADD_DEFINITIONS(-D__USE_SDL)
set_property(TARGET aler PROPERTY CXX_STANDARD 17)
add_dependencies(aler ALE)
