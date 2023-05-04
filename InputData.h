#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>
#include"Buttons.h"
#include<vector>

std::vector<std::string> Initialize();
std::vector<std::string> ReadFromFile(const char* inputPath);
const char* FindPath();
int WhatType(std::string X, int Datasize);
std::string GetData(sf::Event Events, sf::RenderWindow& window, Button btn[], int Nbtn, int X, int& Done);
int GetLocation(sf::Event Events, sf::RenderWindow& window, Button btn[], int Nbtn, int X, int Datasize, int& Done);
int GetSize(sf::Event Events, sf::RenderWindow& window, Button btn[], int Nbtn, int X, int Datasize, int& Done);