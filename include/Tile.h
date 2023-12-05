#ifndef TILE_H
#define TILE_H

enum class TileType {
    Hexagon, Circle, Triangle, Heart, Diamond, Square
};

class Tile {
public:
    // Constructors
    Tile();
    Tile(const TileType& type);


    // Destructor
    ~Tile();

    void SetType(TileType type);
    TileType GetType() const;

    void Swap(Tile& other);
    bool IsMatch(const Tile& other) const;

private:
    TileType type;
};

#endif // TILE_H