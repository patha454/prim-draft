# Author: H Paterson.
# Copyright: Boost Software License 1.0.
# Date: 19/10/2019.

# Set required Cmake version.
cmake_minimum_required(VERSION 2.8.1)

# Select sources for compilation.
add_library(characteristics
            characteristics.c
            ${PROJECT_SOURCE_DIR}/include/format/pecoff/characteristics.h
            ${PROJECT_SOURCE_DIR}/include/platform/types.h)

add_library(machines
            machines.c
            ${PROJECT_SOURCE_DIR}/include/format/pecoff/machines.h
            ${PROJECT_SOURCE_DIR}/include/platform/types.h)

add_library(magic
            magic.c
            ${PROJECT_SOURCE_DIR}/include/format/pecoff/magic.h
            ${PROJECT_SOURCE_DIR}/include/platform/types.h)

# Set includes

target_include_directories(characteristics PRIVATE ${PROJECT_SOURCE_DIR}/include/)

target_include_directories(machines PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_include_directories(magic PRIVATE ${PROJECT_SOURCE_DIR}/include)

# Use ISO C90.
set_property(TARGET characteristics PROPERTY C_STANDARD 90)
set_property(TARGET machines PROPERTY C_STANDARD 90)
set_property(TARGET magic PROPERTY C_STANDARD 90)

