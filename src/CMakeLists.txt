cmake_minimum_required(VERSION 3.10)
project(GraphConverter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra)

include(FetchContent)
FetchContent_Declare(
        nlohmann
        GIT_REPOSITORY  "https://github.com/nlohmann/json"
        GIT_TAG         "develop"
)
FetchContent_MakeAvailable(nlohmann)

add_executable(graphConverter
    main.cpp
    graph/Graph.cpp
    io/Reader.cpp
    io/Writer.cpp
)
target_link_libraries(graphConverter PRIVATE nlohmann_json::nlohmann_json)
