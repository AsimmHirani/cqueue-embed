cmake_minimum_required(VERSION 3.16)
project(cqueue_embed C)

set(CMAKE_C_STANDARD 11)

add_library(cqueue_embed cqueue/cqueue-embed.c)
