cmake_minimum_required(VERSION 3.0.0)
project(wasmBuildWorkspace VERSION 0.1.0)

include(CTest)
enable_testing()


set(SDK_ROOT ${PROJECT_SOURCE_DIR}/sdk)
set(SRC_ROOT ${PROJECT_SOURCE_DIR}/src)
set(TESTS_ROOT ${PROJECT_SOURCE_DIR}/tests)

add_subdirectory(${SRC_ROOT})
add_subdirectory(${TESTS_ROOT})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
