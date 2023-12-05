#include "GameGrid.h"
#include <cstdlib> // For rand and srand
#include <ctime> // For time

GameGrid::GameGrid(int width, int height) : width(width), height(height), grid(height, std::vector<Tile>(width)) {
    srand(static_cast<unsigned int>(time(nullptr))); // Seed for random number generation
    InitializeGrid();
}

void GameGrid::InitializeGrid() {
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            TileType type;
            do {
                type = GenerateRandomType();
            } while (CheckForInitialMatches(row, col, type));
            grid[row][col] = Tile(type, row, col);
        }
    }
}

void GameGrid::SwapTiles(int row1, int col1, int row2, int col2) {
    std::swap(grid[row1][col1], grid[row2][col2]);
    // Update positions of swapped tiles
    grid[row1][col1].SetPosition(row1, col1);
    grid[row2][col2].SetPosition(row2, col2);
}

void GameGrid::FindMatches() {

}

void GameGrid::ClearMatches() {

}

void GameGrid::UpdateGrid() {

}

bool GameGrid::IsMovePossible() const {

}

Tile& GameGrid::GetTile(int row, int col) {
    return grid[row][col];
}

TileType GameGrid::GenerateRandomType() const {
    return static_cast<TileType>(rand() % 6); // 6 different types
}

bool GameGrid::CheckForInitialMatches(int row, int col, TileType type) const {
    // Implement logic to check for intial matches
    return false;
}