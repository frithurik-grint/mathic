cmake_minimum_required(VERSION 3.20.0)
project("mathic" VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_C_STANDARD            90)
set(CMAKE_C_STANDARD_REQUIRED   ON)

set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(GNUInstallDirs)

message(NOTICE "LLVM_DIR: ${LLVM_DIR}")

find_package(LLVM CONFIG REQUIRED)

list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
include(HandleLLVMOptions)
add_definitions(${LLVM_DEFINITIONS})

include_directories(${LLVM_INCLUDE_DIRS})
llvm_map_components_to_libnames(LLVM_LIBRARIES Support Core)

add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(tests)