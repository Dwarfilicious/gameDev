Currently the main achievement is the completion of a flood-fill algorithm
that allows a grid map with enumerated tile types made in the Tiled application
to be imported from a JSON format and algorithmically converted to a usable
map in the context of the written classes. The inputTest.cpp code will compile
to an executable with CMake to show what that looks like with players randomly
assigned as owner to territories. This test also allows for clicking on the map
to print the clicked on map coordinates to the terminal.
