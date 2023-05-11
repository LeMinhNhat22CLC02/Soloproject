#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>
#include"Buttons.h"

class Doubly {
public:
    Doubly();
    ~Doubly();
    int GetSize();
    void Print(sf::RenderWindow& window, int Nprint);
    bool isFull();
    bool isEmpty();
    void AddFirst(std::string val);
    void AddLast(std::string val);
    void AddMiddle(std::string X);
    void DeleteFirst();
    void DeleteLast();
    void DeleteMiddle();
    void Set(std::vector<std::string> X);
    void Update(std::string X, int Y);
    int Search(std::string X);
    void ScreenAdd(sf::RenderWindow& window, Button btn[], Button btnHome, std::string X, int Choosen);
    void ScreenAddForLast(sf::RenderWindow& window, Button btn[], Button btnHome, std::string X);
    void BeforeDelete(sf::RenderWindow& window, Button btn[], Button btnHome, int Choosen);
    void AfterDelete(sf::RenderWindow& window, Button btn[], Button btnHome, int Choosen);
private:
    class Node {
    public:
        std::string data;
        Node* prev;
        Node* next;
        Node(std::string val) : data(val), prev(nullptr), next(nullptr) {}
    };
    Node* head;
    Node* tail;
    int size;
};

void Set(Doubly& X, std::vector<std::string> Y);
void AddFirst(Doubly& X, std::string Y);
void AddLast(Doubly& X, std::string Y);
void AddMiddle(Doubly& X, std::string Y);
void DeleteFirst(Doubly& X);
void DeleteLast(Doubly& X);
void DeleteMiddle(Doubly& X);
void Update(Doubly& X, std::string Y, int Z);
int Search(Doubly& X, std::string Y);
std::string GetData(sf::Event Events, sf::RenderWindow& window, Button btn[], int Nbtn, int X, int& Done, Doubly& Example);
int GetLocation(sf::Event Events, sf::RenderWindow& window, Button btn[], int Nbtn, int X, int Datasize, int& Done, Doubly& Example);
void DoublyClient(sf::Event Events, sf::RenderWindow& window);