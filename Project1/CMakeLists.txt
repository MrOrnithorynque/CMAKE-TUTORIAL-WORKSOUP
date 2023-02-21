cmake_minimum_required(VERSION 3.20)

project("YES")

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

set(SRCS
    srcs/SimpleHelloWorldProgram.cpp
)

set(HEADERS
    includes/
)

add_executable(${PROJECT_NAME} ${SRCS})

target_include_directories(${PROJECT_NAME} PUBLIC ${HEADERS})
