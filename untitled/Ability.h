#ifndef ABILITY_H
#define ABILITY_H

#include <string>

class GameField;

class Ability {
public:
    virtual ~Ability() = default;

    virtual void use(GameField &gameField) = 0;

    virtual std::string getName() const = 0; // Добавили эту строку
};

#endif // ABILITY_H