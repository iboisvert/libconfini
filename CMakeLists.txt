cmake_minimum_required(VERSION 3.10)
project(libconfini 
    VERSION 0.1 
    LANGUAGES C
)

set(CMAKE_C_STANDARD 17)

add_library(confini STATIC src/confini.c)
target_include_directories(confini INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src)