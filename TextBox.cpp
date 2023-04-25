#include<iostream>
#include<SFML/Graphics.hpp>
#include<sstream>
#include"TextBox.h"

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

Textbox::Textbox(int Size, sf::Color color, bool sel)
{
	textbox.setCharacterSize(Size);
	textbox.sf::Text::setFillColor(color);
	textbox.setStyle(sf::Text::Bold);
	isSelected = sel;
	if (sel)
	{
		textbox.setString("_");
	}
	else
	{
		textbox.setString("");
	}
}

void Textbox::setFont(sf::Font& font)
{
	textbox.setFont(font);
}

void Textbox::setPosition(sf::Vector2f pos)
{
	textbox.setPosition(pos);
}

void Textbox::setLimit(bool Check)
{
	Haslimit = Check;
}

void Textbox::setLimit(bool Check, int lim)
{
	Haslimit = Check;
	limit = lim - 1;
}

void Textbox::setSelected(bool sel)
{
	isSelected = sel;
	if (!sel)
	{
		std::string t = text.str();
		std::string Newt = "";
		for (int i = 0; i < t.size(); i++)
			Newt += t[i];
		textbox.setString(Newt);
	}
}

std::string Textbox::getText()
{
	return text.str();
}

void Textbox::drawto(sf::RenderWindow& window)
{
	window.draw(textbox);
}

void Textbox::typeOn(sf::Event input)
{
	if (isSelected)
	{
		int chartyped = input.text.unicode;
		if (chartyped < 128)
		{
			if (Haslimit)
			{
				if (text.str().length() <= limit)
				{
					inputLogic(chartyped);
				}
				else if (text.str().length() > limit && chartyped == DELETE_KEY)
				{
					deleteLastchar();
				}
			}
			else
			{
				inputLogic(chartyped);
			}
		}
	}
}

void Textbox::inputLogic(int charTyped)
{
	if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY)
	{
		text << static_cast<char>(charTyped);
	}
	else if (charTyped == DELETE_KEY && text.str().length() > 0)
	{
		deleteLastchar();
	}
	textbox.setString(text.str() + "_");
}

void Textbox::deleteLastchar()
{
	std::string t = text.str();
	std::string Newt = "";
	for (int i = 0; i < t.size() - 1; i++)
		Newt += t[i];
	text.str("");
	text << Newt;
	textbox.setString(text.str());
}

void Textbox::Clear()
{
	text.str("");
	textbox.setString(text.str());
}

void Textbox::setText(std::string X)
{
	text.str("");
	text << X;
	textbox.setString(text.str());
}
