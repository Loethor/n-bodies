cmake_minimum_required(VERSION 3.20)

project(cpp_playground LANGUAGES CXX)

# Add include directory for project headers
include_directories(${CMAKE_SOURCE_DIR}/include)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Main executable
add_executable(app 
    src/main.cpp
    src/body/body.cpp
    src/simulation/simulation.cpp
    src/integrator/euler_integrator.cpp
    src/config/config_loader.cpp
)
target_compile_options(app PRIVATE -Wall -Wextra -Wpedantic)

# Google Test setup
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.14.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Enable testing
enable_testing()

# Test executable
add_executable(tests
    tests/body_test.cpp
    tests/math_test.cpp
    tests/config_loader_test.cpp
    src/body/body.cpp
    src/simulation/simulation.cpp
    src/integrator/euler_integrator.cpp
    src/config/config_loader.cpp
)
target_link_libraries(tests gtest_main)
target_compile_options(tests PRIVATE -Wall -Wextra -Wpedantic)

include(GoogleTest)
gtest_discover_tests(tests)
