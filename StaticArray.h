#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>
#include"Buttons.h"

void Set(std::string X[], std::vector<std::string> Y, int &n);
void AddFirst(std::string X[], std::string Y, int &n, sf::RenderWindow& window);
void AddMiddle(std::string X[], std::string Y, int &n, sf::RenderWindow& window);
void AddLast(std::string X[], std::string Y, int &n, sf::RenderWindow& window);
void DeleteFirst(std::string X[], int& n, sf::RenderWindow& window);
void DeleteMiddle(std::string X[], int& n, sf::RenderWindow& window);
void DeleteLast(std::string X[], int& n);
void Update(std::string X[], std::string Y, int Z, int n);
int Search(std::string X[], std::string Y, int n);
void Print(sf::RenderWindow& window, std::string data[], int size, int Nprint);
std::string GetData(sf::Event Events, sf::RenderWindow& window, Button btn[], int Nbtn, int X, int& Done, std::string Example[], int n);
int GetLocation(sf::Event Events, sf::RenderWindow& window, Button btn[], int Nbtn, int X, int Datasize, int& Done, std::string Example[], int n);
void StaticArrayClient(sf::Event Events, sf::RenderWindow& window);