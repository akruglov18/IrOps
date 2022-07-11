set(ProjectId Checker)
project(${ProjectId})

file(GLOB_RECURSE ALL_SOURCE_FILES *.cpp *.h *.hpp)

add_executable(${ProjectId} ${ALL_SOURCE_FILES})
target_link_libraries(${ProjectId})
