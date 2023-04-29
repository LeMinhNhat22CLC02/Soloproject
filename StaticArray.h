#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>

void Set(std::string X[], std::vector<std::string> Y, int &n);
void AddFirst(std::string X[], std::string Y, int &n);
void AddMiddle(std::string X[], std::string Y, int &n);
void AddLast(std::string X[], std::string Y, int &n);
void DeleteFirst(std::string X[], int& n);
void DeleteMiddle(std::string X[], int& n);
void DeleteLast(std::string X[], int& n);
void Update(std::string X[], std::string Y, int Z, int n);
void Search(std::string X[], std::string Y, int n);
void StaticArrayClient(sf::Event Events, sf::RenderWindow& window);