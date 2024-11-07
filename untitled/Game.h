#ifndef SHIP_GAME_GAME_H
#define SHIP_GAME_GAME_H

#include "GameField.h"
#include "ShipManager.h"
#include "AbilityManager.h"
#include <vector>

class Game {
public:
    Game();

    void run();

private:
    void start_game();

    void placeShips();

    void gameLoop();

    int numShips_;
    AbilityManager abilityManager_;
    GameField gameField_;
    std::vector<int> shipSizes_;
};

#endif //SHIP_GAME_GAME_H
