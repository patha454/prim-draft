# Author: H Paterson.
# Copyright: Boost Software License 1.0.
# Date: 19/10/2019.

# Set required Cmake version.
cmake_minimum_required(VERSION 2.8.1)

# Enable strict warnings
if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

# Build Binary Format Libraries
add_subdirectory(format)
