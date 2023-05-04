#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>

class Arrow {
public:
    Arrow()
    {
        Pos = { 0, 0 };
    }

	void setPos(sf::Vector2f newPos)
	{
        Pos = newPos;
	}

    void drawto(sf::RenderWindow& window)
    {
        window.draw(arrow);
    }
private:
    sf::Vector2f Pos;
    sf::ConvexShape arrow;
}; 

void PrintBox(int Num, sf::RenderWindow& window)
{
    sf::Color OutColor(241, 70, 102);
    sf::Color BoxColor(255, 220, 195);

    sf::CircleShape Box(50.f);
    Box.setFillColor(BoxColor);
    Box.setFillColor(BoxColor);
    Box.setOutlineThickness(3);
    Box.setOutlineColor(OutColor);

    for (int i = 0; i < Num; i++)
    {
        Box.setPosition({ (float)225 + i * (150), 250 });
        window.draw(Box);
    }
}