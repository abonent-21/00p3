#ifndef SHIP_GAME_ATTACKOUTOFFIELD_H
#define SHIP_GAME_ATTACKOUTOFFIELD_H


#include "Exception.h"

class AttackOutOfBoundsException : public Exception {
public:
    AttackOutOfBoundsException();

    virtual ~AttackOutOfBoundsException() noexcept; // Добавлен виртуальный деструктор
};

#endif //SHIP_GAME_ATTACKOUTOFFIELD_H
