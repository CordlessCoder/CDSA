cmake_minimum_required(VERSION 4.1)
project(DSA C)

set(CMAKE_C_STANDARD 11)

include_directories(src)
include_directories(src/memory)

add_executable(DSA
        src/memory/alloc_arena.c
        src/memory/alloc_malloc.c
        src/memory/allocator.c
        src/memory/allocator.h
        src/memory/buffer.c
        src/memory/buffer.h
        src/list.h
        src/main.c)
