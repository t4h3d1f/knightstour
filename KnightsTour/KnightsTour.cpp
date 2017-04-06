// KnightsTour.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;

const int boardSize = 8;
int board[boardSize][boardSize] = { 0 };
long long failedAttempts = 0;

void drawBoard()
{
	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			cout << board[i][j] << '\t';
		}
		cout << endl;
	}
}
//moveKnight checks if the knight is on the board, and if the space is has been used in the current attempt.
//if the prior checks clear, check if the board has been filled.
//if the board has not been filled
bool moveKnight(int row, int col, int moveNum)
{
	if (!((0 <= row) && (row <= boardSize-1) && (0 <= col)&&(col <= boardSize-1)))
		return false;
	if (!(board[row][col] == 0))
		return false;
	if (moveNum == (boardSize * boardSize))
	{
		board[row][col] = moveNum;
		return true;
	}
	if (failedAttempts % 10000000 == 0)
	{
	drawBoard();
	failedAttempts++; //add one for every ten million failed attempt, since the program 
					//only evaluates a failed attempt once it has run out of moves. 
	cout << endl; //this would cause the board to be printed multiple times otherwise
	}
	board[row][col] = moveNum;
	if (!moveKnight(row - 2, col + 1, moveNum + 1))
	{
		if (!moveKnight(row - 1, col + 2, moveNum + 1))
		{
			if (!moveKnight(row + 1, col + 2, moveNum + 1))
			{
				if (!moveKnight(row + 2, col + 1, moveNum + 1))
				{
					if (!moveKnight(row +2, col -1, moveNum + 1))
					{
						if (!moveKnight(row + 1, col - 2, moveNum + 1))
						{
							if (!moveKnight(row - 1, col - 2, moveNum + 1))
							{
								if (!moveKnight(row - 2, col -1, moveNum + 1))
								{
									board[row][col] = 0;
									failedAttempts++;
									return false;
								}
							}
						}
					}
				}
			}
		}
	}
	return true;
}



int main()
{
	cout << "enter starting location\n";
	int row, col;
	cin >> row >> col;
	moveKnight(row, col, 1);
	cout << "Solution found!\n";
	drawBoard();
	cout << "There were " << failedAttempts << " failed attempts to find a solution.\n";
	system("pause");
}