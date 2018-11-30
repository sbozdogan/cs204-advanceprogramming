#ifndef BOARD_H
#define BOARD_H

#include<string>
using namespace std;

class Board
{
	public:
		Board();
		void DisplayBoard()const;
		bool dropPieceOn(int col, char piece);
		bool isFull()const;
		bool isConnect3(char checkPiece);
	private:
		char myBoard[5][4];
};

#endif