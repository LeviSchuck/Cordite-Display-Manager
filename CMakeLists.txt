    cmake_minimum_required(VERSION 2.8)

project(displaymanager)

add_library(displaymanager factory.cpp window.cpp screenimpl.cpp process.cpp)
    if(COMMAND cmake_policy)
      cmake_policy(SET CMP0003 NEW)
    endif(COMMAND cmake_policy)

TARGET_LINK_LIBRARIES(displaymanager
  SDL
)

add_executable(displaymanagerApp  main.cpp)
TARGET_LINK_LIBRARIES(displaymanagerApp
  displaymanager
  SDL
)
