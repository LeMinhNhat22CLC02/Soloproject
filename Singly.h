#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>

class Singly {
public:
    Singly();
    ~Singly();
    void Set(std::vector<std::string> X);
    void AddFirst(std::string X, sf::RenderWindow& window);
    void AddLast(std::string X, sf::RenderWindow& window);
    void AddMiddle(std::string X, sf::RenderWindow& window);
    void DeleteFirst(sf::RenderWindow& window);
    void DeleteLast(sf::RenderWindow& window);
    void DeleteMiddle(sf::RenderWindow& window);
    void Update(std::string X, int Location);
    int Search(std::string X);
    int GetSize();
    bool isFull();
    bool isEmpty();
    void Print(sf::RenderWindow& window, int Nprint);
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
void AddFirst(Singly& X, std::string Y, sf::RenderWindow& window);
void AddLast(Singly& X, std::string Y, sf::RenderWindow& window);
void AddMiddle(Singly& X, std::string Y, sf::RenderWindow& window);
void DeleteFirst(Singly& X, sf::RenderWindow& window);
void DeleteLast(Singly& X, sf::RenderWindow& window);
void DeleteMiddle(Singly& X, sf::RenderWindow& window);
void Update(Singly& X, std::string Y, int Z);
int Search(Singly& X, std::string Y);
void SinglyClient(sf::Event Events, sf::RenderWindow& window);