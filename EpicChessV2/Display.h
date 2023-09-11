#pragma once
#include <SFML/Graphics.hpp>

class Display
{
public:
	Display();
	~Display();

	void start();

	void ResizeView(const sf::RenderWindow& window, sf::View& view);

private:
	sf::RenderWindow window;
	sf::View view;
};

