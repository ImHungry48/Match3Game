#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

enum class TileType {
    Hexagon, Circle, Triangle, Heart, Diamond, Square
};

class Tile {
public:
    // Constructors
    Tile(TileType& type, int gridRow, int gridCol);

    // Destructor
    ~Tile();

    // Setters and Getters for type
    void SetType(TileType type);
    TileType GetType() const;

    // Setters and Getters for grid position
    void SetPosition(int row, int col);
    int GetRow() const;
    int GetCol() const;

    // Setters and Getters for screen positions
    void SetScreenPosition(int x, int y);
    sf::Vector2f GetScreenPosition() const;

    // Matching properties
    void SetMatch(bool match);
    bool IsMatch() const;

    // Animation properties
    void SetAlpha(int alpha);
    int GetAlpha() const;
    void UpdatePosition(); // Updates position for animation
    bool IsAnimating() const; // Checks if the tile is currently animating

    // Swap functionality
    void Swap(Tile& other);

private:
    TileType type; // Piece type on tile
    int gridRow, gridCol; // Position in the grid
    sf::Vector2f position; // Current screen position
    sf::Vector2f target; // Target screen position for animation
    sf::Vector2f velocity; // Velocity for moving toward the target
    bool match; // Flag to indicate if the tile is part of a match
    int alpha; // Alpha value for animation
};

#endif // TILE_H