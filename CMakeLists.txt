cmake_minimum_required(VERSION 3.16)

project(
	ADVENT_OF_CODE_2024
	LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(WARNINGS_AS_ERRORS ON)
include_directories("cmake")

if (CMAKE_BUILD_TYPE MATCHES "Release")
	set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
endif()

if (CMAKE_BUILD_TYPE MATCHES "RelWithDebInfo")
	set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
endif()

add_subdirectory("lib/Catch2")
add_subdirectory("resources")
add_subdirectory("src")
add_subdirectory("test")
