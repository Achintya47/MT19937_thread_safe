cmake_minimum_required(VERSION 3.20)
project(mt19937_thread_safe LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---- Library ----
add_library(mt19937
    src/mt19937.cpp
    src/mt19937_twist.cpp
    src/thread_rng_manager.cpp
)

target_include_directories(mt19937 PUBLIC include)

# ---- Main demo (optional) ----
add_executable(mt_test
    main.cpp
)

target_link_libraries(mt_test PRIVATE mt19937)

# ---- Tests ----
add_executable(test_thread_rng
    tests/test_reference.cpp
)

target_link_libraries(test_thread_rng PRIVATE mt19937)
