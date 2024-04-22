cmake_minimum_required(VERSION 3.27)
project(relisStructure C)

set(CMAKE_C_STANDARD 11)

add_executable(relisStructure testHashTable.c
        libs/dataStructure/Hash/HashTable.h
        libs/dataStructure/Hash/HashTable.c)

add_subdirectory(libs)

target_link_libraries(dataStructure)