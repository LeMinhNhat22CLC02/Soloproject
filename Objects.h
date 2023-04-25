#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>

class Arrow {
public:
	void Save()
	{
        sf::ConvexShape arrow(3);
        arrow.setPosition(200, 200);
        arrow.setFillColor(sf::Color::Red);
        arrow.setPoint(0, sf::Vector2f(0, 0));
        arrow.setPoint(1, sf::Vector2f(50, 0));
        arrow.setPoint(2, sf::Vector2f(50, 25));
	}
private:
};