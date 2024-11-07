#ifndef SHIP_GAME_EXCEPTION_H
#define SHIP_GAME_EXCEPTION_H

#include <exception>
#include <string>

class Exception : public std::exception {
public:
    explicit Exception(const std::string& message);
    virtual ~Exception() noexcept; // Добавлен виртуальный деструктор
    const char* what() const noexcept override;

private:
    std::string message_;
};

#endif //SHIP_GAME_EXCEPTION_H
