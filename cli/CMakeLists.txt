
include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(cli cli.c)

target_link_libraries(cli yunTable_util)
