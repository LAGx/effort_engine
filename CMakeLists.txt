# by k_vark 

cmake_minimum_required (VERSION 3.10)
project (effort_engine)


#settings
set(PROJECT_SOURCE_DIR "/home/kvark/effort_project/core")
set(CMAKE_CXX_STANDARD 17)


#is exist project dir
IF(NOT EXISTS ${PROJECT_SOURCE_DIR})
        message(FATAL_ERROR "PROJECT_SOURCE_DIR not exists")
ENDIF()


#debug and release modes
if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    message(">> enable DEBUG_MODE mode")
    add_definitions(-DDEBUG_MODE=1)
elseif(${CMAKE_BUILD_TYPE} STREQUAL "Release")
    message(">> enable RELEASE_MODE mode")
    add_definitions(-DRELEASE_MODE=0)
    add_definitions(-DNDEBUG)
else()
    message(FATAL_ERROR "flag -DCMAKE_BUILD_TYPE=" ${CMAKE_BUILD_TYPE} " is invalid") #try to set -DCMAKE_BUILD_TYPE=Release or -DCMAKE_BUILD_TYPE=Debug
endif()

#windows, linux, macOS
# WIN_OS LINUX_OS MAC_OS
message(">> selected " ${OS} " operating system")
if( NOT ((${OS} STREQUAL "WIN_OS") OR (${OS} STREQUAL "LINUX_OS") OR (${OS} STREQUAL "MAC_OS")))
    message( FATAL_ERROR "flag -DOS=" ${OS} " is invalid") #try to set -DOS=LINUX_OS or -DOS=WIN_OS or -DOS=MAC_OS
endif()


file(GLOB_RECURSE ALL_CPP_NATIVE_CODE "${PROJECT_SOURCE_DIR}/source/*.cpp")
include_directories("${PROJECT_SOURCE_DIR}/source")


add_executable(${PROJECT_NAME}.run ${ALL_CPP_NATIVE_CODE})
