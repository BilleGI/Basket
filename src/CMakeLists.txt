cmake_minimum_required(VERSION 3.5)

add_executable(basket main.cpp basket.cpp ${MY_INCLUDE_DIR}/basket.h)

target_include_directories(basket PRIVATE ${MY_INCLUDE_DIR})
