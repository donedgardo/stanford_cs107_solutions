cmake_minimum_required(VERSION 3.14)
project(concat_all)

# Ensure MSVC uses the DLL runtime (/MD, /MDd) to match GoogleTest
cmake_policy(SET CMP0091 NEW)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL" CACHE STRING "" FORCE)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)

add_executable(concat_all
        concat_all_tests.cc
        concat_all.h)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
enable_testing()

target_link_libraries(
        concat_all
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(concat_all)
