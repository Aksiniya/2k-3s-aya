cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)

include(cmake/HunterGate.cmake)

HunterGate(
    URL "https://github.com/Aksiniya/hunter/archive/v0.19.137.1.tar.gz"
    SHA1 "5568fca5fbb7a6bf9f8b6c50c54ff74667e548e7"
)

project(demo)

hunter_add_package(print)
hunter_add_package(Boost COMPONENTS filesystem  system program_options)

find_package(print)
find_package(Boost COMPONENTS filesystem system program_options REQUIRED)

add_executable(demo ${CMAKE_CURRENT_SOURCE_DIR}/sources/demo.cpp)

target_link_libraries(demo print Boost::filesystem Boost::system  Boost::program_options)

install(TARGETS demo RUNTIME DESTINATION bin)
