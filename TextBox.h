#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>
#include<sstream>

class Textbox {
public:
	Textbox() {}
	Textbox(int Size, sf::Color color, bool sel);
	void setFont(sf::Font& font);
	void setPosition(sf::Vector2f pos);
	void setLimit(bool Check);
	void setLimit(bool Check, int lim);
	void setSelected(bool sel);
	std::string getText();
	void drawto(sf::RenderWindow& window);
	void typeOn(sf::Event input);
	void Clear();
	void setText(std::string X);
private:
	sf::Text textbox;
	std::ostringstream text;
	bool isSelected = false;
	bool Haslimit = false;
	int limit = 0;

	void inputLogic(int charTyped);
	void deleteLastchar();
};
