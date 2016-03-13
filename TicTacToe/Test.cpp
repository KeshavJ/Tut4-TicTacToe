#include <iostream> 
#include <string>
#include "TicTacToe.h"

using namespace std;

int main() {
	
	int playerNum = 1; 
	int row = 0, col = 0; 
	
	TicTacToe game;  

		for (int i = 0; i < 9; i++)
		{
			cout << "Choose space according to grid layout to enter your move" << endl;
			cout << "Grid Layout: " << endl;
			cout << "00 01 02" << endl;
			cout << "10 11 12" << endl;
			cout << "20 21 22" << endl;
			
			cout << "Enter row" << endl;
			cin >> row;

			cout << "Enter column" << endl;
			cin >> col;

			cout << "Enter your Player number. Player 1 uses X's and Player 2 uses O's " << endl;
			cin >> playerNum;

			if (game.move(row, col, playerNum))
			{
				game.print();
				game.over();

				if ((game.over() == 1))
				{
					cout << "Player 1 wins!! " << endl;
					game.reset();
					i = 0; //Reset Game Counter 
				}

				else if ((game.over() == 2))
				{
					cout << "Player 2 Wins!! " << endl;
					game.reset();
					i = 0;
				}

				else if ((game.over() == 3))
				{
					cout << "Draw Match!! " << endl;
					game.reset();
					i = 0;
				}
				else if ((game.over() == 4))
				{
					cout << "Game still in progress " << endl;
				}
				else
				{
					cout << "Game Ended" << endl;
				}
			}

			else
			{
				cout << "Invalid Input. Please try again " << endl;
				i--;  
			}
		}

	return 0;
}
