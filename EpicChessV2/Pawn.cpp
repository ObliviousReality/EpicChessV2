#include "Pawn.h"
#include <iostream>

Pawn::Pawn(int x, int y, bool isWhite) : Piece(x, y, isWhite)
{
	type = 0;
	if (isWhite)
	{
		t.loadFromFile("assets/white/pawn.png");
		thisColour = 1;
	}
	else
		t.loadFromFile("assets/black/pawn.png");
	sprite.setTexture(t);
	sprite.setPosition(40 + x * 100, 80 + y * 100);
}

Pawn::~Pawn()
{
}

void Pawn::Draw(sf::RenderWindow& window)
{
	sprite.setPosition(40 + x * 100, 80 + y * 100);
	window.draw(this->sprite);
}

void Pawn::generateMoves(int** tiles)
{
	resetMoves();
	int base = -1;
	int opColour = 1;
	if (isWhite)
	{
		base = 1;
		opColour = 2;
	}
	if (y + base > -1 && y + base < 8) {
		if (!tiles[x][y + base]) {
			moves[movePointer][0] = x;
			moves[movePointer][1] = y + base;
			movePointer++;
			if (y == 1 || y == 6)
			{
				if (!tiles[x][y + (2 * base)])
				{
					moves[movePointer][0] = x;
					moves[movePointer][1] = y + (2 * base);
					movePointer++;
				}
			}
		}
		for (int i = -1; i < 2; i += 2)
		{
			if (x + i > -1 && x + i < 8) {
				if (tiles[x + i][y + base] == opColour)
				{
					moves[movePointer][0] = x + i;
					moves[movePointer][1] = y + base;
					movePointer++;
				}
			}
		}
	}
}