#include "Tile.h"

// Constructor
Tile::Tile(TileType type, int gridRow, int gridCol)
    : type(type), gridRow(gridRow), gridCol(gridCol), match(false), alpha(255), position(0, 0), target(0, 0), velocity(0, 0) {
    // Initialization logic (if needed)
}

void Tile::SetType(TileType type) {
    this->type = type;
}

TileType Tile::GetType() const {
    return type;
}

void Tile::SetPosition(int row, int col) {
    gridRow = row;
    gridCol = col;
}

int Tile::GetRow() const {
    return gridRow;
}

int Tile::GetCol() const {
    return gridCol;
}

void Tile::SetScreenPosition(int x, int y) {
    position = sf::Vector2f(static_cast<float>(x), static_cast<float>(y));
    target = position; // Initialize target to the current position
}

sf::Vector2f Tile::GetScreenPosition() const {
    return position;
}

void Tile::SetMatch(bool match) {
    this->match = match;
}

bool Tile::IsMatch() const {
    return match;
}

void Tile::SetAlpha(int alpha) {
    this->alpha = alpha;
}

int Tile::GetAlpha() const {
    return alpha;
}

void Tile::UpdatePosition() {
    if (position != target) {
        sf::Vector2f delta = target - position;
        position += velocity;
    }
}

bool Tile::IsAnimating() const {
    return position != target; // Tile is animating if its position is not yet at the target
}