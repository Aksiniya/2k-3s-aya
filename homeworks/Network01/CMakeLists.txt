cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11) 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.19.123.tar.gz"
    SHA1 "57d07480686f82ddc916a5980b4f2a18e5954c2b"
)

project(client)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)
add_library(client STATIC ${CMAKE_CURRENT_SOURCE_DIR}/sources/client.cpp)

hunter_add_package(CURL)
find_package(CURL CONFIG REQUIRED)

add_executable(example ${CMAKE_CURRENT_SOURCE_DIR}/examples/main.cpp)
target_link_libraries(example PRIVATE CURL::libcurl)