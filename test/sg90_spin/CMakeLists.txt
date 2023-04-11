cmake_minimum_required(VERSION 3.22)

add_executable(sg90_spin)

target_sources(sg90_spin PRIVATE sg90_spin.c)

target_link_libraries(sg90_spin PRIVATE libsg90 pico_stdlib)

pico_add_extra_outputs(sg90_spin)