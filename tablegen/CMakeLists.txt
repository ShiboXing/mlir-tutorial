cmake_minimum_required(VERSION 4.1)

project(tablegen VERSION 0.0.1)

find_package(MLIR REQUIRED CONFIG)
list(APPEND CMAKE_MODULE_PATH "${MLIR_CMAKE_DIR}")
list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")

include(TableGen)
include(AddLLVM)
include(AddMLIR)
include(HandleLLVMOptions)

message(STATUS "CMAKE_INSTALL_PREFIX: ${CMAKE_INSTALL_PREFIX}")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/include)
include_directories(${CMAKE_INSTALL_PREFIX}/include)

add_subdirectory(include/toy)
add_subdirectory(lib)
add_subdirectory(tools/toy-opt)
add_custom_target(header DEPENDS MLIRToyIncGen)
