cmake_minimum_required(VERSION 3.10)
project(LruProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include headers
include_directories(include)

# Add sources
add_executable(LruProject
    src/main.cpp
    src/LruCache.cpp
)