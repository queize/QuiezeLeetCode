cmake_minimum_required(VERSION 3.0)

project(main)

include_directories(
    D:/ProgrammTrash/HeaderCode)

set(SOURCES 
    main.cpp 
    solution.cpp)

set(HEADERS 
    headers.hpp 
    primary_header.hpp 
    solution.hpp 
    tests.hpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
    ${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS})