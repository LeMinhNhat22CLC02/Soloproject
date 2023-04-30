#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>

class Singly {
public:
    Singly();
    ~Singly();
    void Set(std::vector<std::string> X);
    void AddFirst(std::string X);
    void AddLast(std::string X);
    void AddMiddle(std::string X);
    void DeleteFirst();
    void DeleteLast();
    void DeleteMiddle();
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
void AddFirst(Singly& X, std::string Y);
void AddLast(Singly& X, std::string Y);
void AddMiddle(Singly& X, std::string Y);
void DeleteFirst(Singly& X);
void DeleteLast(Singly& X);
void DeleteMiddle(Singly& X);
void Update(Singly& X, std::string Y, int Z);
void Search(Singly& X, std::string Y);
void SinglyClient(sf::Event Events, sf::RenderWindow& window);