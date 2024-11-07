#include "DoubleDamage.h"
#include "GameField.h"
#include <iostream>

void DoubleDamage::use(GameField& gameField) {
    gameField.setDoubleDamageActive(true);
    std::cout << "Used double damaged\n";
}

std::string DoubleDamage::getName() const {
    return "Double damage\n";
}