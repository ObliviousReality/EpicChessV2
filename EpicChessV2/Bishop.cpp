#include "Bishop.h"

Bishop::Bishop(int x, int y, bool isWhite) : Piece(x, y, isWhite)
{
	type = 3;
	if (isWhite)
	{
		t.loadFromFile("assets/white/bishop.png");
		thisColour = 1;
	}
	else
		t.loadFromFile("assets/black/bishop.png");
	sprite.setTexture(t);
	sprite.setPosition(40 + x * 100, 80 + y * 100);
}

Bishop::~Bishop()
{
}

void Bishop::Draw(sf::RenderWindow& window)
{
	sprite.setPosition(40 + x * 100, 80 + y * 100);
	window.draw(sprite);
}

void Bishop::generateMoves(int** tiles)
{
	resetMoves();
	bool ul = true;
	bool dl = true;
	bool dr = true;
	bool ur = true;
	for (int i = 1; i < 8; i++)
	{
		if (x + i < 8 && y + i < 8 && dr)
		{
			if (!tiles[x + i][y + i])
			{
				moves[movePointer][0] = x + i;
				moves[movePointer][1] = y + i;
				movePointer++;
			} 
			else if (tiles[x + i][y + i] != thisColour)
			{
				moves[movePointer][0] = x + i;
				moves[movePointer][1] = y + i;
				movePointer++;
				dr = false;
			}
			else
				dr = false;
		}
		if (x + i < 8 && y - i > -1 && ur)
		{
			if (!tiles[x + i][y - i])
			{
				moves[movePointer][0] = x + i;
				moves[movePointer][1] = y - i;
				movePointer++;
			}
			else if (tiles[x + i][y - i] != thisColour)
			{
				moves[movePointer][0] = x + i;
				moves[movePointer][1] = y - i;
				movePointer++;
				ur = false;
			}
			else
				ur = false;
		}
		if (x - i > -1 && y - i > -1 && ul)
		{
			if (!tiles[x - i][y - i])
			{
				moves[movePointer][0] = x - i;
				moves[movePointer][1] = y - i;
				movePointer++;
			}
			else if (tiles[x - i][y - i] != thisColour)
			{
				moves[movePointer][0] = x - i;
				moves[movePointer][1] = y - i;
				movePointer++;
				ul = false;
			}
			else
				ul = false;
		}
		if (x - i > -1 && y + i < 8 && dl)
		{
			if (!tiles[x - i][y + i])
			{
				moves[movePointer][0] = x - i;
				moves[movePointer][1] = y + i;
				movePointer++;
			}
			else if (tiles[x - i][y + i] != thisColour)
			{
				moves[movePointer][0] = x - i;
				moves[movePointer][1] = y + i;
				movePointer++;
				dl = false;
			}
			else
				dl = false;
		}
		if (!dl && !ul && !ur && !dr)
			break;
	}
}
