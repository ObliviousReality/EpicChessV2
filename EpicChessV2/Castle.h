#pragma once
#include "Piece.h"
class Castle :
    public Piece
{
public:
    Castle(int x, int y, bool isWhite);
    ~Castle();
    void Draw(sf::RenderWindow& window);
    void generateMoves(int** tiles);
};

