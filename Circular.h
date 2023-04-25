#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>

class Circular {
public:
    Circular() : head(nullptr), tail(nullptr), size(0) {}

    void addFront(int val) 
    {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = nullptr;

        if (head == nullptr) 
        {
            head = newNode;
            tail = newNode;
            tail->next = head;
        }
        else 
        {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }

        size++;
    }

    void addMiddle(int val, int pos) 
    {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = nullptr;

        if (pos == 0) 
        {
            addFront(val);
            return;
        }
        else if (pos == size) 
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
        else 
        {
            Node* current = head;
            for (int i = 0; i < pos - 1; i++) 
            {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }

        size++;
    }

    void print() {
        Node* current = head;

        while (current != head)
        {
            std::cout << current->data << " ";
            current = current->next;
        } 

        std::cout << std::endl;
    }
private:
    struct Node {
        int data;
        Node* next;
    };
    Node* head;
    Node *tail;
	int size;
};

void CircularClient(sf::Event Events, sf::RenderWindow& window);