#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>
#include"Buttons.h"

class Queue {
public:
    Queue();
    ~Queue();
    void Add(std::string data);
    void Remove();
    bool isFull();
    bool isEmpty();
    void Print(sf::RenderWindow& window);
    int GetSize();
    void Set(std::vector<std::string> X);
private:
    struct Node
    {
        std::string data;
        Node* next = nullptr;
    };

    Node* front;
    Node* back;
    int Size;
};

void Set(Queue& X, std::vector<std::string> Y);
void Add(Queue& X, std::string Y);
void Remove(Queue& X);
std::string GetData(sf::Event Events, sf::RenderWindow& window, Button btn[], int Nbtn, int X, int& Done, Queue& Example);
void QueueClient(sf::Event Events, sf::RenderWindow& window);