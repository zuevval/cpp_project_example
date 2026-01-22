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

FetchContent_Declare(
        googletest
        GIT_REPOSITORY  "https://github.com/google/googletest"
        GIT_TAG "main"
)
FetchContent_MakeAvailable(googletest)

set(SOURCE_DIR src)
add_executable(graphConverter
    ${SOURCE_DIR}/main.cpp
    ${SOURCE_DIR}/graph/Graph.cpp
    ${SOURCE_DIR}/io/Reader.cpp
    ${SOURCE_DIR}/io/Writer.cpp
)
target_link_libraries(graphConverter PRIVATE nlohmann_json::nlohmann_json)


enable_testing()

set(TEST_DIRECTORY test)
add_executable(
  graphTest
  ${TEST_DIRECTORY}/testGraph.cpp
  ${SOURCE_DIR}/graph/Graph.cpp
  ${TEST_DIRECTORY}/testReadWrite.cpp
  ${SOURCE_DIR}/io/Reader.cpp
  ${SOURCE_DIR}/io/Writer.cpp
)
target_link_libraries(graphTest GTest::gtest_main)
target_link_libraries(graphTest nlohmann_json::nlohmann_json)

include(GoogleTest)
gtest_discover_tests(graphTest)
