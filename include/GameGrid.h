#ifndef GAMEGRID
#define GAMEGRID

#include <vector>
#include "Tile.h"

class GameGrid {
public:
    GameGrid(int width, int height);

    // Grid initialization
    void InitializeGrid();

    // Swap functionality
    void SwapTiles(int row1, int col1, int row2, int col2);

    // Match checking and clearing
    void FindMatches();
    void ClearMatches();

    // Grid updating
    void UpdateGrid();

    // Utility functions
    bool IsMovePossible() const;
    Tile& GetTile(int row, int col);

private:
    int width, height; // Grid dimensions
    std::vector<std::vector<Tile>> grid; // 2D grid of tiles

    // Helper methods
    TileType GenerateRandomType() const;
    bool CheckForInitialMatches(int row, int col, TileType type) const;
};

#endif // GAMEGRID