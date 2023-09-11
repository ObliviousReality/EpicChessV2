#include "Piece.h"
#include <iostream>

Piece::Piece(int x, int y, int isWhite) : t()
{
	this->isWhite = isWhite;
	this->x = x;
	this->y = y;
	for (int i = 0; i < 30; i++) {
		moves[i] = new int[2];
	}
}

Piece::~Piece()
{
}

void Piece::setPosition(int newX, int newY)
{
	x = newX;
	y = newY;
}

void Piece::Draw(sf::RenderWindow& window)
{
	std::cout << "This shouldn't be used" << std::endl;
	window.draw(sprite);
}

void Piece::generateMoves(int** tiles)
{
	std::cout << "This also shouldn't be used" << std::endl;
}

void Piece::resetMoves()
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			moves[i][j] = 0;
		}
	}
	movePointer = 0;
}


