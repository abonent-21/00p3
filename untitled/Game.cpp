#include "Game.h"
#include "ShipManager.h"
#include <iostream>
#include <string>
#include <limits>
#include "AbilityException.h"
#include "AttackOutOfField.h"
#include "PlaceShipException.h"

Game::Game()
        : abilityManager_(),
          gameField_(10, 10, abilityManager_),
          numShips_(0) {}

void Game::start_game() {
    std::cout << "___BUTTLE SHIP GAME___\n";

    while (true) {
        std::cout << "Enter number of ships:";
        std::cin >> numShips_;
        if (std::cin.fail() || numShips_ <= 0 || numShips_ > 5) {
            std::cout << "Error number must be positive or less than 5\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max());
        } else {
            break;
        }
    }

    for (int i = 1; i <= numShips_; ++i) {
        int length;
        while (true) {
            std::cout << "Enter a length of ship " << i<< ": \n";
            std::cin >> length;
            if (std::cin.fail() || length <= 0 || length > 4) {
                std::cout << "Error. Length of ship must be in range of 1 to 4\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max());
            } else {
                shipSizes_.push_back(length);
                break;
            }
        }
    }

    gameField_.initializeShipManager(numShips_, shipSizes_);
}

void Game::placeShips() {
    for (int i = 0; i < numShips_; ++i) {
        gameField_.print_field();
        int x, y;
        char orientation;
        while (true) {
            std::cout << "Enter the coordinate to place a ship lenght - " << shipSizes_[i] << ": ";
            std::cin >> x >> y;
            if (std::cin.fail() || x < 0 || x >= 10 || y < 0 || y >= 10) {
                std::cout << "Error. Try enter coordinate again!"
                          << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max());
                continue;
            }

            std::cout << "Choose h or v: ";
            std::cin >> orientation;
            if (orientation != 'h' && orientation != 'v') {
                std::cout << "Error. Incorrect letter. Print h - horizontal or v - vertical"
                          << std::endl;
                continue;
            }

            try {
                Ship::Orientation dir = (orientation == 'h') ? Ship::Orientation::Vertical
                                                             : Ship::Orientation::Horizontal;
                Ship ship(shipSizes_[i], dir);
                gameField_.placeShip(std::move(ship), x, y, dir);
                std::cout << "Ship successfully has been placed!\n";
                break;
            } catch (const ShipPlacementException &e) {
                std::cout << e.what() << "Error of placement. Try again!\n";
            }
        }
    }
}

void Game::gameLoop() {
    bool gameOver = false;
    std::string command;

    while (!gameOver) {
        gameField_.print_field();
        std::cout << "Enter x and y or print ability: ";
        std::cin >> command;

        if (command == "exit") {
            std::cout << "Game over" << std::endl;
            break;
        }

        if (command == "ability") {
            try {
                abilityManager_.useAbility(gameField_);
            } catch (const NoAbilitiesException &e) {
                std::cout << e.what() << std::endl;
            }
            if (gameField_.allShipsDestroyed()) {
                std::cout << "All ships has been destroyed! Game Over!" << std::endl;
                gameOver = true;
            }
            continue;
        }

        int x, y;
        try {
            x = std::stoi(command);
            if (!(std::cin >> y)) {
                throw std::invalid_argument("Invalid enter");
            }

            try {
                gameField_.attackCell(x, y);

                // Проверяем окончание игры после атаки
                if (gameField_.allShipsDestroyed()) {
                    std::cout << "All ships has been destroyed! Game Over!" << std::endl;
                    gameOver = true;
                }
            } catch (const AttackOutOfBoundsException &e) {
                std::cout << e.what() << std::endl;
            }
        } catch (std::exception &) {
            std::cout << "Invalid enter" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
    }
}

void Game::run() {
    start_game();
    placeShips();
    gameLoop();
}