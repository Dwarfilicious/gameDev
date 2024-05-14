find_package(GLEW REQUIRED)
find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)

add_library(gameResources STATIC
    inputResources/mouseHandler.cpp
    mapResources/Color.cpp
    mapResources/Continent.cpp
    mapResources/Map.cpp
    mapResources/Territory.cpp
    mapResources/Tile.cpp
    playerResources/Player.cpp
    shapes/Square.cpp
)
target_include_directories(gameResources PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${GLEW_INCLUDE_DIRS})

target_link_libraries(gameResources PUBLIC json ${GLEW_LIBRARIES} ${GLUT_LIBRARIES} ${OPENGL_LIBRARIES})
