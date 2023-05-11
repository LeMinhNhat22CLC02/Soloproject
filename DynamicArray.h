#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>
#include"Buttons.h"

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
    void Print(sf::RenderWindow& window, int Nprint);
    void AddFirst(std::string X);
    void AddMiddle(std::string X);
    void AddLast(std::string X);
    void DeleteFirst();
    void DeleteMiddle();
    void DeleteLast();
    void Update(std::string X, int Location);
    void resize(int newSize);
    int getCap();
    int Search(std::string X);
    void PrintAdd(int Num, Button btn[], Button btnHome, sf::RenderWindow& window);
    void PrintDelete(int Num, Button btn[], Button btnHome, sf::RenderWindow& window);
private:
    int size;
    int capacity;
    std::vector<std::string> data;
};

void Set(Dynamic& X, std::vector<std::string> Y);
void AddFirst(Dynamic &X, std::string Y);
void AddMiddle(Dynamic &X, std::string Y);
void AddLast(Dynamic &X, std::string Y);
void DeleteFirst(Dynamic &X);
void DeleteMiddle(Dynamic &X);
void DeleteLast(Dynamic &X);
void Update(Dynamic& X, std::string Y, int Z);
int Search(Dynamic& X, std::string Y);
std::string GetData(sf::Event Events, sf::RenderWindow& window, Button btn[], int Nbtn, int X, int& Done, Dynamic Example);
int GetLocation(sf::Event Events, sf::RenderWindow& window, Button btn[], int Nbtn, int X, int Datasize, int& Done, Dynamic Example);
int GetSize(sf::Event Events, sf::RenderWindow& window, Button btn[], int Nbtn, int X, int Datasize, int& Done, Dynamic Example);
void DynamicArrayClient(sf::Event Events, sf::RenderWindow& window);