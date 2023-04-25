#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>

class Stack {
public:
    Stack();
    void SetStack(std::vector<std::string> X);
    bool isEmpty();
    bool isFull();
    void Add(std::string X, int Location);
    void Delete(int Location);
    void Update(std::string X, int Location);
    void Search(std::string X);
    void Print(sf::RenderWindow &window);
    int GetSize();
private:
	std::vector<std::string> data;
	int Size;
};

void Set(Stack& X, std::vector<std::string> Y);
void Add(Stack& X, std::string Y, int Z);
void Delete(Stack& X, int Y);
void Update(Stack& X, std::string Y, int Z);
void Search(Stack X, std::string Y);
void StackClient(sf::Event Events, sf::RenderWindow& window);