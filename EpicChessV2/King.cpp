#include "King.h"
#include <iostream>

King::King(int x, int y, bool isWhite) : Piece(x, y, isWhite)
{
	type = 5;
	if (isWhite)
	{
		t.loadFromFile("assets/white/king.png");
		thisColour = 1;
	}
	else
		t.loadFromFile("assets/black/king.png");
	sprite.setTexture(t);
	sprite.setPosition(40 + x * 100, 80 + y * 100);
}

King::~King()
{
}

void King::Draw(sf::RenderWindow& window)
{
	sprite.setPosition(40 + x * 100, 80 + y * 100);
	window.draw(sprite);
}

void King::generateMoves(int** tiles)
{
	resetMoves();
	//std::cout << opColour << std::endl;
	for (int i = -1; i < 2; i++)
	{
		if (i != 0 && movePointer < 30)
		{
			if (x + i > -1 && x + i < 8)
			{
				if (!(tiles[x + i][y] == thisColour))
				{
					moves[movePointer][0] = x + i;
					moves[movePointer][1] = y;
					movePointer++;
				}
			}
			if (y + i > -1 && y + i < 8)
			{
				if (!(tiles[x][y + i] == thisColour))
				{
					moves[movePointer][0] = x;
					moves[movePointer][1] = y + i;
					movePointer++;
				}
			}
			for (int j = -1; j < 2; j++)
			{
				if (j != 0)
				{
					if (x + i > -1 && x + i<8 && y + j >-1 && y + j < 8)
					{
						if (!(tiles[x + i][y + j] == thisColour))
						{
							moves[movePointer][0] = x + i;
							moves[movePointer][1] = y + j;
							movePointer++;
						}
					}
				}
			}
		}

	}
}
