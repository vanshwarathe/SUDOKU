#ifndef SUDOKUGENERATOR_HPP
#define SUDOKUGENERATOR_HPP

#include <vector>

class SudokuGenerator {
public:
    SudokuGenerator();
    std::vector<std::vector<int>> generatePuzzle(int emptyCells = 40);

private:
    std::vector<std::vector<int>> board;

    bool fillBoard();
    bool isSafe(int row, int col, int num);
    bool findEmpty(int &row, int &col);
    void removeCells(int count);
};

#endif
