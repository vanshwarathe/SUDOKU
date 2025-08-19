#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP

#include "SudokuBoard.hpp"
#include "SudokuGenerator.hpp"

class GameController {
private:
    SudokuBoard board;
    SudokuGenerator generator;

public:
    GameController();

    void startGame(int difficulty = 40);
    void gameLoop();  // handles user interaction
};

#endif
