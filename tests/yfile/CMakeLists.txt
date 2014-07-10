
aux_source_directory(. DIR_YFILE_SRC)
include_directories(${PROJECT_SOURCE_DIR}/include)

#test for yFile
project(yfile_test)
add_definitions(-DYFILE_TEST)
add_executable(yfile_test ${DIR_YFILE_SRC})
target_link_libraries(yfile_test yunTable_util)



