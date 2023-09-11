#include "Tile.h"
#include <iostream>
#include "Piece.h"

Tile::Tile()
{
	containsPiece = false;
	x = 0;
	y = 0;
}

Tile::~Tile()
{
}

void Tile::Draw(sf::RenderWindow& window)
{
	if (containsPiece)
		piece->Draw(window);
}

void Tile::setPiece(Piece* p)
{
	containsPiece = true;
	piece = p;
}

void Tile::setPosition(int x, int y)
{
	if (containsPiece) {
		piece->setPosition(x, y);
	}
}

void Tile::clearPiece() {
	piece = NULL;
	containsPiece = false;
}

void Tile::generateMoves(int** tiles)
{
	if (containsPiece)
		piece->generateMoves(tiles);
}

int Tile::getMoveNumber()
{
	if (containsPiece)
		return piece->getMoveNumber();
	else
		return 0;
}

int** Tile::getMoves()
{
	if (containsPiece)
		return piece->getMoves();
	else
		return nullptr;
}
