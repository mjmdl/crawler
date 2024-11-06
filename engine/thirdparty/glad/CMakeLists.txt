cmake_minimum_required(VERSION 3.22.1)
project(glad)

file(GLOB_RECURSE GLAD_SOURCES src/**.c)
add_library(${PROJECT_NAME} ${GLAD_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} PUBLIC GL)
