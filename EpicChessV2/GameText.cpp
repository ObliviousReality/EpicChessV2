#include "GameText.h"

GameText::GameText(std::string text, int x, int y, bool center)
{
	this->text = text;
	this->x = x;
	this->y = y;
	this->centerAligned = center;
	textItem.setString(text);
	font.loadFromFile("assets/font.ttf");
	textItem.setFont(font);
	textItem.setFillColor(sf::Color(255, 255, 0));
	textItem.setCharacterSize(60);
	if (centerAligned)
	{
		textItem.setPosition(x - textItem.getLocalBounds().width / 2, y - textItem.getLocalBounds().height / 2);
	}
	else
	{
		textItem.setPosition(x, y);
	}
}

GameText::~GameText()
{
}

void GameText::Draw(sf::RenderWindow& window)
{
	window.draw(textItem);
}
