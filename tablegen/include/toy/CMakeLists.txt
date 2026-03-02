cmake_minimum_required(VERSION 4.1)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/include)

add_mlir_dialect(Toy toy)
