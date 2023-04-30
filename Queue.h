#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>

class Queue {
public:
    Queue();
    ~Queue();
    void Add(std::string data);
    void Remove();
    bool isFull();
    bool isEmpty();
    void Print();
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
void QueueClient(sf::Event Events, sf::RenderWindow& window);