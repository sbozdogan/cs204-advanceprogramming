#include "Player.h"
#include "Board.h"
#include<iostream>
#include<string>

using namespace std;

bool Player::play(int col)
{
	return board.dropPieceOn(col, playerPiece);
}

bool Player::isWinner()
{
	return board.isConnect3(this->playerPiece);
}


