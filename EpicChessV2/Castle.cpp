#include "Castle.h"
#include <iostream>

Castle::Castle(int x, int y, bool isWhite) : Piece(x, y, isWhite)
{
	type = 2;
	if (isWhite)
	{
		t.loadFromFile("assets/white/castle.png");
		thisColour = 1;
	}
	else
		t.loadFromFile("assets/black/castle.png");
	sprite.setTexture(t);
	sprite.setPosition(40 + x * 100, 80 + y * 100);
}

Castle::~Castle()
{
}

void Castle::Draw(sf::RenderWindow& window)
{
	sprite.setPosition(40 + x * 100, 80 + y * 100);
	window.draw(sprite);
}

void Castle::generateMoves(int** tiles)
{
	bool left = true;
	bool right = true;
	bool up = true;
	bool down = true;
	resetMoves();
	for (int i = 1; i < 8; i++) {
		if (x + i < 8 && right)
		{
			if (!tiles[x + i][y])
			{
				moves[movePointer][0] = x + i;
				moves[movePointer][1] = y;
				movePointer++;
			}
			else if (tiles[x + i][y] != thisColour)
			{
				moves[movePointer][0] = x + i;
				moves[movePointer][1] = y;
				movePointer++;
				right = false;
			}
			else
				right = false;
		}
		if (x - i >= 0 && left)
		{
			if (!tiles[x - i][y])
			{
				moves[movePointer][0] = x - i;
				moves[movePointer][1] = y;
				movePointer++;
			}
			else if (tiles[x - i][y] != thisColour)
			{
				moves[movePointer][0] = x - i;
				moves[movePointer][1] = y;
				movePointer++;
				left = false;
			}
			else
				left = false;
		}
		if (y + i < 8 && down)
		{
			if (!tiles[x][y + i])
			{
				moves[movePointer][0] = x;
				moves[movePointer][1] = y + i;
				movePointer++;
			}
			else if (tiles[x][y + i] != thisColour)
			{
				moves[movePointer][0] = x;
				moves[movePointer][1] = y + i;
				movePointer++;
				down = false;
			}
			else
				down = false;
		}
		if (y - i >= 0 && up)
		{
			if (!tiles[x][y - i])
			{
				moves[movePointer][0] = x;
				moves[movePointer][1] = y - i;
				movePointer++;
			}
			else if (tiles[x][y - i] != thisColour)
			{
				moves[movePointer][0] = x;
				moves[movePointer][1] = y - i;
				movePointer++;
				up = false;
			}
			else
				up = false;
		}
		if (!left && !right && !up && !down)
			break;
	}
}
