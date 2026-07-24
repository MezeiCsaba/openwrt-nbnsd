cmake_minimum_required(VERSION 3.16)

project(openwrt-nbnsd C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_compile_options(
    -Wall
    -Wextra
    -Wpedantic
)

add_executable(

    nbnsd

    src/main.c
    src/log.c
    src/nbns.c
    src/netbios.c

)