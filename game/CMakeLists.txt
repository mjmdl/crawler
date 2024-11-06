cmake_minimum_required(VERSION 3.22.1)
project(crawler)

file(GLOB_RECURSE CRAWLER_SOURCES code/**.cpp)
add_executable(${PROJECT_NAME} ${CRAWLER_SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE code)
target_link_libraries(${PROJECT_NAME} PUBLIC knave_engine)
