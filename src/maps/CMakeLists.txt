add_library(maps STATIC
    mapHandler.cpp
)
target_include_directories(maps PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(maps PUBLIC gameResources)
