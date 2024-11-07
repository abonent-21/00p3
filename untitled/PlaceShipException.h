#ifndef SHIP_GAME_PLACESHIPEXCEPTION_H
#define SHIP_GAME_PLACESHIPEXCEPTION_H

#include "Exception.h"

class ShipPlacementException : public Exception {
public:
    ShipPlacementException();

    virtual ~ShipPlacementException() noexcept;
};


#endif //SHIP_GAME_PLACESHIPEXCEPTION_H
