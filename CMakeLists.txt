cmake_minimum_required(VERSION 3.28)

# set topdir and append cmake dir to module path
set(crate_TOPDIR "${CMAKE_CURRENT_SOURCE_DIR}")
list(APPEND CMAKE_MODULE_PATH "${crate_TOPDIR}/cmake")

include(CrateReusables)

# create atom and init project
crate_atom(crate)
project(${crate}
  VERSION 0.1.0
  LANGUAGES CXX  
)

set(crate_DIR "${crate_TOPDIR}/crate")

# configure crate library
add_library(${crate})

target_include_directories(${crate} PRIVATE ${crate_TOPDIR})
target_sources(${crate} PUBLIC
  FILE_SET CXX_MODULES
  FILES
    "${crate_DIR}/crate.ccm"
)

target_compile_features(${crate} PUBLIC cxx_std_20)
target_compile_options(${crate}
  PRIVATE
    -Wall -Werror
  PUBLIC
    -fno-rtti
)

