cmake_minimum_required(VERSION 3.16.3 FATAL_ERROR)

project(LeetCodeTask2_AddTwoNumbers)

set(SOURCES main.cpp)
# set(HEADERS )

add_executable(Task ${SOURCES})
#add_executable(Task ${SOURCES} ${HEADERS})

set(CXX_COVERAGE_COMPILE_FLAGS "-std=c++17 -Wall -Werror -g")
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${CXX_COVERAGE_COMPILE_FLAGS}")

set_target_properties(
    Task PROPERTIES
    CXX_STANDART 17
    CXX_STANDART_REQUIRED ON
)
