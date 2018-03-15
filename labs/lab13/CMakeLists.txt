cmake_minimum_required(VERSION 3.2)

include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.19.123.tar.gz"
    SHA1 "57d07480686f82ddc916a5980b4f2a18e5954c2b"
)

project(yaml)
hunter_add_package(yaml-cpp)
find_package(yaml-cpp CONFIG REQUIRED)

add_executable(pack sources/pack.cpp)
add_executable(unpack sources/unpack.cpp)

target_link_libraries(pack yaml-cpp::yaml-cpp)
target_link_libraries(unpack yaml-cpp::yaml-cpp)
