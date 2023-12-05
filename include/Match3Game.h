#ifndef MATCH3GAME_H
#define MATCH3GAME_H

#include "GameGrid.h"
#include <SFML/Graphics.hpp>

class Match3Game {
public:
    Match3Game(int gridWidth, int gridHeight, int tileSize);
    void Run();

private:
    GameGrid gameGrid;
    int tileSize;
    sf::Vector2i offset;
    sf:: RenderWindow window;

    // SFML Resources
    sf::Texture backgroundTexture, tileTexture;
    sf::Sprite background, tileSprite;

    // Game state variables
    int selectedRow, selectedCol;
    bool isSwap, isMoving;

    // Private methods for game logic
    void ProcessInput();
    void UpdateGame();
    void Render();


};

#endif // MATCH3GAME_H