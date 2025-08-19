# 🧩 Sudoku C++ Game

A fully playable **terminal-based Sudoku game** written in modern C++. This project allows players to solve randomly generated Sudoku puzzles interactively, with input validation and an automatic solver.

---

## 🚀 Features

- 🔢 Random Sudoku puzzle generation
- 🎮 Interactive terminal-based gameplay
- ✅ Move validation for legal Sudoku inputs
- 🧠 Built-in solver using backtracking
- 🧱 Modular design with well-separated logic
- 💡 Clean and object-oriented C++ structure

---

## 🗂️ Project Structure

| File/Folder         | Description                              |
|---------------------|------------------------------------------|
| `main.cpp`          | Entry point of the game                  |
| `GameController.*`  | Controls game flow and user interaction  |
| `SudokuBoard.*`     | Maintains and validates the board state  |
| `SudokuGenerator.*` | Generates new Sudoku puzzles             |
| `SudokuSolver.*`    | Solves puzzles using backtracking        |
| `utils.*`           | Utility functions (e.g., randomization)  |

---

## 🛠️ Getting Started

### ✅ Prerequisites

- C++ compiler (g++, clang++, or any that supports C++17 or later)
- Terminal or command-line interface

---

### 🔧 Compile the Game

```bash
g++ main.cpp GameController.cpp SudokuBoard.cpp SudokuGenerator.cpp SudokuSolver.cpp -o sudoku
0 