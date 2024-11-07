#include "AttackOutOfField.h"

AttackOutOfBoundsException::AttackOutOfBoundsException()
        : Exception("Coordinate of attack out of border") {}

AttackOutOfBoundsException::~AttackOutOfBoundsException() noexcept {}