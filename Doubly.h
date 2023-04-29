#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>

class Doubly {
public:
    Doubly();
    ~Doubly();
    int GetSize();
    void Print();
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
    void Search(std::string X);
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
void Add(Doubly& X, std::string Y, int Z);
void Delete(Doubly& X, int Y);
void AddFirst(Doubly& X, std::string Y);
void AddLast(Doubly& X, std::string Y);
void AddMiddle(Doubly& X, std::string Y);
void DeleteFirst(Doubly& X);
void DeleteLast(Doubly& X);
void DeleteMiddle(Doubly& X);
void Update(Doubly& X, std::string Y, int Z);
void Search(Doubly& X, std::string Y);
void DoublyClient(sf::Event Events, sf::RenderWindow& window);