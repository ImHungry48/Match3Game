#include "Match3Game.h"

Match3Game::Match3Game(int gridWidth, int gridHeight, int tileSize)
    : gameGrid(gridWidth, gridHeight), tileSize(tileSize), 
      gridWidth(gridWidth), gridHeight(gridHeight),
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
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                // Calculate grid position based on mouse click
                sf::Vector2i pos = sf::Mouse::getPosition(window) - offset;
                int x = pos.x / tileSize + 1;
                int y = pos.y / tileSize + 1;

                // CHeck if the click is in bounds of the grid
                if (x > 0 && x <= gridWidth && y > 0 && y <= gridHeight) {
                    SelectTile(y, x); // // Note: (y, x) are row and column respectively
                }
            }
        }
    }
}

void Match3Game::SelectTile(int row, int col) {
    if (!isTileSelected) {
        // Select the first tile
        selectedRow = row;
        selectedCol = col;
        isTileSelected = true;
    } else {
        // Select the second tile and try swapping
        swapRow = row;
        swapCol = col;
        TrySwapTiles();
    }
}

void Match3Game::TrySwapTiles() {
    // Check if the selected tiels are adjacent
    if ((abs(selectedRow - swapRow) == 1 && selectedCol == swapCol) || 
        (abs(selectedCol - swapCol) == 1 && selectedRow == swapRow)) {
        // Perform the swap
        gameGrid.SwapTiles(selectedRow, selectedCol, swapRow, swapCol);

        // TODO: Add logic to handle matches, animations, etc., after swapping
    }
}

void Match3Game::UpdateGame() {
    gameGrid.FindMatches(); // Find and mark matches in the grid
    gameGrid.ClearMatches(); // Clear matched tiles

    // TODO: Add loop that calls gameGrid.UpdateGrid() so tiles settle

    // Check if the player needs to make a move or if the game is over
    if (!gameGrid.IsMovePossible()) {
        // TODO: Handle game over or reset the grid
    }
}

void Match3Game::Render() {
    window.clear();
    window.draw(background);
    // Draw tiles and other game elements

    for (int i = 1; i <= gridHeight; i++) {
        for (int j = 1; j <= gridWidth; j++) {
            Tile& tile = gameGrid.GetTile(i - 1, j - 1);

            tileSprite.setTextureRect(sf::IntRect(static_cast<int>(tile.GetType()) * tileSize, 0, tileSize, tileSize));
            tileSprite.setColor(sf::Color(255, 255, 255, tile.GetAlpha())); // Set alpha for fading effect
            tileSprite.setPosition((j - 1) * tileSize, (i - 1) * tileSize);
            tileSprite.move(offset.x, offset.y); // Adjust for any offset
            window.draw(tileSprite);
        }
    }
    window.display();
}