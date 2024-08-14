# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++17

# Directories
SRC_DIR = processor
OBJ_DIR = out

# Source files
SRC = main.cpp $(SRC_DIR)/image.cpp
# Object files
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

# Executable name
TARGET = program

# Create the object directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Rule to build the executable
$(TARGET): $(OBJ) | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

# Rule to build object files
$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove object files and executable
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Phony targets
.PHONY: clean
