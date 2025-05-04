cmake_minimum_required(VERSION 3.10.1)

include_directories(${CMAKE_SOURCE_DIR}/src)

project(main)

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

aux_source_directory(src SRC_LIST)

include_directories(inc)

add_executable(main ${SRC_LIST})

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)