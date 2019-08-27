#pragma once
#include<vector>

class SudokuSolver
{
public:
	using Sudoku = std::vector<std::vector<char>>;
	SudokuSolver();
	~SudokuSolver();
	bool checkRow(Sudoku& m, int i, int j, char val);
	bool checkColumn(Sudoku& m, int i, int j, char val);
	bool checkGrid(Sudoku& m, int i, int j, char val);
	bool solveSudoku(Sudoku& board, int i, int j);
	void solveSudoku(std::vector<std::vector<char>>& board);
	void displayBoard(std::vector<std::vector<char>>& board);
};

