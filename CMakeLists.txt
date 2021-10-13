cmake_minimum_required(VERSION 3.16)
project(cqueue_embed C)

set(CMAKE_C_STANDARD 99)

include_directories(cqueue)

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

add_library(cqueue_embed cqueue/cqueue-embed.c)
add_executable(cqueue_embed_test examples/main.c)
target_link_libraries(cqueue_embed_test cqueue_embed)