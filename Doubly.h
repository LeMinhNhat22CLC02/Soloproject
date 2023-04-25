#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>

class Doubly {
public:
    Doubly();
    ~Doubly();
    void addFront(std::string val);
    void addBack(std::string val);
    void removeFront();
    void removeBack();
    int GetSize();
    void Print();
    bool isFull();
    bool isEmpty();
    void Set(std::vector<std::string> X);
    void Add(std::string X, int Y);
    void Delete(int X);
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
void Update(Doubly& X, std::string Y, int Z);
void Search(Doubly& X, std::string Y);
void DoublyClient(sf::Event Events, sf::RenderWindow& window);