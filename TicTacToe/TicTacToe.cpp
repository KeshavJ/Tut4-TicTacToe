#include "TicTacToe.h"
#include <iostream>

TicTacToe::TicTacToe()
{
	for (int i = 0; i < 3; i++)
		 	for (int j = 0; j < 3; j++)
		 		grid[i][j] = ' ';

}

void TicTacToe::reset(){
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			grid[i][j] = ' ';
};

bool TicTacToe::move(int rows, int col, int player)
{
	bool check = 0;  //flag for illegal moves 
	                    
	if (((rows < 3) && (col < 3)) && (grid[rows][col] == ' ')) {
		check = 1;
		if(player == 1) {
			grid[rows][col] = 'X';   
		}
		else { grid[rows][col] = 'O'; }  
	}
	return check;
};

void TicTacToe::print()
{
	cout << "--------------------" << endl;
	for (int x = 0; x < 3; x++)
	{
		cout << "	" << grid[x][0] << "|" << grid[x][1] << "|" << grid[x][2] << endl;
	}
	cout << "--------------------" << endl << endl;

};

int TicTacToe::over()
{
	int player1 = 0;
	int player2 = 0; 
	int checkProgress = 0; 

	//check the rows 
	for (int i = 0; i < 3; i++)
	{
		player1 = 0;
		player2 = 0;

		for (int j = 0; j < 3; j++)
		{
			if (grid[i][j] == 'X') { 
				player1++; 
			}
			if (grid[i][j] == 'O') {
				player2++; 
			}
			if (grid[i][j] == ' ') {
				checkProgress = 1; 
			}
		}
		
		if (player1 == 3) { 
			return 1;
		}

		if (player2 == 3) {
			return 2; 
		} 
	}
	
	//Check the columns 
	for (int j = 0; j < 3; j++)
	{
		player1 = 0;
		player2 = 0;

		for (int i = 0; i < 3; i++)
		{
			if (grid[i][j] == 'X') {
				player1++;
			}
			if (grid[i][j] == ')') {
				player2++;
			}
			if (grid[i][j] == ' ') {
				checkProgress = 1;
			}
		}
		if (player1 == 3) {
			return 1;
		}
		if (player2 == 3) {
			return 2;
		}
	}
	
	//Check the First Diagonal Line 
	player1 = 0;
	player2 = 0;  //Reset control signals 
	for (int i = 0; i < 3; i++)
	{
		if (grid[i][i] == 'X') {
			player1++;
		}
		if (grid[i][i] == '0') { 
			player2++; 
		}
		if (grid[i][i] == '-') {
			checkProgress = 1; 
		}
		
		if (player1 == 3) { 
			return 1;
		}  
		if (player2 == 3) { 
			return 2;
		} 
	}
	
	//Check the Second diagonal line 
	player1 = 0;
	player2 = 0;  
	int row = 0;
	
	for (int j = 2; j >= 0; j--)
	{
		if (grid[row][j] == 'X') { 
			player1++; 
		}
		if (grid[row][j] == 'O') {
			player2++; 
		}
		if (grid[row][j] == '-') { 
			checkProgress = 1;
		}
		row++;
		
		if (player1 == 3) { 
			return 1; 
		}
		if (player2 == 3) {
			return 2; 
		}
	}

	//Checking for draws 
	if ((player1 == 3) && (player2 == 3))
	{
		return 3;
	}

	if (checkProgress == 1)
	{
		return 4;
	}
	else
		return 0;
};

TicTacToe::~TicTacToe()
{
}
