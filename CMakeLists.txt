cmake_minimum_required(VERSION 3.22)

include(pico_sdk_import.cmake)

project(lib_sg90 C CXX ASM)
set(CMAKE_C_STANDARD 11)

set(TEST "false")

if(CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
    
    set(TEST "true")

    pico_sdk_init()

endif()

add_subdirectory(test)

add_library(libsg90 src/sg90.c)

target_include_directories(libsg90 PUBLIC include)

target_link_libraries(libsg90 PUBLIC pico_stdlib hardware_pwm)
