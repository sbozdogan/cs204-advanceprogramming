#include "Board.h"
#include <iostream>

using namespace std;

Board::Board()
{
	for(int i=0; i<5; i++)
	{
		for(int j=0; j<4; j++)
		{
			myBoard[i][j] = '-';
		}
	}
}

void Board::DisplayBoard()const
{
	cout << endl;
	for(int i=0; i<5; i++)
	{
		for(int j=0; j<4; j++)
		{
			cout << myBoard[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

bool Board::dropPieceOn(int column, char piece)
{
	if(column >= 0 && column < 4)
	{
		if(myBoard[4][column] != '-')
		{
			if(myBoard[3][column] != '-')
			{
				if(myBoard[2][column] != '-')
				{
					if(myBoard[1][column] != '-')
					{
						if(myBoard[0][column] != '-')
						{
							return false;
						}
						else
						{
							myBoard[0][column]= piece;
							return true;
						}
					}
					else
					{
						myBoard[1][column]= piece;
						return true;
					}
				}
				else
				{
					myBoard[2][column]= piece;
					return true;
				}
			}
			else
			{
				myBoard[3][column]= piece;
				return true;
			}
		}
		else
		{
			myBoard[4][column] = piece;
			return true;
		}



	}
	else
	{
		return false;
	}

}

bool Board::isFull()const
{
	int countFullCells = 0;
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<5; j++)
		{
			if(myBoard[i][j]== '-')
			{
				return false;
			}
		}
	}
	return true;
}

bool Board::isConnect3(char checkPiece)
{
	if(myBoard[0][0]==checkPiece)
	{
		if(myBoard[0][1]==checkPiece)
		{
			if(myBoard[0][2]==checkPiece)
			{
				return true;
			}
		}
		if(myBoard[1][1]==checkPiece)
		{
			if(myBoard[2][2]==checkPiece)
			{
				return true;
			}
		}
		if(myBoard[1][0]==checkPiece)
		{
			if(myBoard[2][0]==checkPiece)
			{
				return true;
			}
		}
	}
	if(myBoard[0][1]==checkPiece)
	{
		if(myBoard[0][2]==checkPiece)
		{
			if(myBoard[0][3]==checkPiece)
			{
				return true;
			}
		}
		if(myBoard[1][2]==checkPiece)
		{
			if(myBoard[2][3]==checkPiece)
			{
				return true;
			}
		}
		if(myBoard[1][1]==checkPiece)
		{
			if(myBoard[2][1]==checkPiece)
			{
				return true;
			}
		}
	}
	if(myBoard[0][2]==checkPiece)
	{
		if(myBoard[1][1]==checkPiece)
		{
			if(myBoard[2][0]==checkPiece)
			{
				return true;
			}
		}
		if(myBoard[1][2]==checkPiece)
		{
			if(myBoard[2][2]==checkPiece)
			{
				return true;
			}
		}
	}
	if(myBoard[0][3]==checkPiece)
	{
		if(myBoard[1][2]==checkPiece)
		{
			if(myBoard[2][1]==checkPiece)
			{
				return true;
			}
		}
		if(myBoard[1][3]==checkPiece)
		{
			if(myBoard[2][3]==checkPiece)
			{
				return true;
			}
		}
	}
	if(myBoard[1][0]==checkPiece)
	{
		if(myBoard[1][1]==checkPiece)
		{
			if(myBoard[1][2]==checkPiece)
			{
				return true;
			}
		}
		if(myBoard[2][1]==checkPiece)
		{
			if(myBoard[3][2]==checkPiece)
			{
				return true;
			}
		}
		if(myBoard[2][0]==checkPiece)
		{
			if(myBoard[3][0]==checkPiece)
			{
				return true;
			}
		}
	}
	if(myBoard[1][1]==checkPiece)
	{
		if(myBoard[1][2]==checkPiece)
		{
			if(myBoard[1][3]==checkPiece)
			{
				return true;
			}
		}
		if(myBoard[2][2]==checkPiece)
		{
			if(myBoard[3][3]==checkPiece)
			{
				return true;
			}
		}
		if(myBoard[2][1]==checkPiece)
		{
			if(myBoard[3][1]==checkPiece)
			{
				return true;
			}
		}
	}
	if(myBoard[1][2]==checkPiece)
	{
		if(myBoard[2][1]==checkPiece)
		{
			if(myBoard[3][0]==checkPiece)
			{
				return true;
			}
		}
		if(myBoard[2][2]==checkPiece)
		{
			if(myBoard[3][2]==checkPiece)
			{
				return true;
			}
		}
	}
	if(myBoard[1][3]==checkPiece)
	{
		if(myBoard[2][2]==checkPiece)
		{
			if(myBoard[3][1]==checkPiece)
			{
				return true;
			}
		}
		if(myBoard[2][3]==checkPiece)
		{
			if(myBoard[3][3]==checkPiece)
			{
				return true;
			}
		}
	}
	if(myBoard[2][0]==checkPiece)
	{
		if(myBoard[2][1]==checkPiece)
		{
			if(myBoard[2][2]==checkPiece)
			{
				return true;
			}
		}
		if(myBoard[3][1]==checkPiece)
		{
			if(myBoard[4][2]==checkPiece)
			{
				return true;
			}
		}
		if(myBoard[3][0]==checkPiece)
		{
			if(myBoard[4][0]==checkPiece)
			{
				return true;
			}
		}
	}
	if(myBoard[2][1]==checkPiece)
	{
		if(myBoard[2][2]==checkPiece)
		{
			if(myBoard[2][3]==checkPiece)
			{
				return true;
			}
		}
		if(myBoard[3][2]==checkPiece)
		{
			if(myBoard[4][3]==checkPiece)
			{
				return true;
			}
		}
		if(myBoard[3][1]==checkPiece)
		{
			if(myBoard[4][1]==checkPiece)
			{
				return true;
			}
		}
	}
	if(myBoard[2][2]==checkPiece)
	{
		if(myBoard[3][1]==checkPiece)
		{
			if(myBoard[4][0]==checkPiece)
			{
				return true;
			}
		}
		if(myBoard[3][2]==checkPiece)
		{
			if(myBoard[4][2]==checkPiece)
			{
				return true;
			}
		}
	}
	if(myBoard[2][3]==checkPiece)
	{
		if(myBoard[3][2]==checkPiece)
		{
			if(myBoard[4][1]==checkPiece)
			{
				return true;
			}
		}
		if(myBoard[3][3]==checkPiece)
		{
			if(myBoard[4][3]==checkPiece)
			{
				return true;
			}
		}
	}
	if(myBoard[3][0]==checkPiece)
	{
		if(myBoard[3][1]==checkPiece)
		{
			if(myBoard[3][2]==checkPiece)
			{
				return true;
			}
		}
	}
	if(myBoard[3][1]==checkPiece)
	{
		if(myBoard[3][2]==checkPiece)
		{
			if(myBoard[3][3]==checkPiece)
			{
				return true;
			}
		}
	}
	if(myBoard[4][0]==checkPiece)
	{
		if(myBoard[3][1]==checkPiece)
		{
			if(myBoard[2][2]==checkPiece)
			{
				return true;
			}
		}
		if(myBoard[4][1]==checkPiece)
		{
			if(myBoard[4][2]==checkPiece)
			{
				return true;
			}
		}
	}
	if(myBoard[4][1]==checkPiece)
	{
		if(myBoard[4][2]==checkPiece)
		{
			if(myBoard[4][3]==checkPiece)
			{
				return true;
			}
		}
	}

	return false;
}



