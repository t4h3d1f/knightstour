// KnightsTour.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

using namespace std;

const int boardSize = 9;
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
	cout << endl;
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
									//drawBoard();
									//cout << endl;
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

////
//use increments of pi/8
//round(sqrt(5)cos(theta)) for col
//round(sqrt(5)sin(theta)) for row
////

int main()
{
	moveKnight(0, 0, 1);
	cout << "Solution found!\n";
	drawBoard();
	cout << "There were " << failedAttempts << " failed attempts to find a solution.\n";
	cin.get();
//	cin.get();
}