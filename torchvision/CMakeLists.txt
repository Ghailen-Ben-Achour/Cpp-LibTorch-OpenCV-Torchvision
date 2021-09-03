cmake_minimum_required(VERSION "3.12")

project(torch-demo)
set(OpenCV_DIR /home/ghailen/cpp/opencv/opencv-master/modules)

set(CMAKE_CXX_STANDARD 14)


find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(torch-demo main.cpp)

target_link_libraries(torch-demo ${OpenCV_LIBS} )


cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
list(APPEND CMAKE_PREFIX_PATH "/home/ghailen/cpp/libtorch")

find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

target_link_libraries(torch-demo "${TORCH_LIBRARIES}")
set_property(TARGET torch-demo PROPERTY CXX_STANDARD 14)


if (MSVC)
  file(GLOB TORCH_DLLS "${TORCH_INSTALL_PREFIX}/lib/*.dll")
  add_custom_command(TARGET example-app
                     POST_BUILD
                     COMMAND ${CMAKE_COMMAND} -E copy_if_different
                     ${TORCH_DLLS}
                     $<TARGET_FILE_DIR:example-app>)
endif (MSVC)



cmake_minimum_required(VERSION 3.12)
list(APPEND CMAKE_PREFIX_PATH "/home/ghailen/cpp/vision")


find_package(TorchVision REQUIRED)

target_link_libraries(torch-demo TorchVision::TorchVision)
