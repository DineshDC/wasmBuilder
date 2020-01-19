cmake_minimum_required(VERSION 3.0.0)
project(__PROJECT__Workspace VERSION 0.1.0)


set(SDK_ROOT ${PROJECT_SOURCE_DIR}/sdk)
set(WWW_ROOT ${PROJECT_SOURCE_DIR}/www)
set(BUILD_ROOT ${PROJECT_SOURCE_DIR}/build)


add_subdirectory(${PROJECT_SOURCE_DIR}/src)
# add_subdirectory(${PROJECT_SOURCE_DIR}/libs)
# add_subdirectory(${PROJECT_SOURCE_DIR}/test)


include(CTest)
enable_testing()

