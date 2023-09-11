#pragma once
#include "Piece.h"
#include <SFML/Graphics.hpp>
class Pawn :
    public Piece
{
public:
    Pawn(int x, int y, bool isWhite);
    ~Pawn();
    void Draw(sf::RenderWindow& window);
    void generateMoves(int** tiles);
};

