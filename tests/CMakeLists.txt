cmake_minimum_required(VERSION 3.0.0)
set(PROJ_NAME_T  wasmBuildTest)
project(${PROJ_NAME_T} VERSION 0.1.0)

include(CTest)
enable_testing()

file(GLOB SRC_TEST 
    ${TESTS_ROOT}/*.cpp
    ${TESTS_ROOT} *.h
)

set(GTEST_SDK ${SDK_ROOT}/gtest)

add_executable(${PROJ_NAME_T} ${SRC_TEST})
target_include_directories(${PROJ_NAME_T} PUBLIC
   ${GTEST_SDK}/inc
   ${SRC_ROOT}
)

target_link_libraries(${PROJ_NAME_T}
        ${GTEST_SDK}/libs/libgtest.a
        ${GTEST_SDK}/libs/libgtest_main.a
        pthread
    )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
