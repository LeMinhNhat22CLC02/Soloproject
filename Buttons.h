#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>

class Button {
public:
	Button(std::string t, sf::Vector2f size, int Charsize, sf::Color bgColor, sf::Color textColor, sf::Color OutColor);
	Button(std::string t, sf::Vector2f size, int Charsize, sf::Color bgColor, sf::Color textColor);
	void setFont(sf::Font& font);
	void setBackColor(sf::Color color);
	void setTextColor(sf::Color& color);
	void setPos(sf::Vector2f pos);
	void drawto(sf::RenderWindow& window);
	bool isMouseOver(sf::RenderWindow& window);
	sf::Vector2f getPosition();
private:
	sf::RectangleShape button;
	sf::Text text;
};