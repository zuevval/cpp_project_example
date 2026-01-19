cmake_minimum_required(VERSION 3.10)
project(GraphConverter)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra)

add_executable(graphConverter
    main.cpp
    graph/Graph.cpp
    io/Reader.cpp
    io/Writer.cpp
)
