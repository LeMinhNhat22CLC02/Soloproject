#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>

class Queue {
public:
    Queue();
    ~Queue();
    void enqueue(std::string data);
    std::string dequeue();
    std::string peek();
    bool isFull();
    bool isEmpty();
    void Print();
    int GetSize();
    void Set(std::vector<std::string> X);
    void Add(std::string X, int Y);
    void Delete(int X);
    void Update(std::string X, int Y);
    void Search(std::string X);
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
void Add(Queue& X, std::string Y, int Z);
void Delete(Queue& X, int Y);
void Update(Queue& X, std::string Y, int Z);
void Search(Queue& X, std::string Y);
void QueueClient(sf::Event Events, sf::RenderWindow& window);