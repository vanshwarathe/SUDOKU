// SudokuBoard.cpp
#include "SudokuBoard.hpp"
#include <iomanip>

SudokuBoard::SudokuBoard() {
    board = std::vector<std::vector<int>>(9, std::vector<int>(9, 0));
    locked = std::vector<std::vector<bool>>(9, std::vector<bool>(9, false));
}

void SudokuBoard::loadBoard(const std::vector<std::vector<int>>& initial) {
    board = initial;
    locked = std::vector<std::vector<bool>>(9, std::vector<bool>(9, false));

    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            if (initial[i][j] != 0)
                locked[i][j] = true;
}

void SudokuBoard::displayBoard() const {
    std::cout << "\n   ";
    for (int c = 0; c < 9; ++c)
        std::cout << " " << c + 1;
    std::cout << "\n";

    for (int i = 0; i < 9; ++i) {
        if (i % 3 == 0)
            std::cout << "  ---------------------\n";

        std::cout << i + 1 << " |";
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == 0)
                std::cout << " .";
            else
                std::cout << " " << board[i][j];

            if ((j + 1) % 3 == 0)
                std::cout << " |";
        }
        std::cout << "\n";
    }
    std::cout << "  ---------------------\n";
}

bool SudokuBoard::isValidMove(int row, int col, int num) const {
    if (board[row][col] != 0) return false;

    // Row check
    for (int i = 0; i < 9; ++i)
        if (board[row][i] == num)
            return false;

    // Column check
    for (int i = 0; i < 9; ++i)
        if (board[i][col] == num)
            return false;

    // 3x3 grid check
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[startRow + i][startCol + j] == num)
                return false;

    return true;
}

bool SudokuBoard::makeMove(int row, int col, int num) {
    if (locked[row][col]) return false;
    if (!isValidMove(row, col, num)) return false;

    board[row][col] = num;
    return true;
}

bool SudokuBoard::isLocked(int row, int col) const {
    return locked[row][col];
}

bool SudokuBoard::isComplete() const {
    for (const auto& row : board)
        for (int cell : row)
            if (cell == 0)
                return false;
    return true;
}

const std::vector<std::vector<int>>& SudokuBoard::getBoard() const {
    return board;
}
