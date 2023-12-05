#include "Match3Game.h"

Match3Game::Match3Game(int gridWidth, int gridHeight, int tileSize)
    : gameGrid(gridWidth, gridHeight), tileSize(tileSize), 
      gridWidth(gridWidth), gridHeight(gridHeight),
      window(sf::VideoMode(gridWidth * tileSize, gridHeight * tileSize), "Match-3 Game!"),
      isSwap(false), isMoving(false), isMatchFound(false),
      score(0) {

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
    bool animationInProgress = false;

    // Animate each tile
    for (int i = 0; i < gridHeight; i++) {
        for (int j = 0; j < gridWidth; j++) {
            Tile& tile = gameGrid.GetTile(i, j);
            tile.UpdatePosition();

            if (tile.IsAnimating()) {
                animationInProgress = true;
            }
        }
    }
    
    // If animations are finished, handle matches and update the grid
    if (!animationInProgress) {
        if (isSwap || isMatchFound) {
            gameGrid.FindMatches();  // Check for new matches
            int matchesCleared = gameGrid.ClearMatches();  // Clear matches and check if any were cleared

            if (matchesCleared > 0) {
                // Increment score based on the number of matches cleared
                score += CalculateScore(matchesCleared);

                // Shift tiles down and generate new tiles
                gameGrid.ShiftTilesDown();
                gameGrid.GenerateNewTiles();
            } else if (isSwap) {
                // If no matches after a swap, it might be a game over condition or swap back
                if (!gameGrid.IsMovePossible()) {
                    // Handle game over
                    ResetGame();  // or any other game over logic
                } else {
                    // Swap the tiles back if no match was found
                    gameGrid.SwapTiles(selectedRow, selectedCol, swapRow, swapCol);
                }
                isSwap = false;
            }

            isMatchFound = false;  // Reset match found flag
        }
    }
    
}

int Match3Game::CalculateScore(int matchesCleared) {
    return matchesCleared * 10;
}

void Match3Game::Render() {
    window.clear();
    window.draw(background);
    // Draw tiles and other game elements

    for (int i = 0; i < gridHeight; i++) {
        for (int j = 0; j < gridWidth; j++) {
            Tile& tile = gameGrid.GetTile(i, j);
            sf::Vector2f screenPos = tile.GetScreenPosition();

            tileSprite.setTextureRect(sf::IntRect(static_cast<int>(tile.GetType()) * tileSize, 0, tileSize, tileSize));
            tileSprite.setColor(sf::Color(255, 255, 255, tile.GetAlpha())); // Set alpha for fading effect
            tileSprite.setPosition(screenPos);
            window.draw(tileSprite);
        }
    }

    // Display the score
    DisplayScore();
    
    window.display();

}

void Match3Game::DisplayScore() {
    sf::Text scoreText;
    sf::Font font;
    if (!font.loadFromFile("")) { // TODO: Edit Stub for File
        // Handle error
    }

    scoreText.setFont(font);
    scoreText.setString("Score: " + std::to_string(score));
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10, 10); // Example position

    window.draw(scoreText);

    window.display();
}

void Match3Game::ResetGame() {
    // Display "Game Over" message
    DisplayGameOverMessage();

    // Pause for a few seconds to display the message
    sf::sleep(sf::seconds(3));

    // Re-initialize the grid for a new game
    gameGrid.InitializeGrid();

    // Reset other game state variables
    ResetGameState();

    // Redraw the initial game state
    Render();
}

void Match3Game::DisplayGameOverMessage() {
    sf::Text gameOverText;
    sf::Font font;

    if (!font.loadFromFile("")) { // TODO: Edit stub for file
        // Handle error
    }

    gameOverText.setFont(font);
    gameOverText.setString("Game Over");
    gameOverText.setCharacterSize(24);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setStyle(sf::Text::Bold);
    gameOverText.setPosition(window.getSize().x / 2.0f, window.getSize().y / 2.0f); // Center the text

    window.draw(gameOverText);
    window.display();
}

void Match3Game::ResetGameState() {
    // Reset game flags
    isSwap = false;
    isMoving = false;
    isMatchFound = false;
}