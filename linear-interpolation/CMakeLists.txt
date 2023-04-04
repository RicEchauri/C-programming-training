cmake_minimum_required(VERSION 3.0)
project(linear-interpolation) 
#incluir los headers 
include_directories(include)
add_executable(
    interpolation #binario
    src/main.c
    src/interpolation.c
)
