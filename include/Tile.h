#ifndef TILE_H
#define TILE_H

enum class TileType {
    Hexagon, Circle, Triangle, Heart, Diamond, Square
};

class Tile {
public:
    // Constructors
    Tile();
    Tile(const TileType& type, int gridRow, int gridCol);

    // Destructor
    ~Tile();

    // Setters and Getters for type
    void SetType(TileType type);
    TileType GetType() const;

    // Setters and Getters for grid position
    void SetPosition(int row, int col);
    int GetRow() const;
    int GetColumn() const;

    // Setters and Getters for screen positions
    void SetScreenPosition(int x, int y);
    int GetX() const;
    int GetY() const;

    // Matching properties
    void SetMatch(bool match);
    bool IsMatch() const;

    // Animation properties
    void SetAlpha(int alpha);
    int GetAlpha() const;

    // Swap functionality
    void Swap(Tile& other);

private:
    TileType type; // Piece type on tile
    int gridRow, gridCol; // Position in the grid
    int x, y; // Position on the screen
    bool match; // Flag to indicate if the tile is part of a match
    int alpha; // Alpha value for animation
};

#endif // TILE_H