find_package(GLEW REQUIRED)

add_executable(graphicsTest graphicsTest.cpp)
add_executable(test test.cpp)
add_executable(visualTest visualTest.cpp)

target_link_libraries(test PUBLIC gameResources)
target_link_libraries(visualTest PUBLIC gameResources maps)
target_link_libraries(graphicsTest PUBLIC gameResources ${GLEW_LIBRARIES} -lfreeglut -lopengl32)
