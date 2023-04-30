#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>

class Circular {
public:
    Circular() 
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void AddNode(std::string val) {
        Node* newNode = new Node();
        newNode->data = val;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            newNode->next = head;
        }
        else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

private:
    struct Node {
        std::string data;
        Node* next;
        Node ()
        {
            data = "";
            next = nullptr;
        }
    };
    Node* head;
    Node* tail;
	int size;
};

void CircularClient(sf::Event Events, sf::RenderWindow& window);