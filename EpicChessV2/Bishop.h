#pragma once
#include "Piece.h"
class Bishop :
    public Piece
{
public:
    Bishop(int x, int y, bool isWhite);
    ~Bishop();
    void Draw(sf::RenderWindow& window);

    void generateMoves(int** tiles);
};

