#pragma once
#include "Piece.h"
class King :
    public Piece
{
public:
    King(int x, int y, bool isWhite);
    ~King();
    void Draw(sf::RenderWindow& window);

    void generateMoves(int** tiles);
};

