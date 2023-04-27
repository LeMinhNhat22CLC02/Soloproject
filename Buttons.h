#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>

class Button {
public:
	Button();
	Button(std::string t, sf::Vector2f size, int Charsize, sf::Color bgColor, sf::Color textColor, sf::Color OutColor, float Out);
	void setFont(sf::Font& font);
	void setBackColor(sf::Color color);
	void setTextColor(sf::Color& color);
	void setPos(sf::Vector2f pos);
	void drawto(sf::RenderWindow& window);
	bool isMouseOver(sf::RenderWindow& window);
	sf::Vector2f getPosition();
	void setString(std::string t);
private:
	sf::RectangleShape button;
	sf::Text text;
};