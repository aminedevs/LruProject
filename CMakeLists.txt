cmake_minimum_required(VERSION 3.10)
project(LruProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_library(LruLib src/LruCache.cpp)
target_include_directories(LruLib PUBLIC include)

# Add sources
add_executable(LruApp
    src/main.cpp)
target_link_libraries(LruApp PRIVATE LruLib)

enable_testing()

add_executable(runTests tests/main.cpp tests/LruCache.test.cpp)
target_link_libraries(runTests PRIVATE LruLib)

target_include_directories(runTests PRIVATE tests)

add_test(NAME LruTests COMMAND runTests)
