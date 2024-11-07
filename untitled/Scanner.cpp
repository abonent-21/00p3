#include "Scanner.h"
#include "GameField.h"
#include <iostream>

void Scanner::use(GameField& gameField) {
    int x, y;
    std::cout << "Enter a coord of scanning: ";
    std::cin >> x >> y;

    if (!gameField.scanArea(x, y)) {
        std::cout << "Error of coordinates of scanning area\n";
    }
}

std::string Scanner::getName() const {
    return "Scanner\n";
}