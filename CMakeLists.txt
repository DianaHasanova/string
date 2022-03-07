cmake_minimum_required(VERSION 3.20)
project(libsString C)

set(CMAKE_C_STANDARD 11)

add_executable(libsString main.c string/tasks/string_.c string/tasks/string_.h)

add_subdirectory(string)


