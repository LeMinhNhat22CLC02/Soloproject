#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>

void Set(std::string X[], std::vector<std::string> Y, int &n);
void Add(std::string X[], std::string Y, int Z, int &n);
void Delete(std::string X[], int Y, int &n);
void Update(std::string X[], std::string Y, int Z, int n);
void Search(std::string X[], std::string Y, int n);
void StaticArrayClient(sf::Event Events, sf::RenderWindow& window);