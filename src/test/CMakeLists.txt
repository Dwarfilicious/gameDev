find_package(GLEW REQUIRED)
find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(graphicsTest graphicsTest.cpp)
add_executable(test test.cpp)
add_executable(inputTest inputTest.cpp)

target_link_libraries(test PUBLIC gameResources)
target_link_libraries(graphicsTest PUBLIC gameResources ${GLEW_LIBRARIES} ${GLUT_LIBRARIES} ${OPENGL_LIBRARIES})
target_link_libraries(inputTest PUBLIC gameResources ${GLEW_LIBRARIES} ${GLUT_LIBRARIES} ${OPENGL_LIBRARIES})

file(GLOB MAPS "${CMAKE_SOURCE_DIR}/src/maps/*.json")
foreach(MAP ${MAPS})
    add_custom_command(TARGET inputTest POST_BUILD
                       COMMAND ${CMAKE_COMMAND} -E copy_if_different
                       ${MAP}
                       $<TARGET_FILE_DIR:inputTest>)
endforeach()
