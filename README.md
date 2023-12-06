# Match3Game

A simple Match-3 style game implemented in C++ using the SFML Library.

## Table of Contents
- [Components](#components)
  - [GameGrid](#gamegrid)
  - [Tile](#tile)
  - [Match3Game](#match3game)
- [Dependencies](#dependencies)
- [Building and Running](#building-and-running)
- [Gameplay](#gameplay)
- [Customization](#customization)

## Components

**Class:** `Tile`

**Description:** Represents an individual tile on the game grid

**Features:**
- Holds information about the type, position, and matching state
- Supports animations for tile movement and interaction

**Class:** `GameGrid`

**Description:** Represents the game grid where all the tiles are placed and interacted with by the player

**Features:**
- Initializes the grid with random tiles
- Provides functionality for swapping tiles
- Checks and clears matching tiles
- Updates grid after clearning matches
- Determines if any moves are possible

**Class:** `Match3Game`

**Description:** Main class that handles the game logic and user interface

**Features:**
- Manages the game loop and processes user input
- Renders game state
- Handles tile selection and swapping logic
- Handles tile selection and swapping logic
- Calculates and displays the score
- Implements "Game Over" logic and resets state

## Dependencies
- [SFML (Simple and Fast Multimedia Library)](https://www.sfml-dev.org/)

## Building and Running
To build and run the game, ensure SFML is installed and properly linked in your build configuration. Compile the source files and link against the SFML library.

## Gameplay
- Players swap adjacent tiles to form a horizontal or vertical line of three or more similar tiles.
- Ten points are earned for each set of tiles cleared from the grid
- The game continues until no more moves are possible, at which point the grid is reset for a new game.

## Customization
- Tile types and grid dimensions can be easily customized in the source code.
- Additional features like power-ups, special tiles, or different game modes can be implemented by extending the existing classes.
