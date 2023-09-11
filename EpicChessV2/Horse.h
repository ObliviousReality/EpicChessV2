#pragma once
#include "Piece.h"
class Horse :
    public Piece
{
public:
    Horse(int x, int y, bool isWhite);
    ~Horse();
    void Draw(sf::RenderWindow& window);
    void generateMoves(int** tiles);
};

