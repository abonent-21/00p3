#include "Game.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Game game;
    game.run();
    return 0;
}