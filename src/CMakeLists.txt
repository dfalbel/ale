cmake_minimum_required(VERSION 3.14)

project(ale)
include(FetchContent)
FetchContent_Declare(
  ALE
  GIT_REPOSITORY "https://github.com/mgbellemare/Arcade-Learning-Environment"
  GIT_TAG "v0.7.3"
  CMAKE_ARGS -DSDL_SUPPORT=ON
)

FetchContent_Declare(
  ZLib
  GIT_REPOSITORY "https://github.com/madler/zlib"
  GIT_TAG "v1.2.11"
)

FetchContent_Declare(
  SDL
  GIT_REPOSITORY https://github.com/libsdl-org/SDL
  GIT_TAG release-2.0.20
)

set(BUILD_PYTHON_LIB OFF)
set(SDL_SUPPORT OFF)

FetchContent_MakeAvailable(ZLib SDL)
FetchContent_MakeAvailable(ALE)

find_package(ale REQUIRED)

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

add_library(aler SHARED code.cpp RcppExports.cpp)
target_link_libraries(aler ale::ale-lib Rcpp RLib SDL2::SDL2)
set_property(TARGET aler PROPERTY CXX_STANDARD 17)

