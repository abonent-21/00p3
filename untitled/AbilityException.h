#ifndef SHIP_GAME_ABILITYEXCEPTION_H
#define SHIP_GAME_ABILITYEXCEPTION_H

#include "Exception.h"

class NoAbilitiesException : public Exception {
public:
    NoAbilitiesException();

    virtual ~NoAbilitiesException() noexcept;
};

#endif //SHIP_GAME_ABILITYEXCEPTION_H
