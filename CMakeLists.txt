cmake_minimum_required(VERSION 3.10)

project(AnalyticsBackend LANGUAGES CXX CUDA)

set(CMAKE_CUDA_ARCHITECTURES 80)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(CUDA REQUIRED)


set(SOURCE_FILES
   src/BackendMain.cpp
)

set(HEADERS
   include/BackendMain.hpp
   include/BackendTypes.hpp
   tmp/input/system.cuh
)
set(OUTPUT_TEMP_PATH "${CMAKE_CURRENT_SOURCE_DIR}/tmp/output/")

include_directories(
   include
   tmp/input
)

add_library(AnalyticsBackend SHARED ${SOURCE_FILES} ${HEADERS})



target_include_directories(AnalyticsBackend
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
    PUBLIC ${CUDA_INCLUDE_DIRS}
    PUBLIC ${CMAKE_BINARY_DIR}
)

target_link_libraries(AnalyticsBackend PUBLIC ${CUDA_LIBRARIES})


target_compile_definitions(AnalyticsBackend PRIVATE
   OUTPUT_PATH="${OUTPUT_TEMP_PATH}")

set(SOURCE_DIR "${CMAKE_SOURCE_DIR}" CACHE STRING "Path to the source directory")
set(BUILD_PROG_DIR "${CMAKE_BINARY_DIR}" CACHE STRING "Path to the build directory")

target_compile_definitions(AnalyticsBackend PUBLIC
    SOURCE_DIR="${CMAKE_SOURCE_DIR}"
    BUILD_PROG_DIR="${CMAKE_BINARY_DIR}"
)


install(TARGETS AnalyticsBackend DESTINATION lib)
install(DIRECTORY include/ DESTINATION include)
