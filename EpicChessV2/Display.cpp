#include "Display.h"
#include "Game.h"

Display::Display() : window(sf::VideoMode(860, 900), "EpicChessV2", sf::Style::Default), view(sf::Vector2f(0, 0), sf::Vector2f(860, 900))
{
	window.setVerticalSyncEnabled(true);
	view.setCenter(860 / 2, 900 / 2);
}

Display::~Display()
{
}

void Display::start()
{
	Game game = Game(10);
	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (evnt.key.code == sf::Keyboard::Key::P || evnt.key.code == sf::Keyboard::Key::Escape)
					window.close();
				if (evnt.key.code == sf::Keyboard::Key::R)
					game.clearSelection();
				break;
			case sf::Event::Resized:
				ResizeView(window, view);
				break;
			default:
				break;
			}
		}
		window.clear(sf::Color(53, 2, 0));
		window.setView(view);
		game.Update(window);
		window.display();
	}
}

void Display::ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x / float(window.getSize().y));
	view.setSize(860 * aspectRatio, 900 * aspectRatio);
}
