#include "AbilityException.h"

NoAbilitiesException::NoAbilitiesException()
        : Exception("Impossible apply ability. There are not any ability") {}

NoAbilitiesException::~NoAbilitiesException() noexcept {} // Реализация деструктора