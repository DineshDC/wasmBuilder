cmake_minimum_required(VERSION 3.0.0)
set(PROJECT __PROJECT__)
project(${PROJECT} VERSION 0.1.0)


# set(CMAKE_CXX_COMPILER em++)
# set(CMAKE_C_COMPILER emcc)

file(GLOB SRC_DIR 
   *.cpp
  )

add_custom_target(${PROJECT} ALL DEPENDS ${PROJECT}.js cpTodestin)
# add_definitions (${PROJECT} PUBLIC --std=c++11 -s WASM=1 -s "EXTRA_EXPORTED_RUNTIME_METHODS=['addOnPostRun']" --bind)
add_custom_command(
    OUTPUT ${PROJECT}.js
    COMMAND em++ --bind --std=c++11 ${SRC_DIR} -s WASM=1 -s "EXTRA_EXPORTED_RUNTIME_METHODS=['addOnPostRun']"  -o ${PROJECT}.js
)


add_custom_command(
    OUTPUT cpTodestin
    COMMAND cp ${BUILD_ROOT}/src/${PROJECT}.js ${BUILD_ROOT}/src/${PROJECT}.wasm ${WWW_ROOT}
)
