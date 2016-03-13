#pragma once
#include<string>

using namespace std;

class TicTacToe
{
private:
	char grid[3][3];

public:
	TicTacToe();
	~TicTacToe();

	void reset();
	bool move(int, int, int);
	void print();
	int over();

};

