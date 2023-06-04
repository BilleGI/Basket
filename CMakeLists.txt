cmake_minimum_required(VERSION 3.5)

project("Basket" VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_subdirectory(src)

install(TARGETS basket
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
