find_package(GLEW REQUIRED)

add_executable(graphicsTest graphicsTest.cpp)
add_executable(test test.cpp)
add_executable(visualTest visualTest.cpp)

target_link_libraries(test PUBLIC gameResources)
target_link_libraries(visualTest PUBLIC gameResources maps)
target_link_libraries(graphicsTest PUBLIC gameResources ${GLEW_LIBRARIES} -lfreeglut -lopengl32)

file(GLOB MAPS "${CMAKE_SOURCE_DIR}/src/maps/*.json")
foreach(MAP ${MAPS})
    add_custom_command(TARGET visualTest POST_BUILD
                       COMMAND ${CMAKE_COMMAND} -E copy_if_different
                       ${MAP}
                       $<TARGET_FILE_DIR:visualTest>)
endforeach()
