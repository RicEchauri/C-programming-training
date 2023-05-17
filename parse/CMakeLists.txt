cmake_minimum_required(VERSION 3.0)
project(parse) 
#incluir los headers 
include_directories(include)
add_executable(
    parse #binario
    src/main.c
    src/parse.c
    src/tools.c
)
