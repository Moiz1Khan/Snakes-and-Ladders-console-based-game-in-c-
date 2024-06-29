# Snakes-and-Ladders-console-based-game-in-c++

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Game Rules](#game-rules)
- [Contributing](#contributing)
- [License](#license)

## Introduction

Welcome to the classic Snake and Ladder game implemented in C++. This project is a console-based application where players can roll the dice and move their pieces on a 10x10 board. The game includes features such as saving and loading game progress, displaying player positions, and handling special rules for snakes and ladders.

## Features

- 4-player game
- Save and load game functionality
- Snakes and Ladders board with predefined positions
- Simple and intuitive user interface
- Game records and player rankings

## Installation

To run this project, you need to have a C++ compiler installed on your machine. Follow the steps below to set up and run the game:

1. Clone the repository:
    ```bash
    git clone https://github.com/your-username/snake-and-ladder-game.git
    cd snake-and-ladder-game
    ```

2. Compile the source code:
    ```bash
    g++ -o snake_and_ladder snake_and_ladder.cpp
    ```

3. Run the executable:
    ```bash
    ./snake_and_ladder
    ```

## Usage

1. Upon starting the game, you will be prompted to enter the names of the four players.
2. After entering the names, you will see the main menu with the following options:
    - Start New Game
    - Continue Saved Game
    - View Records
    - Credits
    - Exit
3. Select the desired option by entering the corresponding number.
4. Follow the on-screen instructions to play the game.

## Game Rules

### Snakes

- If a player lands on a snake's head, they slide down to the tail of the snake.

### Ladders

- If a player lands on the bottom of a ladder, they climb up to the top of the ladder.

### Dice Rolls

- Players roll two dice each turn. If they roll a total of 12 (double sixes), they get an additional turn.
- The player must roll a 6 to start moving their piece onto the board.

### Winning the Game

- The first player to reach exactly 100 wins the game. If a player's roll exceeds 100, their position remains unchanged.

## Contributing

We welcome contributions to improve this project! Here are some ways you can contribute:

- Report bugs and issues
- Suggest new features or improvements
- Submit pull requests to add new features or fix bugs

Please ensure that your contributions align with the project's coding style and standards.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.
