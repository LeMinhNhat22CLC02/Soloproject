#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>

class Dynamic {
public:
    Dynamic();
    Dynamic(int cap);
    std::string& operator[](int index);
    int GetSize();
    bool isFull();
    bool isMax();
    bool isEmpty();
    void Set(std::vector<std::string> X);
    void Print(sf::RenderWindow& window);
    void AddFirst(std::string X, sf::RenderWindow& window);
    void AddMiddle(std::string X, sf::RenderWindow& window);
    void AddLast(std::string X, sf::RenderWindow& window);
    void DeleteFirst(sf::RenderWindow& window);
    void DeleteMiddle(sf::RenderWindow& window);
    void DeleteLast(sf::RenderWindow& window);
    void Update(std::string X, int Location);
    void resize(int newSize);
    int getCap();
    void Search(std::string X);
private:
    int size;
    int capacity;
    std::vector<std::string> data;
};

void Set(Dynamic& X, std::vector<std::string> Y);
void AddFirst(Dynamic &X, std::string Y, sf::RenderWindow& window);
void AddMiddle(Dynamic &X, std::string Y, sf::RenderWindow& window);
void AddLast(Dynamic &X, std::string Y, sf::RenderWindow& window);
void DeleteFirst(Dynamic &X, sf::RenderWindow& window);
void DeleteMiddle(Dynamic &X, sf::RenderWindow& window);
void DeleteLast(Dynamic &X, sf::RenderWindow& window);
void Update(Dynamic& X, std::string Y, int Z);
void Search(Dynamic& X, std::string Y);
void DynamicArrayClient(sf::Event Events, sf::RenderWindow& window);