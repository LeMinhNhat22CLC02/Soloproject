#include<iostream>
#include<SFML/Graphics.hpp>
#include"Buttons.h"

Button::Button(std::string t, sf::Vector2f size, int Charsize, sf::Color bgColor, sf::Color textColor, sf::Color OutColor)
{
	text.setString(t);
	text.sf::Text::setFillColor(textColor);
	text.setCharacterSize(Charsize);
	text.setStyle(sf::Text::Bold);

	button.setSize(size);
	button.setFillColor(bgColor);
	button.setOutlineThickness(5);
	button.setOutlineColor(OutColor);
}

Button::Button(std::string t, sf::Vector2f size, int Charsize, sf::Color bgColor, sf::Color textColor)
{
	text.setString(t);
	text.sf::Text::setFillColor(textColor);
	text.setCharacterSize(Charsize);

	button.setSize(size);
	button.setFillColor(bgColor);
	button.setOutlineThickness(5);
	button.setOutlineColor(sf::Color::Cyan);
}

void Button::setFont(sf::Font& font)
{
	text.setFont(font);
}

void Button::setBackColor(sf::Color color)
{
	button.setFillColor(color);
}

void Button::setTextColor(sf::Color& color)
{
	text.sf::Text::setFillColor(color);
}

void Button::setPos(sf::Vector2f pos)
{
	button.setPosition(pos);
	text.setPosition(pos);
}

void Button::drawto(sf::RenderWindow& window)
{
	window.draw(button);
	window.draw(text);
}

bool Button::isMouseOver(sf::RenderWindow& window)
{
	float MouseX = sf::Mouse::getPosition(window).x;
	float MouseY = sf::Mouse::getPosition(window).y;

	float BtnPosX = button.getPosition().x;
	float BtnPosY = button.getPosition().y;

	float btnXPosWidth = button.getPosition().x + button.getLocalBounds().width;
	float btnYPosHeight = button.getPosition().y + button.getLocalBounds().height;

	if (MouseX > BtnPosX && MouseX < btnXPosWidth && MouseY > BtnPosY && MouseY < btnYPosHeight)
	{
		return true;
	}
	return false;
};

sf::Vector2f Button::getPosition()
{
	return button.getPosition();
}