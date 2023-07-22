project(vm)


file(GLOB_RECURSE SRC_LIST src/*.cpp)

file(GLOB_RECURSE TEST_SRC_LIST "src/*.cpp" "test/*.cpp")
list(FILTER TEST_SRC_LIST EXCLUDE REGEX ".*main.cpp$")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_PATH})

add_executable(${PROJECT_NAME} ${SRC_LIST})
target_include_directories(${PROJECT_NAME} PUBLIC include lib/include)

add_executable(test_all ${TEST_SRC_LIST})

target_include_directories(test_all PUBLIC include test/include lib/include)

set(CMAKE_CXX_STANDARD 20)
