cmake_minimum_required(VERSION 3.22)

add_executable(sg90_invKin)

target_sources(sg90_invKin PRIVATE sg90_invKin.c)

target_link_libraries(sg90_invKin PRIVATE libsg90 pico_stdlib)

pico_add_extra_outputs(sg90_invKin)