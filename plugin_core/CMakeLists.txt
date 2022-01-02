cmake_minimum_required(VERSION 3.4.6)
project(MyPluginMaster)

# set(CMAKE_CXX_COMPLIRE "g++")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --std=c++14 -g -O0 -fPIC -Wall -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g  -O0 --std=c++14 -fPIC -Wall -Werror")

message("${PROJECT_SOURCE_DIR}/../build")
include_directories("${PROJECT_SOURCE_DIR}/..")
link_directories("${PROJECT_SOURCE_DIR}/../build")
file(GLOB_RECURSE all_plugin_src "${PROJECT_SOURCE_DIR}/src/**.cpp")
add_library(all_plugin_objs OBJECT ${all_plugin_src})
add_library(MyPlugin SHARED $<TARGET_OBJECTS:all_plugin_objs>)
target_link_libraries(MyPlugin plugincore)