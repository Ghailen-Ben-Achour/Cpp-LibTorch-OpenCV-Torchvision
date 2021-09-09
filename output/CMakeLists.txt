cmake_minimum_required(VERSION 3.1)

project(visualize)

set(CMAKE_PREFIX_PATH /home/ghailen/cpp/libtorch)
set(CMAKE_INSTALL_PREFIX /usr/local)
set(CMAKE_BUILD_TYPE Release)
set(OPENCV_EXTRA_MODULES_PATH /home/ghailen/cpp/opencv/opencv-master/modules)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

find_package( OpenCV REQUIRED )
find_package(Torch REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS}")
message(STATUS "OpenCV library status:")
message(STATUS "    config: ${OpenCV_DIR}")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

add_executable(main src/main.cpp
                    include/convert.h
                   )

target_include_directories(main PRIVATE include)
target_link_libraries( main ${OpenCV_LIBS})
target_link_libraries(main "${TORCH_LIBRARIES}")

set_property(TARGET main PROPERTY CXX_STANDARD 14)

