# cqueue-embed
 Static Queue implemented in C with no dependencies

## What does this project do?

This project aims to implement a standalone queue for use in embedded applications without dynamic memory allocation.

## Why is this project useful?

In my personal experience with embedded systems, knowing how much memory a data structure will take up at run-time is important. Many queue implementations rely on dynamic memory allocation which is difficult to analyze at compile-time, therefore I have written this project.

## How do I get started?

The easiest way by far is to include this project as a subdirectory in your CMake target and add ``` cmake-embed ``` as a target-link-library. Follow how I implemented ``` cmake-embed-test ``` in my ```CMakeList.txt``` file.

You can also include ``` cqueue-embed.h ``` in your project and link the associated ``` cqueue-enbed.c ``` file.

You will see references to ``` mssert.h ``` which I have used for unit testing on embedded target hardware. If you don't define ``` MSSERT ``` in the compile-flags you don't need to have ``` mssert.h ``` visible in your system's make file. 

## Where can I get more help, if I need it?

This project is still very green. I welcome issues and feedback to make it more usable. If you make a pull request or an issue I will do my damndest to address it.