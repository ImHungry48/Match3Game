#include "GameGrid.h"
#include <cstdlib> // For rand and srand
#include <ctime> // For time

// Constructor or GameGrid class
GameGrid::GameGrid(int width, int height) : width(width), height(height), grid(height, std::vector<Tile>(width)) {
    srand(static_cast<unsigned int>(time(nullptr))); // Seed for random number generation
    InitializeGrid();
}

// Initializes the grid with random tiles, ensuring no initial matches
void GameGrid::InitializeGrid() {
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            TileType type;
            // Keep generating a random type until one is found that doesn't create an initial match
            do {
                type = GenerateRandomType();
            } while (CheckForInitialMatches(row, col, type));
            // Assign a random type until one is found that doesn't create an initial match
            grid[row][col] = Tile(type, row, col);
        }
    }
}

// Swaps two tiles in the grid
void GameGrid::SwapTiles(int row1, int col1, int row2, int col2) {
    std::swap(grid[row1][col1], grid[row2][col2]);
    // Update positions of swapped tiles
    grid[row1][col1].SetPosition(row1, col1);
    grid[row2][col2].SetPosition(row2, col2);
}

// Find and marks matching tiles (three of same type in rows and columns)
void GameGrid::FindMatches() {
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            // Check for horizontal matches
            if (col > 1 &&
                grid[row][col].GetType() == grid[row][col - 1].GetType() &&
                grid[row][col].GetType() == grid[row][col - 2].GetType()) {
                for (int n = 0; n < 3; n++) {
                    grid[row][col - n].SetMatch(true);
                }
            }

            // Check for vertical matches
            if (row > 1 &&
                grid[row][col].GetType() == grid[row - 1][col].GetType() &&
                grid[row][col].GetType() == grid[row - 2][col].GetType()) {
                for (int n = 0; n < 3; n++) {
                    grid[row - n][col].SetMatch(true);
                }
            }
        }
    }
}

// Clears matched tiles from the grid
int GameGrid::ClearMatches() {
    int clearedCount = 0;
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            if (grid[row][col].IsMatch()) {
                grid[row][col].SetAlpha(0);
                grid[row][col].SetMatch(false);
                clearedCount++;
            }
        }
    }
    return clearedCount;
}

// Updates the grid after clearing matches
void GameGrid::UpdateGrid() {
    for (int col = 0; col < width; col++) {
        for (int row = height - 1; row >= 0; row--) {
            // If a tile has been cleared
            if (grid[row][col].GetAlpha() == 0) {
                // Shift tiles above the cleared tile down
                for (int n = row; n > 0; n--) {
                    SwapTiles(n, col, n - 1, col);
                }
                // Generate a new tile at the top of the column
                grid[0][col] = Tile(GenerateRandomType(), 0, col);
                grid[0][col].SetAlpha(255); // Reset alpha to opaque
            }
        }
    }
}

// Stub function to determine if any moves are possible that would result in a match
bool GameGrid::IsMovePossible() const {
    return true; // TODO: Implement comprehensive logic to check for possible moves
}

// Returns a reference to the tile at a given position in the grid
Tile& GameGrid::GetTile(int row, int col) {
    return grid[row][col];
}

// Generates a random tile type
TileType GameGrid::GenerateRandomType() const {
    return static_cast<TileType>(rand() % 6); // 6 different types
}

// Checks whether placing a tile of a given type at a specific position would create an initial match
bool GameGrid::CheckForInitialMatches(int row, int col, TileType type) const {
    // Check left and above (since we fill the grid from top-left)
    if (col >= 2 && 
        type == grid[row][col - 1].GetType() && 
        type == grid[row][col - 2].GetType()) {
        return true; // Horizontal match found
    }
    if (row >= 2 && 
        type == grid[row - 1][col].GetType() && 
        type == grid[row - 2][col].GetType()) {
        return true; // Vertical match found
    }
    return false; // No match found
}

void GameGrid::ShiftTilesDown() {
    for (int col = 0; col < width; col++) {
        for (int row = height - 1; row > 0; row--) {
            if (grid[row][col].GetAlpha() == 0) {
                for (int n = row; n > 0; n--) {
                    SwapTiles(n, col, n - 1, col);
                }
            }
        }
    }
}

void GameGrid::GenerateNewTiles() {
    for (int col = 0; col < width; col++) {
        if (grid[0][col].GetAlpha() == 0) { // Check if the top tile in the column is cleared
            grid[0][col] = Tile(GenerateRandomType(), 0, col);
            grid[0][col].SetAlpha(255); // Reset alpha to opaque
        }
    }
}