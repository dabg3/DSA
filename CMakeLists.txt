cmake_minimum_required(VERSION 3.20)
project(DSA)

add_library(dsa SHARED "")
target_include_directories(dsa PUBLIC include)
target_sources(dsa PRIVATE
	src/dsa.c
)

add_subdirectory(unity)
add_executable(test_runner tests/test_dsa.c)
target_link_libraries(test_runner PRIVATE dsa unity)
include(CTest)
add_test(NAME example COMMAND test_runner)
