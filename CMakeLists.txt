cmake_minimum_required(VERSION 3.14)
project(MyPluginMaster)

# set(CMAKE_CXX_COMPLIRE "g++")
find_package(Threads REQUIRED)
set(CMAKE_C_FLAGS_ "${CMAKE_C_FLAGS} -g -O0 -std=c++14 -fPIC -Wall -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 --std=c++14 -fPIC -Wall -Werror")

include_directories("${CMAKE_SOURCE_DIR}")
include_directories("${CMAKE_SOURCE_DIR}/include")
file(GLOB_RECURSE MasterSrc "${CMAKE_SOURCE_DIR}/src/*.cpp")
#aux_source_directory("${CMAKE_SOURCE_DIR}/src" MasterSrc)

add_library(MasterObjs OBJECT   ${MasterSrc})
add_library(plugincore SHARED $<TARGET_OBJECTS:MasterObjs>)
target_link_libraries(plugincore m dl Threads::Threads)
install(
        TARGETS plugincore
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        PUBLIC_HEADER DESTINATION include           
)

add_subdirectory(plugin_core)



aux_source_directory("${PROJECT_SOURCE_DIR}/test" main_src)
add_executable(main ${main_src})
target_link_libraries(main plugincore)




