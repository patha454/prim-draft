# Author: H Paterson.
# Copyright: Boost Software License 1.0.
# Date: 19/10/2019.

# Set required Cmake version.
cmake_minimum_required(VERSION 2.8.1)

# Define the Prim project.
project(Prim)

# Include all headers.
include_directories(include)

# Build all Prim sources.
add_subdirectory(src)
