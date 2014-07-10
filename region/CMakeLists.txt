
aux_source_directory(. DIR_REGION_SRC)
include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(regin ${DIR_REGION_SRC})

target_link_libraries(regin pthread)
target_link_libraries(regin yunTable_util)
