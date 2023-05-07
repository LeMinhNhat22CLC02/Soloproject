#include<iostream>
#include<SFML/Graphics.hpp>

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