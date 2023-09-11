#pragma once
#include "Piece.h"
class Queen :
    public Piece
{
public:
    Queen(int x, int y, bool isWhite);
    ~Queen();
    void Draw(sf::RenderWindow& window);
    void generateMoves(int** tiles);
};

