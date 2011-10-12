project(displaymanager)

add_library(displaymanager factory.cpp window.cpp screenimpl.cpp process.cpp)

add_executable(displaymanagerApp  main.cpp)
TARGET_LINK_LIBRARIES(displaymanagerApp
  displaymanager
)
