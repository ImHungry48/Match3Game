#ifndef MATCH3GAME_H
#define MATCH3GAME_H

#include "GameGrid.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Match3Game {
public:
    // Constructor
    Match3Game(int gridWidth, int gridHeight, int tileSize);
    
    // Start game loop
    void Run();

private:
    GameGrid gameGrid;
    int tileSize;
    sf::Vector2i offset;
    sf:: RenderWindow window;

    // Grid dimensions
    int gridWidth, gridHeight;

    // SFML Resources
    sf::Texture backgroundTexture, tileTexture;
    sf::Sprite background, tileSprite;

    // Game state variables
    bool isSwap, isMoving, isMatchFound;

    // Variables for tile selection and tile swapping
    bool isTileSelected;
    int selectedRow, selectedCol;
    int swapRow, swapCol;

    // Tracking score
    int score;

    // Private methods for game logic
    void ProcessInput(); // Handles player input
    void UpdateGame(); // Updates the game state
    void Render(); // Renders the game

    // Methods for tile selection and swapping
    void SelectTile(int row, int col); // Handles tile selection
    void TrySwapTiles(); // Attempts to swap two selected tiles

    // Methods for calculating and the score
    int CalculateScore(int matchesCleared);
    void DisplayScore();

    // "Game Over" logic
    void ResetGame();
    void DisplayGameOverMessage();
    void ResetGameState();

};

#endif // MATCH3GAME_H