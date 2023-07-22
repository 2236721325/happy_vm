cmake_minimum_required(VERSION 3.25)
project(happy_vm)




set(BIN_PATH ${PROJECT_SOURCE_DIR}/cmake-build-debug/bin)
add_subdirectory(vm)
add_subdirectory(learn)

