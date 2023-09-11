#include "Game.h"
#include <iostream>
#include "Pawn.h"
#include "Bishop.h"
#include "Castle.h"
#include "Horse.h"
#include "Queen.h"
#include "King.h"

Game::Game(int fuckingNumber) : title("Epic Chess 2", 430, 25, true)
{
	for (int i = 0; i < 30; i++)
	{
		markers[i] = sf::RectangleShape(sf::Vector2f(100, 100));
		markers[i].setFillColor(sf::Color(0, 255, 0, 100));
	}
	selectedMarker.setFillColor(sf::Color(255, 255, 0, 50));
	selectedMarker.setOutlineColor(sf::Color(255, 255, 0));
	selectedMarker.setOutlineThickness(-5);
	selectionBox.setFillColor(sf::Color(0, 0, 255, 100));
	selectionBox.setOutlineThickness(-5);
	selectionBox.setOutlineColor(sf::Color(0, 0, 255));
	selectedTile[0] = -1;
	selectedTile[1] = -1;

	t.loadFromFile("assets/background.png");
	background.setTexture(t);
	for (int i = 0; i < 8; i++)
	{
		tileFilled[i] = new int[8];
		tiles[i] = new Tile[8];
		for (int j = 0; j < 8; j++)
		{
			tiles[i][j].setPosition(i, j);
			if (j == 0) {
				if (i == 2 || i == 5) {
					tiles[i][j].setPiece(new Bishop(i, j, 1));
				}
				else if (i == 0 || i == 7) {
					tiles[i][j].setPiece(new Castle(i, j, 1));
				}
				else if (i == 1 || i == 6) {
					tiles[i][j].setPiece(new Horse(i, j, 1));
				}
				else if (i == 3) {
					tiles[i][j].setPiece(new King(i, j, 1));
					whiteKing = tiles[i][j].getPiece();
				}
				else if (i == 4) {
					tiles[i][j].setPiece(new Queen(i, j, 1));
				}
			}
			else if (j == 1) {
				tiles[i][j].setPiece(new Pawn(i, j, 1));
			}
			else if (j == 6) {
				tiles[i][j].setPiece(new Pawn(i, j, 0));
			}
			else if (j == 7) {
				if (i == 2 || i == 5) {
					tiles[i][j].setPiece(new Bishop(i, j, 0));
				}
				else if (i == 0 || i == 7) {
					tiles[i][j].setPiece(new Castle(i, j, 0));
				}
				else if (i == 1 || i == 6) {
					tiles[i][j].setPiece(new Horse(i, j, 0));
				}
				else if (i == 3) {
					tiles[i][j].setPiece(new Queen(i, j, 0));
				}
				else if (i == 4) {
					tiles[i][j].setPiece(new King(i, j, 0));
					blackKing = tiles[i][j].getPiece();
				}
			}
			else {
				tiles[i][j].setPosition(i, j);
			}
		}
	}
	grave->setPosition(-1, -1);

}

Game::~Game()
{
}

void Game::Update(sf::RenderWindow& window)
{
	window.draw(background);
	title.Draw(window);
	sf::RectangleShape board[8][8];

	if (clickDelay)
		clickDelay--;
	if (runCheck)
		runCheckCheck();

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++) {
			board[i][j] = sf::RectangleShape(sf::Vector2f(100, 100));
			board[i][j].setPosition(30 + (i * 100), 70 + (j * 100));
			if ((i + j) % 2 == 0)
			{
				board[i][j].setFillColor(sf::Color(255, 255, 255, 220));
			}
			else
			{
				board[i][j].setFillColor(sf::Color(0, 0, 0, 220));
			}
			window.draw(board[i][j]);
			tiles[i][j].Draw(window);
		}
	}
	sf::Vector2i pos = sf::Mouse::getPosition(window);
	sf::Vector2f realPos = window.mapPixelToCoords(pos);
	if (realPos.x > 30 && realPos.x < 830 && realPos.y>70 && realPos.y < 870)
	{
		int xPos = (int(realPos.x) - 30) / 100 * 100;
		int yPos = (int(realPos.y) - 70) / 100 * 100;
		selectionBox.setPosition(sf::Vector2f(30 + (xPos), 70 + (yPos)));
		window.draw(selectionBox);
		if (!clickDelay)
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				sf::Vector2i clickPos(xPos / 100, yPos / 100);

				if (!tileSelected) {
					if (tiles[clickPos.x][clickPos.y].getContainsPiece() && turn % 2 != tiles[clickPos.x][clickPos.y].getPiece()->isWhite)
					{
						selectedTile[0] = clickPos.x;
						selectedTile[1] = clickPos.y;
						tileSelected = true;
						selectedMarker.setPosition(30 + xPos, 70 + yPos);
						clickDelay = 15;
					}
				}
				else
				{
					if ((turn % 2) + 1 == tileFilled[clickPos.x][clickPos.y])
					{
						tileSelected = false;
					}
					else
					{
						targetSelected = true;
						targetTile[0] = clickPos.x;
						targetTile[1] = clickPos.y;
						clickDelay = 30;
					}
				}

			}
	}
	Tile selectedPiece;
	if (!tileSelected)
	{
		int selectedX = (selectionBox.getPosition().x - 30) / 100;
		int selectedY = (selectionBox.getPosition().y - 70) / 100;
		selectedPiece = tiles[selectedX][selectedY];
	}
	else
	{
		selectedPiece = tiles[selectedTile[0]][selectedTile[1]];
	}
	if (selectedPiece.getContainsPiece() && turn % 2 != selectedPiece.getPiece()->isWhite)
	{
		selectedPiece.generateMoves(tileFilled);
		int** moves = selectedPiece.getMoves();
		int moveCount = selectedPiece.getMoveNumber();
		for (int i = 0; i < moveCount; i++)
		{
			bool toSkip = false;
			if (selectedPiece.getPiece()->isWhite)
			{
				if (moves[i][0] == blackKing->getPosition().x && moves[i][1] == blackKing->getPosition().y)
				{
					moves[i][0] = -10;
					moves[i][1] = -10;
					toSkip = true;
				}
			}
			else {
				if (moves[i][0] == whiteKing->getPosition().x && moves[i][1] == whiteKing->getPosition().y)
				{
					moves[i][0] = -10;
					moves[i][1] = -10;
					toSkip = true;
				}
			}
			if (!toSkip)
			{
				markers[i].setPosition(30 + moves[i][0] * 100, 70 + moves[i][1] * 100);
				if (tileFilled[moves[i][0]][moves[i][1]])
					markers[i].setFillColor(sf::Color(255, 0, 0, 150));
				else
					markers[i].setFillColor(sf::Color(0, 255, 0, 100));
				window.draw(markers[i]);
			}
		}
	}
	if (tileSelected)
	{
		window.draw(selectedMarker);
		if (targetSelected)
		{
			Tile* targetPiece = &tiles[targetTile[0]][targetTile[1]];
			Tile* selectedPiece = &tiles[selectedTile[0]][selectedTile[1]];
			int** moves = selectedPiece->getMoves();
			int moveCount = selectedPiece->getMoveNumber();
			bool toMove = false;
			for (int i = 0; i < moveCount; i++)
			{
				if (moves[i][0] == targetTile[0] && moves[i][1] == targetTile[1])
				{
					toMove = true;
					break;
				}
			}
			if (toMove)
			{
				bool revert = false;
				bool graveFilled = false;
				if (targetPiece->getContainsPiece())
				{
					grave->setPiece(targetPiece->getPiece());
					graveFilled = true;
				}
				selectedPiece->setPosition(targetTile[0], targetTile[1]);
				if (targetPiece->getContainsPiece())
				{
					targetPiece->clearPiece();
				}
				targetPiece->setPiece(selectedPiece->getPiece());
				selectedPiece->clearPiece();
				runCheckCheck();
				if (turn % 2)
				{
					if (blackCheck)
					{
						revert = true;
					}
				}
				else
				{
					if (whiteCheck)
					{
						revert = true;
					}
				}
				if (revert)
				{
					selectedPiece->setPiece(targetPiece->getPiece());
					if (graveFilled)
					{
						targetPiece->setPiece(grave->getPiece());
					}
					else
					{
						targetPiece->clearPiece();
					}
					selectedPiece->setPosition(selectedTile[0], selectedTile[1]);
				}
				else
				{
					turn++;
					runCheck = true;
					if (turn % 2)
					{
						selectionBox.setFillColor(sf::Color(255, 0, 0, 100));
						selectionBox.setOutlineColor(sf::Color(255, 0, 0));
					}
					else
					{
						selectionBox.setFillColor(sf::Color(0, 0, 255, 100));
						selectionBox.setOutlineColor(sf::Color(0, 0, 255));
					}
				}

			}
			tileSelected = false;
			targetSelected = false;
		}
	}
}


void Game::updateFilled()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (tiles[i][j].getContainsPiece())
				if (tiles[i][j].getPiece()->isWhite)
					tileFilled[i][j] = 1;
				else
					tileFilled[i][j] = 2;
			else
				tileFilled[i][j] = 0;
		}
	}
}

void Game::clearSelection()
{
	tileSelected = false;
	targetSelected = false;
}


void Game::runCheckCheck()
{
	updateFilled();
	blackCheck = false;
	whiteCheck = false;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (tiles[i][j].getContainsPiece())
			{
				tiles[i][j].generateMoves(tileFilled);
				Piece* p = tiles[i][j].getPiece();
				int** moves = p->getMoves();
				int moveCount = p->getMoveNumber();
				for (int i = 0; i < moveCount; i++)
				{
					if (p->isWhite)
					{
						if (moves[i][0] == blackKing->getPosition().x && moves[i][1] == blackKing->getPosition().y)
						{
							std::cout << "Black Check" << std::endl;
							blackCheck = true;
						}
					}
					else
					{
						if (moves[i][0] == whiteKing->getPosition().x && moves[i][1] == whiteKing->getPosition().y)
						{
							std::cout << "White Check" << std::endl;
							whiteCheck = true;
						}
					}

				}
			}
		}
	}
	runCheck = false;
}