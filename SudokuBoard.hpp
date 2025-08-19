#ifndef SUDOKUBOARD_HPP
#define SUDOKUBOARD_HPP

#include<vector>
#include<iostream>

class SudokuBoard{
private:
    std::vector<std::vector<int>> board ;
    std::vector<std::vector<bool>> locked ;

public:
    SudokuBoard();

    void loadBoard(const std::vector<std::vector<int>>& initial);
    void displayBoard() const;
    bool isValidMove(int row, int col, int num) const;
    bool makeMove(int row, int col, int num);
    bool isLocked(int row, int col) const;
    bool isComplete() const;

    const std::vector<std::vector<int>>& getBoard() const ;
};
#endif