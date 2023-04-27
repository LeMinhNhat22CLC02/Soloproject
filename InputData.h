#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>
#include"Buttons.h"
#include<vector>

std::vector<std::string> Initialize();
int WhatType(std::string X, int Datasize);
std::string GetData(sf::Event Events, sf::RenderWindow& window, Button btn1, Button btn2, Button btn3, Button btn4, Button btn5, Button btnX, int &Done);
int GetLocation(sf::Event Events, sf::RenderWindow& window, Button btn1, Button btn2, Button btn3, Button btn4, Button btn5, Button btnX, int Datasize, int& Done);
std::string GetData(sf::Event Events, sf::RenderWindow& window, Button btn[], int Nbtn, int X, int& Done);
int GetLocation(sf::Event Events, sf::RenderWindow& window, Button btn[], int Nbtn, int X, int Datasize, int& Done);