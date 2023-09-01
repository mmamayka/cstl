cmake_minimum_required(VERSION 3.22.1)

project(cstl LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(cstl-static STATIC)
add_library(cstl::cstl-static ALIAS cstl-static)

file(GLOB CSTL_SRC "src/*.c")
target_sources(cstl-static PRIVATE ${CSTL_SRC})
target_include_directories(cstl-static 
    PUBLIC include
    PRIVATE src/include
)

enable_testing()
add_subdirectory(t)
