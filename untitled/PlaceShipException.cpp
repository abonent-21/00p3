#include "PlaceShipException.h"

ShipPlacementException::ShipPlacementException()
        : Exception("Impossible place a ship. Error of placement") {}

ShipPlacementException::~ShipPlacementException() noexcept {} // Реализация деструктора