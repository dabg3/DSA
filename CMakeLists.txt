cmake_minimum_required(VERSION 3.20)
project(DSA)

add_library(dsa SHARED "")
target_include_directories(dsa PUBLIC include)
target_sources(dsa PRIVATE
	src/dsa.c
)

add_subdirectory(unity)
add_executable(sorting_suite tests/test_sorting.c)
target_link_libraries(sorting_suite PRIVATE dsa unity)
add_executable(linalg_suite tests/test_linalg.c)
target_link_libraries(linalg_suite PRIVATE dsa unity)
include(CTest)
add_test(NAME sorting COMMAND sorting_suite)
add_test(NAME linalg COMMAND linalg_suite)
