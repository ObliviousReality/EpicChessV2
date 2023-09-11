#pragma once
#include <string>
#include <SFML/Graphics.hpp>
class GameText
{
public:
	GameText(std::string text, int x, int y, bool center);
	~GameText();

	void Draw(sf::RenderWindow& window);

private:
	std::string text;
	int x;
	int y;
	bool centerAligned;
	sf::Text textItem;
	sf::Font font;
};

