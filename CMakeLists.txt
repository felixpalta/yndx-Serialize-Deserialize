cmake_minimum_required(VERSION 2.8)

project(SerDeser)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(./googletest)

add_executable(SerDeserApp "main.cpp")
add_library(SerDeser "SerDeser.cpp")
add_executable(SerDeserTests SerDeserTests.cpp)

target_include_directories(SerDeserApp PRIVATE .)
target_include_directories(SerDeserTests PRIVATE .)

set_target_properties(SerDeserApp SerDeser SerDeserTests PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

target_link_libraries(SerDeserApp PRIVATE
    SerDeser
)
target_link_libraries(SerDeserTests PRIVATE
    gtest_main
    SerDeser
)

enable_testing()

add_test(SerDeserTests SerDeserTests)
