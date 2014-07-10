
include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(master master.c)

target_link_libraries(master pthread)
target_link_libraries(master yunTable_util)
