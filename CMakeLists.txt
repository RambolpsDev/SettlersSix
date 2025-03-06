cmake_minimum_required(VERSION 3.20)

project(SettlersSix LANGUAGES CXX)

# Use C++20
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(${PROJECT_SOURCE_DIR}/vendored/SDL3 EXCLUDE_FROM_ALL)

# Gather all .cpp files in the 'src' folder recursively
file(GLOB_RECURSE SRC_SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

# Add include directory
include_directories("${PROJECT_SOURCE_DIR}/include")

# Create the executable from main.cpp and all .cpp files in 'src'
add_executable(SettlersSix ${SRC_SOURCES})

# Link the executable with SDL3
target_link_libraries(SettlersSix PRIVATE SDL3::SDL3)