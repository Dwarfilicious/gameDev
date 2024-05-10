add_executable(test test.cpp)
add_executable(visualTest visualTest.cpp)

target_link_libraries(test PUBLIC gameResources)
target_link_libraries(visualTest PUBLIC gameResources maps)
