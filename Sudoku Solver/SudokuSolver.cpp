#include "SudokuSolver.h"
#include <iostream>

SudokuSolver::SudokuSolver()
{
}


SudokuSolver::~SudokuSolver()
{
}
bool SudokuSolver::checkRow(Sudoku& m, int i, int j, char val)
{
	for (int col = 0; col < m[i].size(); col++)
	{
		if (col == j)
			continue;
		if (m[i][col] == val)
			return false;
	}
	return true;
}
bool SudokuSolver::checkColumn(Sudoku& m, int i, int j, char val)
{
	for (int row = 0; row < m.size(); row++)
	{
		if (row == i)
			continue;
		if (m[row][j] == val)
			return false;
	}
	return true;
}
bool SudokuSolver::checkGrid(Sudoku& m, int i, int j, char val)
{
	int col = (j / 3);
	int row = (i / 3);
	for (int a = 0; a < 3; a++)
	{
		for (int b = 0; b < 3; b++)
		{
			if (a == i && b == j)
				continue;
			if (m[a + 3 * row][b + 3 * col] == val)
				return false;
		}
	}
	return true;
}

bool SudokuSolver::solveSudoku(Sudoku& board, int i, int j)
{
	if (j == board[i].size())
	{
		i++;
		j = 0;
	}
	if (i == board.size())
		return true;
	if (board[i][j] != '.')
		return solveSudoku(board, i, j + 1);
	for (int val = 1; val <= 9; val++)
	{
		char valChar = val + '0';
		if (checkRow(board, i, j, valChar) && checkColumn(board, i, j, valChar) && checkGrid(board, i, j, valChar))
		{
			board[i][j] = val + '0';
			if (solveSudoku(board, i, j + 1))
				return true;
		}
	}
	board[i][j] = '.';
	return false;
}


void SudokuSolver::solveSudoku(std::vector<std::vector<char>>& board)
{
	solveSudoku(board, 0, 0);
}

void SudokuSolver::displayBoard(std::vector<std::vector<char>>& board)
{
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			std::cout << board[i][j] << "\t";
		}
		std::cout << "\n";
	}
}

int main() {
	std::vector<std::vector<char>> board = { {'5', '3', '.', '.', '7', '.', '.', '.', '.'},{'6', '.', '.', '1', '9', '5', '.', '.', '.'},{'.', '9', '8', '.', '.', '.', '.', '6', '.'},{'8', '.', '.', '.', '6', '.', '.', '.', '3'},{'4', '.', '.', '8', '.', '3', '.', '.', '1'},{'7', '.', '.', '.', '2', '.', '.', '.', '6'},{'.', '6', '.', '.', '.', '.', '2', '8', '.'},{'.', '.', '.', '4', '1', '9', '.', '.', '5'},{'.', '.', '.', '.', '8', '.', '.', '7', '9'} };
	SudokuSolver solver;
	solver.solveSudoku(board);
	solver.displayBoard(board);

	getchar();
	return 0;

}