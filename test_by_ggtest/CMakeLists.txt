set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(google_test_engine)
#create gtest and gtest_main

add_executable(unittest_1 unittest_doubly_linked_list.cpp)
add_executable(unittest_2 unittest_text_buffer.cpp)
#.exe

target_link_libraries(unittest_1 TextBuffer gtest gtest_main)
target_link_libraries(unittest_2 TextBuffer gtest gtest_main)


target_include_directories(unittest_1 PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(unittest_2 PRIVATE ${CMAKE_SOURCE_DIR}/include)

