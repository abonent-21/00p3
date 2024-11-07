#include "Bombing.h"
#include "GameField.h"
#include <iostream>

void Bombardment::use(GameField& gameField) {
    gameField.randomBombardment();
}

std::string Bombardment::getName() const {
    return "Bombing\n";
}