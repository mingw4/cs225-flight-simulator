cmake_minimum_required(VERSION 3.0.0)
project(DAN VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(DAN main.cpp dataloader.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
target_link_libraries(${PROJECT_NAME} png)
include(CPack)
