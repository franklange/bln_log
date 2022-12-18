cmake_minimum_required(VERSION 3.10)
project(bln_log)

option(BLN_LOG_EXAMPLES "Enable Examples" OFF)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Build Type" FORCE)
endif()

add_library(${PROJECT_NAME} INTERFACE)

set_target_properties(${PROJECT_NAME} PROPERTIES
    LINKER_LANGUAGE          CXX
)

target_sources(${PROJECT_NAME} PRIVATE
    include/bln_log/log.hpp
)

target_include_directories(${PROJECT_NAME} INTERFACE include)
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_20)

if (BLN_LOG_EXAMPLES)
    add_subdirectory(example)
endif()
