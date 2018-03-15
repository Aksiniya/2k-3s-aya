cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(explorer)

set(EXPLORER_VERSION_MAJOR 0)
set(EXPLORER_VERSION_MINOR 1)
set(EXPLORER_VERSION_PATCH 0)
set(EXPLORER_VERSION_TWEAK 0)
set(EXPLORER_VERSION 
${EXPLORER_VERSION_MAJOR}.${EXPLORER_VERSION_MINOR}.${EXPLORER_VERSION_PATCH}.${EXPLORER_VERSION_TWEAK})
set(EXPLORER_VERSION_STRING "v${EXPLORER_VERSION}")

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)

find_package(Boost COMPONENTS filesystem REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -I /usr/local/include -L /usr/local/lib -lboost_system -lboost_filesystem")

set(SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/sources/explorer.cpp)

add_executable(${PROJECT_NAME} ${SRC_LIST})

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})

include(CPackConfig.cmake)
