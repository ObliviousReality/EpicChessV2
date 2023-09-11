#include "Horse.h"

Horse::Horse(int x, int y, bool isWhite) : Piece(x, y, isWhite)
{
	type = 1;
	if (isWhite)
	{
		t.loadFromFile("assets/white/horse.png");
		thisColour = 1;
	}
	else
		t.loadFromFile("assets/black/horse.png");
	sprite.setTexture(t);
	sprite.setPosition(40 + x * 100, 80 + y * 100);
}

Horse::~Horse()
{
}

void Horse::Draw(sf::RenderWindow& window)
{
	sprite.setPosition(40 + x * 100, 80 + y * 100);
	window.draw(sprite);
}

void Horse::generateMoves(int** tiles)
{
	resetMoves();

	int xOff = -2;
	int yOff = 0;
	for (int i = 0; i < 4; i++)
	{
		switch (i)
		{
		case 1: // Up
			xOff = 0;
			yOff = -2;
			break;
		case 2: // Right
			xOff = 2;
			yOff = 0;
			break;
		case 3: // Down
			xOff = 0;
			yOff = 2;
			break;
		}
		if (xOff)
			for (yOff = -1; yOff < 2; yOff++)
			{
				if (yOff != 0 && x + xOff > -1 && x + xOff<8 && y + yOff>-1 && y + yOff < 8)
				{
					if (tiles[x + xOff][y + yOff] != thisColour) {
						moves[movePointer][0] = x + xOff;
						moves[movePointer][1] = y + yOff;
						movePointer++;
					}
				}
			}
		else
			for (xOff = -1; xOff < 2; xOff++)
			{
				if (xOff != 0 && x + xOff > -1 && x + xOff<8 && y + yOff>-1 && y + yOff < 8)
				{
					if (tiles[x + xOff][y + yOff] != thisColour)
					{
						moves[movePointer][0] = x + xOff;
						moves[movePointer][1] = y + yOff;
						movePointer++;
					}
				}
			}
	}
}
