cmake_minimum_required(VERSION 3.10)
project(TextBufferProject LANGUAGES C CXX)


set(SOURCES
    src/TextBuffer.cpp
)

set(HEADERS
    include/TextBuffer.h
    include/utils.h
    include/main.h
)

add_library(TextBuffer STATIC ${SOURCES} ${HEADERS})

target_include_directories(TextBuffer PRIVATE include)

add_subdirectory(test_by_ggtest)