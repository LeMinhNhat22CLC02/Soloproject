#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>

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
void StaticArrayClient(sf::Event Events, sf::RenderWindow& window);