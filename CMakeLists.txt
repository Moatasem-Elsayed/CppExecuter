cmake_minimum_required(VERSION 3.27)

project(cppExecuter)

set(CMAKE_CXX_STANDARD 14)

find_package(PkgConfig REQUIRED)
pkg_search_module(SFML REQUIRED sfml-all)
add_subdirectory(src)
