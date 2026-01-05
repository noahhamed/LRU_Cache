cmake_minimum_required(VERSION 3.20)
project(lru_cache)

set(CMAKE_CXX_STANDARD 17)

add_executable(lru_cache
        main.cpp
        LRUCache.cpp
        LRUCache.h
)

add_executable(lru_cache_tests
        tests.cpp
        LRUCache.cpp
        LRUCache.h
)
