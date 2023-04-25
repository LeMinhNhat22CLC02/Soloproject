#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>

class Singly {
public:
    Singly();
    ~Singly();
    void Set(std::vector<std::string> X);
    void Add(std::string X, int Location);
    void Delete(int Location);
    void Update(std::string X, int Location);
    void Search(std::string X);
    int GetSize();
    bool isFull();
    bool isEmpty();
    void Print();
private:
	struct Node
	{
		std::string data;
		Node* next = nullptr;
	};
	Node* head;
	int size;
};

void Set(Singly& X, std::vector<std::string> Y);
void Add(Singly& X, std::string Y, int Z);
void Delete(Singly& X, int Y);
void Update(Singly& X, std::string Y, int Z);
void Search(Singly& X, std::string Y);
void SinglyClient(sf::Event Events, sf::RenderWindow& window);