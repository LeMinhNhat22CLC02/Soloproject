#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>

class Stack {
public:
    Stack();
    void Set(std::vector<std::string> X);
    bool isEmpty();
    bool isFull();
    void Push(std::string X, sf::RenderWindow& window);
    void Pop(sf::RenderWindow& window);
    void Print(sf::RenderWindow &window);
    int GetSize();
private:
	std::vector<std::string> data;
	int Size;
};

void Set(Stack& X, std::vector<std::string> Y);
void Push(Stack& X, std::string Y, sf::RenderWindow& window);
void Pop(Stack& X, sf::RenderWindow& window);
void StackClient(sf::Event Events, sf::RenderWindow& window);