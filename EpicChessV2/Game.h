#pragma once
#include "Display.h"
#include "GameText.h"
#include "Tile.h"
#include "Pawn.h"
class Game
{
public:
	Game(int fuckingNumber);
	~Game();

	void Update(sf::RenderWindow& window);

	void updateFilled();

	void clearSelection();

	void runCheckCheck();

private:
	GameText title;
	sf::RectangleShape* markers = new sf::RectangleShape[30];
	sf::RectangleShape selectedMarker = sf::RectangleShape(sf::Vector2f(100, 100));
	sf::RectangleShape selectionBox = sf::RectangleShape(sf::Vector2f(100, 100));;

	Tile** tiles = new Tile * [8];

	Piece* whiteKing;
	Piece* blackKing;

	Tile* grave = new Tile();

	int** tileFilled = new int* [8];

	int* selectedTile = new int[2];
	int* targetTile = new int[2];
	bool tileSelected = false;
	bool targetSelected = false;

	int clickDelay = 30;

	sf::Sprite background;

	sf::Texture t;

	int turn = 0;

	bool runCheck = true;

	bool whiteCheck = false;
	bool blackCheck = false;
};

