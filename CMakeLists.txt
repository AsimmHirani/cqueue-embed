cmake_minimum_required(VERSION 3.16)
project(cqueue_embed C)

set(CMAKE_C_STANDARD 11)

include_directories(cqueue)

add_library(cqueue_embed cqueue/cqueue-embed.c)
add_executable(cqueue_embed_test examples/main.c)
target_link_libraries(cqueue_embed_test cqueue_embed)