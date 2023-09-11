#include "Queen.h"

Queen::Queen(int x, int y, bool isWhite) : Piece(x, y, isWhite)
{
	type = 4;
	if (isWhite)
	{
		t.loadFromFile("assets/white/queen.png");
		thisColour = 1;
	}
	else
		t.loadFromFile("assets/black/queen.png");
	sprite.setTexture(t);
	sprite.setPosition(40 + x * 100, 80 + y * 100);
}

Queen::~Queen()
{
}

void Queen::Draw(sf::RenderWindow& window)
{
	sprite.setPosition(40 + x * 100, 80 + y * 100);
	window.draw(sprite);
}

void Queen::generateMoves(int** tiles)
{
	resetMoves();
	bool ul = true;
	bool dl = true;
	bool dr = true;
	bool ur = true;
	bool left = true;
	bool right = true;
	bool up = true;
	bool down = true;
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
		if (!dl && !ul && !ur && !dr && !left && !right && !up && !down)
			break;
	}

}

