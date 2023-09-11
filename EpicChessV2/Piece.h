#pragma once
#include <SFML/Graphics.hpp>

class Piece
{
public:
	Piece(int x, int y, int isWhite);
	~Piece();

	void setPosition(int newX, int newY);
	sf::Vector2i getPosition() { return sf::Vector2i(x, y); };

	virtual void Draw(sf::RenderWindow& window);

	virtual void generateMoves(int** tiles);

	void resetMoves();

	int getMoveNumber() { return movePointer; };

	int** getMoves() { return moves; };

	int getType() { return type; };

public:
	sf::Texture t;
	sf::Sprite sprite;
	int x;
	int y;
	int type = -1;
	int thisColour = 2;
	bool isWhite;
	int** moves = new int*[30];
	int movePointer = 0;
};

