cmake_minimum_required(VERSION 3.20)

project(cpp_playground LANGUAGES CXX)

# Add include directory for project headers
include_directories(${CMAKE_SOURCE_DIR}/include)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(app src/main.cpp)
target_compile_options(app PRIVATE -Wall -Wextra -Wpedantic)
