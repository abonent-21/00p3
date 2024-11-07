#ifndef DOUBLEDAMAGE_H
#define DOUBLEDAMAGE_H

#include "Ability.h"

class DoubleDamage : public Ability {
public:
    void use(GameField& gameField) override;
    std::string getName() const override; // Добавили эту строку
};

#endif // DOUBLEDAMAGE_H