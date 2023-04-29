#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>

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
    void Print();
    void AddFirst(std::string X);
    void AddMiddle(std::string X);
    void AddLast(std::string X);
    void DeleteFirst();
    void DeleteMiddle();
    void DeleteLast();
    void Update(std::string X, int Location);
    void resize(int newSize);
    int getCap();
    void Search(std::string X);
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
void Search(Dynamic& X, std::string Y);
void DynamicArrayClient(sf::Event Events, sf::RenderWindow& window);