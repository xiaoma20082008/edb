cmake_minimum_required(VERSION 3.16)

foreach(policy
        CMP0023
        CMP0048 # CMake 3.0
        CMP0074 # CMake 3.12
        CMP0077
        CMP0079
        )
    if(POLICY ${policy})
        cmake_policy(SET ${policy} NEW)
    endif()
endforeach()

project(edb LANGUAGES C CXX ASM VERSION 1.0.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CXX_COMMON_FLAGS "-std=c++17 -Wall -Werror -fno-rtti -fPIC -fPIE")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 ${CXX_COMMON_FLAGS} -fno-inline")
set(CMAKE_CXX_FLAGS_RELEASE " -O1 ${CXX_COMMON_FLAGS}")


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)

set(CMAKE_MODULE_PATH "${CMAKE_HOME_DIRECTORY}/cmake")


# external dependencies
include(ExternalProject)
include(FetchContent)

# sources
add_subdirectory(src)