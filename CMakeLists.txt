project(yuntable)

set(CMAKE_C_COMPILER "gcc")
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_C_FLAGS_DEBUG "-g -Wall")

include_directories(${PROJECT_SOURCE_DIR})
add_subdirectory(cli)
add_subdirectory(master)
add_subdirectory(region)
add_subdirectory(util)
add_subdirectory(tests/yfile)
