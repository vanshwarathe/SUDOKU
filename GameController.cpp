#include "GameController.hpp"
#include <iostream>

GameController::GameController() {}

void GameController::startGame(int difficulty) {
    auto puzzle = generator.generatePuzzle(difficulty);
    board.loadBoard(puzzle);
    gameLoop();
}

void GameController::gameLoop() {
    while (!board.isComplete()) {
        board.displayBoard();

        int row, col, num;
        std::cout << "\nEnter your move (row [1-9] col [1-9] num [1-9]) or 0 0 0 to quit: ";
        std::cin >> row >> col >> num;

        if (row == 0 && col == 0 && num == 0) {
            std::cout << "Game exited.\n";
            return;
        }

        row--; col--;  // convert to 0-indexed

        if (row < 0 || row >= 9 || col < 0 || col >= 9 || num < 1 || num > 9) {
            std::cout << "Invalid input. Please try again.\n";
            continue;
        }

        if (board.isLocked(row, col)) {
            std::cout << "Cell is locked. Try a different one.\n";
            continue;
        }

        if (!board.isValidMove(row, col, num)) {
            std::cout << "Invalid move. Number conflicts with row/column/box.\n";
            continue;
        }

        board.makeMove(row, col, num);
    }

    std::cout << "\n🎉 Congratulations! You completed the Sudoku!\n";
    board.displayBoard();
}
