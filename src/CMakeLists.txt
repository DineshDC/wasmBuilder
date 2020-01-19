cmake_minimum_required(VERSION 3.0.0)
set(PROJ_NAME  wasmBuild)
project(${PROJ_NAME} VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


file(GLOB SRC_DIR 
    ${PROJECT_SOURCE_DIR}/*.cpp 
    ${PROJECT_SOURCE_DIR}/*.h)


add_executable(${PROJ_NAME} 
    ${SRC_DIR}
    )
target_link_libraries(${PROJ_NAME} stdc++fs pthread)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
