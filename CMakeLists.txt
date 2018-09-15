cmake_minimum_required (VERSION 3.10)
project (effort_engine)


#settings
set(PROJECT_SOURCE_DIR "/home/kvark/effort_project/core")
set (CMAKE_CXX_STANDARD 17)


IF(NOT EXISTS ${PROJECT_SOURCE_DIR})
        message(FATAL_ERROR "ROOT_PROJECT_DIR not exists")
ENDIF()

add_executable(${PROJECT_NAME}.run ${PROJECT_SOURCE_DIR}/engine/main.cpp)
