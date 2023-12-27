cmake_minimum_required(VERSION 3.15)

project(ml++)

find_package( OpenCV REQUIRED )
INCLUDE_DIRECTORIES( ${OpenCV_INCLUDE_DIRS} )


set(HEADER_FILES
  src/nn.h
  src/layer.h
  src/activation.h
  src/node.h
)

set(SOURCE_FILES
  src/nn.cpp
  src/layer.cpp
  src/activation.cpp
  src/node.cpp
  src/nnTester.cpp
)

add_executable(ml++ ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(ml++ ${OpenCV_LIBS})
