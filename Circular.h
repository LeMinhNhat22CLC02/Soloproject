#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>
#include"Buttons.h"

class Circular {
public:
    Circular();
    void Set(std::vector<std::string> X);
    void AddLast(std::string X);
    void AddMiddle(std::string X);
    void AddFirst(std::string X);
    void Delete();
    void DeleteFirst();
    void DeleteMiddle();
    void DeleteLast();
    void Update(std::string X, int Location);
    int Search(std::string X);
    bool isFull();
    bool isEmpty();
    void Print(sf::RenderWindow& window, int Nprint);
    void ScreenAdd(sf::RenderWindow& window, Button btn[], Button btnHome, std::string X, int Choosen);
    void ScreenAddForLast(sf::RenderWindow& window, Button btn[], Button btnHome, std::string X);
    void BeforeDelete(sf::RenderWindow& window, Button btn[], Button btnHome, int Choosen);
    void AfterDelete(sf::RenderWindow& window, Button btn[], Button btnHome, int Choosen);
    int GetSize();
private:
    struct Node {
        std::string data;
        Node* next;
        Node()
        {
            data = "";
            next = nullptr;
        }
    };
    Node* head;
    Node* tail;
    int size;
};

void Set(Circular& X, std::vector<std::string> Y);
void AddFirst(Circular& X, std::string Y);
void AddLast(Circular& X, std::string Y);
void AddMiddle(Circular& X, std::string Y);
void DeleteFirst(Circular& X);
void DeleteLast(Circular& X);
void DeleteMiddle(Circular& X);
void Update(Circular& X, std::string Y, int Z);
int Search(Circular& X, std::string Y);
void CircularClient(sf::Event Events, sf::RenderWindow& window);