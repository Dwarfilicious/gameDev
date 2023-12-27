# Variables
CXX = g++
CXXFLAGS = -g3 -Wall
LDFLAGS = -lglut -lGL
SRC = $(wildcard *.cpp mapResources/*.cpp ../playerResources/*.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = mapTest

# Default target
all: $(TARGET)

# Linking
$(TARGET): $(OBJ)
	$(CXX) $^ -o $@ $(LDFLAGS)

# Compiling
%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

# Clean
clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
