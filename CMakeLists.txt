################################################################################
#         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
#         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
#
#          Distributed under the Boost Software License, Version 1.0.
#                 See accompanying file LICENSE.txt or copy at
#                     http://www.boost.org/LICENSE_1_0.txt
################################################################################
cmake_minimum_required(VERSION 2.8)

################################################################################
# Project nt2 - See toolbox/CMakeLists.txt for toolbox CMake scripts
################################################################################
project(nt2)

################################################################################
# Global Options
################################################################################
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set(INCLUDE_INSTALL_DIR
    "${CMAKE_INSTALL_PREFIX}/include/nt2"
    CACHE PATH
    "The directory where we install the header files"
    FORCE)

set(NT2_VERSION_NUMBER "3.0.0")
set(NT2_VERSION "${NT2_VERSION_NUMBER}")

################################################################################
# Build up NT2 related settings
################################################################################
include(nt2.boost)
include(nt2.sphinx)
include(nt2.python)

################################################################################
# Find number CPU coutn and cache infos
################################################################################
include(nt2.cpucount)
include(nt2.cpucache)

################################################################################
# Find parallelism sources
################################################################################
include(nt2.mpi)
include(nt2.simd)
include(nt2.threading)

################################################################################
# Generate bootstrap.hpp
################################################################################
CONFIGURE_FILE( ${PROJECT_SOURCE_DIR}/cmake/bootstrap.hpp.cmake 
                ${PROJECT_SOURCE_DIR}/include/nt2/sdk/config/bootstrap.hpp 
              )

################################################################################
# Install headers
################################################################################

################################################################################
# Gather CXX flags from user options and configuration
################################################################################
include(nt2.compiler.options)

################################################################################
# Build libnt2
################################################################################
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib/${CMAKE_BUILD_TYPE})
include_directories( ${PROJECT_SOURCE_DIR}/include)
file( GLOB_RECURSE source_files  
      ${PROJECT_SOURCE_DIR}/src/*  
      ${PROJECT_SOURCE_DIR}/include/* 
    )

#add_library(nt2 SHARED ${source_files} )

################################################################################
# Install libnt2
################################################################################

################################################################################
# Add Examples
################################################################################
ADD_SUBDIRECTORY(examples)
