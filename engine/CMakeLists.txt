cmake_minimum_required(VERSION 3.22.1)
project(knave_engine)

add_subdirectory(thirdparty/glad)
add_subdirectory(thirdparty/glfw)

file(GLOB_RECURSE KNAVE_SOURCES code/**.cpp)
add_library(${PROJECT_NAME} ${KNAVE_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC code)
target_link_libraries(${PROJECT_NAME} PUBLIC glad glfw)

target_compile_definitions(${PROJECT_NAME} PUBLIC KNAVE_GLFW=1)
