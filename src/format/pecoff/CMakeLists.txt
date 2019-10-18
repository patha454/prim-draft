# Author: H Paterson.
# Copyright: Boost Software License 1.0.
# Date: 19/10/2019.

# Set required Cmake version.
cmake_minimum_required(VERSION 2.8.1)

# Generate PE/COFF libraries.
add_library(pecoff 
            characteristics.c
            machines.c)

# Use ISO C90
set_property(TARGET pecoff PROPERTY C_STANDARD 90)
