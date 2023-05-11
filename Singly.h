#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>
#include"Buttons.h"

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
    int Search(std::string X);
    int GetSize();
    bool isFull();
    bool isEmpty();
    void Print(sf::RenderWindow& window, int Nprint);
    void ScreenAdd(sf::RenderWindow& window, Button btn[], Button btnHome, std::string X, int Choosen);
    void ScreenAddForLast(sf::RenderWindow& window, Button btn[], Button btnHome, std::string X);
    void BeforeDelete(sf::RenderWindow& window, Button btn[], Button btnHome, int Choosen);
    void AfterDelete(sf::RenderWindow& window, Button btn[], Button btnHome, int Choosen);
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
int Search(Singly& X, std::string Y);
std::string GetData(sf::Event Events, sf::RenderWindow& window, Button btn[], int Nbtn, int X, int& Done, Singly& Example);
int GetLocation(sf::Event Events, sf::RenderWindow& window, Button btn[], int Nbtn, int X, int Datasize, int& Done, Singly& Example);
void SinglyClient(sf::Event Events, sf::RenderWindow& window);