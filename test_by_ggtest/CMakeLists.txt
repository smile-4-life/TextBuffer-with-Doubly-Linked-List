add_subdirectory(google_test_engine)
#create gtest and gtest_main

add_executable(mytest mytest.cpp)
#.exe

target_link_libraries(mytest TextBuffer gtest gtest_main)

target_include_directories(mytest PRIVATE ${CMAKE_SOURCE_DIR}/include)