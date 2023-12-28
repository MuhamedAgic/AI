cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 20)

project(ml++)

find_package( OpenCV REQUIRED )
INCLUDE_DIRECTORIES( ${OpenCV_INCLUDE_DIRS} )


set(HEADER_FILES
  src/nn.h
  src/layer.h
  src/activation.h
  src/node.h
  src/node_edge.h
)

set(SOURCE_FILES
  src/nn.cpp
  src/layer.cpp
  src/activation.cpp
  src/node.cpp
  src/nnTester.cpp
  src/node_edge.cpp
)

add_executable(ml++ ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(ml++ ${OpenCV_LIBS})
