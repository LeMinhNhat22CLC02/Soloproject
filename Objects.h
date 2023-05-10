#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>

void PrintArrow(int Num, sf::RenderWindow& window);
void PrintArrow(int Num, int except1, int except2, sf::RenderWindow& window);
void PrintDoubleArrow(int Num, int except1, int except2, sf::RenderWindow& window);
void ArrowPointAt(int Num, sf::RenderWindow& window);
void ArrowPointUpAt(int Num, sf::RenderWindow& window);
void ArrowPoint(int Num, sf::RenderWindow& window);
void PrintBox(int Num, sf::RenderWindow& window);
void PrintBox(int Num, int Except, sf::RenderWindow& window);
void LongArrow(int Num, sf::RenderWindow& window);