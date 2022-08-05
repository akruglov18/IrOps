set(ProjectId Tensor)
project(${ProjectId})

file(GLOB_RECURSE ALL_SOURCE_FILES *.cpp *.h)

add_library(${ProjectId} ${ALL_SOURCE_FILES})
target_link_libraries(${ProjectId})
