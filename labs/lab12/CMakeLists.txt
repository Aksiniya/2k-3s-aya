cmake_minimum_required(VERSION 3.0)

include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.19.123.tar.gz"
    SHA1 "57d07480686f82ddc916a5980b4f2a18e5954c2b"
)

project(download-curl)

hunter_add_package(CURL)
find_package(CURL CONFIG REQUIRED)

add_executable(foo main.cpp)

target_link_libraries(foo PRIVATE CURL::libcurl)
