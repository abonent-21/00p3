#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <vector>
#include "ShipManager.h"
#include "AbilityManager.h"

class GameField {
public:
    enum class CellStatus {
        Unknown, Empty, Ship, Hit, Occupied
    };

    GameField(int width, int height, AbilityManager &abilityManager);

    GameField(const GameField& other);
    GameField& operator=(const GameField& other);

    GameField(GameField&& other) noexcept;
    GameField& operator=(GameField&& other) noexcept;

    //деструктор
    ~GameField() = default;

    void print_field();

    void placeShip(Ship &&ship, int x, int y, Ship::Orientation orientation);

    void attackCell(int x, int y);

    void set_cell_status(CellStatus cell_status, int x, int y);

    bool allShipsDestroyed() const;

    void initializeShipManager(int numShips, const std::vector<int> &shipSizes);

    void setDoubleDamageActive(bool active);

    bool scanArea(int x, int y);

    void randomBombardment();

private:
    int width_, height_;
    std::vector<std::vector<CellStatus>> grid_;
    ShipManager shipManager_;
    AbilityManager& abilityManager_;
    bool doubleDamageActive_ = false;
};

#endif
