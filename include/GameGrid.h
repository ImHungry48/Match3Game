#ifndef GAMEGRID
#define GAMEGRID

#include <vector>
#include "Tile.h"

class GameGrid {
public:
    GameGrid(int width, int height);

    void InitializeGrid();

private:
    int width, height;
    std::vector<std::vector<Tile>> grid;

    // Helper methods
    TileType GenerateRandomType() const;
};

#endif // GAMEGRID