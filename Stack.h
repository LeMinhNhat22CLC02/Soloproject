#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>

class Stack {
public:
    Stack();
    void Set(std::vector<std::string> X);
    bool isEmpty();
    bool isFull();
    void Push(std::string X);
    void Pop();
    void Print(sf::RenderWindow &window);
    int GetSize();
private:
	std::vector<std::string> data;
	int Size;
};

void Set(Stack& X, std::vector<std::string> Y);
void Push(Stack& X, std::string Y);
void Pop(Stack& X);
void StackClient(sf::Event Events, sf::RenderWindow& window);