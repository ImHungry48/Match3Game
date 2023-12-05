#include "Match3Game.h"

Match3Game::Match3Game(int gridWidth, int gridHeight, int tileSize)
    : gameGrid(gridWidth, gridHeight), tileSize(tileSize),
    window(sf::VideoMode(gridWidth * tileSize, gridHeight * tileSize), "Match-3 Game!"),
    isSwap(false), isMoving(false) {

    backgroundTexture.loadFromFile(""); // TODO: Insert file path
    tileTexture.loadFromFile(""); // TODO: Insert file path

    background.setTexture(backgroundTexture);
    tileSprite.setTexture(tileTexture);
}

void Match3Game::Run() {
    while (window.isOpen()) {
        ProcessInput();
        UpdateGame();
        Render();
    }
}

void Match3Game::ProcessInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        // TODO: Handle other input events such as mouse clicks, etc.
    }
}

void Match3Game::UpdateGame() {
    // TODO: Implement game update logic (check matches, update grid, handle animations)
}

void Match3Game::Render() {
    window.clear();
    window.draw(background);
    // Draw tiles and other game elements
    window.display();
}