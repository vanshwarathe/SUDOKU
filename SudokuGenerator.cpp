#include "SudokuGenerator.hpp"
#include <algorithm>
#include <random>
#include <ctime>

// Constructor initializes empty 9x9 board
SudokuGenerator::SudokuGenerator() {
    board = std::vector<std::vector<int>>(9, std::vector<int>(9, 0));
}

// Public function to generate puzzle
std::vector<std::vector<int>> SudokuGenerator::generatePuzzle(int emptyCells) {
    fillBoard();              // Step 1: Fill full valid board
    removeCells(emptyCells);  // Step 2: Remove cells to make puzzle
    return board;
}

// Backtracking solver to fill board
bool SudokuGenerator::fillBoard() {
    int row, col;

    if (!findEmpty(row, col))
        return true;  // Done

    std::vector<int> nums = {1,2,3,4,5,6,7,8,9};

    // Shuffle to make board different every time
    std::shuffle(nums.begin(), nums.end(), std::default_random_engine(static_cast<unsigned>(time(0))));

    for (int num : nums) {
        if (isSafe(row, col, num)) {
            board[row][col] = num;
            if (fillBoard())
                return true;
            board[row][col] = 0;  // Backtrack
        }
    }

    return false;  // Trigger backtracking
}

// Check if a number can be placed safely
bool SudokuGenerator::isSafe(int row, int col, int num) {
    for (int i = 0; i < 9; ++i) {
        if (board[row][i] == num || board[i][col] == num)
            return false;
    }

    int boxRow = row - row % 3;
    int boxCol = col - col % 3;

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[boxRow + i][boxCol + j] == num)
                return false;

    return true;
}

// Finds the next empty cell
bool SudokuGenerator::findEmpty(int &row, int &col) {
    for (row = 0; row < 9; ++row)
        for (col = 0; col < 9; ++col)
            if (board[row][col] == 0)
                return true;
    return false;
}

// Randomly removes `count` numbers from the filled board
void SudokuGenerator::removeCells(int count) {
    std::srand(static_cast<unsigned>(std::time(0)));

    while (count > 0) {
        int row = std::rand() % 9;
        int col = std::rand() % 9;

        if (board[row][col] != 0) {
            board[row][col] = 0;
            --count;
        }
    }
}
