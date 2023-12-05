# Compiler settings
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

# SFML Settings
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Directory settings
SRC_DIR = .
OBJ_DIR = obj
BIN_DIR = bin

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Executable name
EXEC = Match3Game

all: $(BIN_DIR)/$EXEC

$(BIN_DIR)/$(EXEC): $(OBJS)
    $(CXX) $(OBJS) -o $@ $(SFML_LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

# Create directories if they don't exist
$(shell mkdir -p $(SRC_DIR) $(OBJ_DIR) $(BIN_DIR))

clean:
    rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/$(EXEC)

.PHONY: all clean