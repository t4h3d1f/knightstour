////
// Author:		Thoomas Allen
// Section:		S
// Assignment:	1
// Description:	Knight's Tour finds a path for a knight chess piece to follow. The path takes place on a
// standard chess board (can be changed to run on a larger or smaller board). The path leads the 
// knight around the board, landing on every square once and only once. When the program 
// finishes running it will display the first path it found that met the criteria, and how many 
// paths the program tried before finding it. 
////

#include "stdafx.h"
#include <iostream>

using namespace std;

const int BOARDSIZE = 8;
int finalTile = 0;
int board[BOARDSIZE][BOARDSIZE] = { 0 };
long long failedAttempts = 0;

//Prints the current board. shows numbers where the knight has been and zeros where it has not. 
//the number shown corrisponds to which turn the knight was on when it landed on that spot.
void drawBoard()
{
	for (int i = 0; i < BOARDSIZE; i++)
	{
		for (int j = 0; j < BOARDSIZE; j++)
		{
			cout << board[i][j] << '\t';
		}
		cout << endl;
	}
}

bool checkMove(int row, int col)
{
	if (!((0 <= row) && (row <= BOARDSIZE - 1) && (0 <= col) && (col <= BOARDSIZE - 1)))
		return false;
	if (!(board[row][col] == 0))
		return false;
	return true;
}

//moveKnight checks if the knight is on the board, 
//and if the space it is on has already been used in the current attempt.
//if the prior checks clear, check if the board has been filled.
//if the board has not been filled in completely, start trying to move the knight to a surrounding tile.
bool moveKnight(int row, int col, int moveNum)
{
	if (moveNum == finalTile)
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
	if (checkMove(row - 2, col + 1))
	{
		if (moveKnight(row - 2, col + 1, moveNum + 1))
			return true;
	}
	if (checkMove(row - 1, col + 2))
	{
		if (moveKnight(row - 1, col + 2, moveNum + 1))
			return true;
	}
	if (checkMove(row + 1, col + 2))
	{
		if (moveKnight(row + 1, col + 2, moveNum + 1))
			return true;
	}
	if (checkMove(row + 2, col + 1))
	{
		if (moveKnight(row + 2, col + 1, moveNum + 1))
			return true;
	}
	if (checkMove(row + 2, col - 1))
	{
		if (moveKnight(row + 2, col - 1, moveNum + 1))
			return true;
	}
	if (checkMove(row + 1, col - 2))
	{
		if (moveKnight(row + 1, col - 2, moveNum + 1))
			return true;
	}
	if (checkMove(row - 1, col - 2))
	{
		if (moveKnight(row - 1, col - 2, moveNum + 1))
			return true;
	}
	if (checkMove(row - 2, col - 1))
	{
		if (moveKnight(row - 2, col - 1, moveNum + 1))
			return true;
	}
	//cant find a place to move the knight to. 
	board[row][col] = 0;
	failedAttempts++;
	return false;
}


//Ask the user where to place the knight on the board. Show the ending board and print out how many tries it took.
int main()
{
	finalTile = BOARDSIZE*BOARDSIZE;
	int row, col = 0;
	cout << "enter starting location\n";
	row, col = 0;
	cin >> row >> col;
	if (!checkMove(row, col))
	{
		cout << "invalid location, the program will now close.\n";
		system("pause");
		return 1;
	}
	else 
	moveKnight(row, col, 1);
	cout << "Solution found!\n";
	drawBoard();
	cout << "There were " << failedAttempts << " failed attempts to find a solution.\n";
	system("pause");
	return 0;
}