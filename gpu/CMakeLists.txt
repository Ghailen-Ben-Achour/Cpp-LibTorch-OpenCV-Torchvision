cmake_minimum_required(VERSION 3.2)

project(torchtest)

set(CMAKE_PREFIX_PATH /home/ghailen/cpp/libtorch)

find_package(Torch REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS}")

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} "${TORCH_LIBRARIES}")

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)