// KnightsTour.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

using namespace std;

const int boardSize = 5;
int board[boardSize][boardSize] = { 0 };

bool moveKnight(int row, int col, int moveNum)
{
	if (!((0 <= row <= boardSize) && (0 <= col <= boardSize)))
		return false;
	if (!(board[row][col] == 0))
		return false;
	if (moveNum == (boardSize * boardSize))
	{
		board[row][col] = moveNum;
		return true;
	}
	if (!moveKnight(row - 2, col + 1, moveNum + 1))
	{
		if (!moveKnight(row - 1, col + 2, moveNum + 1))
		{
			if (!moveKnight(row + 1, col + 2, moveNum + 1))
			{
				if (!moveKnight(row + 2, col + 2, moveNum + 1))
				{
					if (!moveKnight(row +2, col -1, moveNum + 1))
					{
						if (!moveKnight(row + 1, col - 2, moveNum + 1))
						{
							if (!moveKnight(row - 1, col - 2, moveNum + 1))
							{
								if (!moveKnight(row - 2, col -1, moveNum + 1))
								{
									return false;
								}
							}
						}
					}
				}
			}
		}
	}
	board[row][col] = moveNum;
	return true;
}

void drawBoard()
{
	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
}

int main()
{
	moveKnight(0, 0, 1);
	cin;
	cin;
}