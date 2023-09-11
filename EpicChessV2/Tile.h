#pragma once
#include <SFML/Graphics.hpp>
#include "Piece.h"
class Tile
{
public:
	Tile();
	~Tile();

	virtual void Draw(sf::RenderWindow& window);

	void setPiece(Piece* p);

	void setPosition(int x, int y);

	bool getContainsPiece() { return containsPiece; };

	void clearPiece();

	Piece* getPiece() { return piece; };

	virtual void generateMoves(int** tiles);

	virtual int getMoveNumber();

	virtual int** getMoves();

	int getType() { return piece->getType(); };

protected:
	int x;
	int y;
	Piece* piece;
	sf::Sprite sprite;
	bool containsPiece;
	
};

