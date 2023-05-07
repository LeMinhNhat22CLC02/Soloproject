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

void PrintBox(int Num, sf::RenderWindow& window);