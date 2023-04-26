#include<iostream>
#include<SFML/Graphics.hpp>
#include"Doubly.h"
#include"Buttons.h"
#include"TextBox.h"
#include"InputData.h"


Doubly::Doubly() : head(nullptr), tail(nullptr), size(0) {}

Doubly::~Doubly()
{
    Node* current = head;
    while (current != nullptr)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void Doubly::addFront(std::string val)
{
    Node* newNode = new Node(val);
    if (head == nullptr)
    {
        head = tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    size++;
}

void Doubly::addBack(std::string val)
{
    Node* newNode = new Node(val);
    if (tail == nullptr)
    {
        head = tail = newNode;
    }
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

void Doubly::removeFront()
{
    Node* nodeToDelete = head;
    head = head->next;
    if (head == nullptr)
    {
        tail = nullptr;
    }
    else
    {
        head->prev = nullptr;
    }
    delete nodeToDelete;
    size--;
}

void Doubly::removeBack()
{
    Node* nodeToDelete = tail;
    tail = tail->prev;
    if (tail == nullptr)
    {
        head = nullptr;
    }
    else
    {
        tail->next = nullptr;
    }
    delete nodeToDelete;
    size--;
}

int Doubly::GetSize()
{
    return size;
}

void Doubly::Print()
{
    Node* current = head;
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

bool Doubly::isFull()
{
    return size == 7;
}

bool Doubly::isEmpty()
{
    return size == 0;
}

void Doubly::Set(std::vector<std::string> X)
{
    head = nullptr;
    tail = nullptr;
    size = 0;
    for (int i = 0; i < X.size(); i++)
        addBack(X[i]);
}

void Doubly::Add(std::string X, int Y)
{
    if (Y == 0)
    {
        addFront(X);
        return;
    }
    if (Y == size)
    {
        addBack(X);
        return;
    }
    Node* Pre = head;
    for (int i = 0; i < Y - 1; i++)
        Pre = Pre->next;
    Node* Aft = Pre->next;
    Node* Now = new Node(X);
    Now->next = Aft; Aft->prev = Now;
    Now->prev = Pre; Pre->next = Now;
    size++;
}

void Doubly::Delete(int X)
{
    if (X == 0)
    {
        removeFront();
        return;
    }
    if (X == size - 1)
    {
        removeBack();
        return;
    }
    Node* Pre = head;
    for (int i = 0; i < X - 1; i++)
        Pre = Pre->next;
    Node* Del = Pre->next, * Aft = Del->next;
    Pre->next = Aft;
    Aft->prev = Pre;
    delete Del;
    size--;
}

void Doubly::Update(std::string X, int Y)
{
    Node* Pre = head;
    for (int i = 0; i < Y; i++)
        Pre = Pre->next;
    Pre->data = X;
}

void Doubly::Search(std::string X)
{
    Node* current = head;
    int count = 0;
    while (current != nullptr)
    {
        if (current->data == X)
        {
            std::cout << count << std::endl;
            return;
        }
        count++;
        current = current->next;
    }
    std::cout << -1 << std::endl;
}

void Set(Doubly &X, std::vector<std::string> Y)
{
    X.Set(Y);
}

void Add(Doubly &X, std::string Y, int Z)
{
    X.Add(Y, Z);
}

void Delete(Doubly &X, int Y)
{
    X.Delete(Y);
}

void Update(Doubly &X, std::string Y, int Z)
{
    X.Update(Y, Z);
}

void Search(Doubly& X, std::string Y)
{
    X.Search(Y);
}

void DoublyClient(sf::Event Events, sf::RenderWindow& window)
{
    sf::Font arial;
    arial.loadFromFile("arial.ttf");

    sf::Color ScreenColor(238, 137, 128);
    sf::Color OutColor(241, 70, 102);
    sf::Color BoxColor(255, 220, 195);
    sf::Color TextColor(64, 140, 124);

    Button btn1("Initialize", { 100, 100 }, 15, BoxColor, TextColor, OutColor, 5);
    btn1.setPos({ 50, 50 });
    btn1.setFont(arial);

    Button btn2("Add", { 100, 100 }, 15, BoxColor, TextColor, OutColor, 5);
    btn2.setPos({ 50, 200 });
    btn2.setFont(arial);

    Button btn3("Delete", { 100, 100 }, 15, BoxColor, TextColor, OutColor, 5);
    btn3.setPos({ 50, 350 });
    btn3.setFont(arial);

    Button btn4("Update", { 100, 100 }, 15, BoxColor, TextColor, OutColor, 5);
    btn4.setPos({ 50, 500 });
    btn4.setFont(arial);

    Button btn5("Search", { 100, 100 }, 15, BoxColor, TextColor, OutColor, 5);
    btn5.setPos({ 50, 650 });
    btn5.setFont(arial);

    Button btn6("Home", { 100, 100 }, 15, sf::Color::Cyan, TextColor, OutColor, 5);
    btn6.setPos({ 1200, 0 });
    btn6.setFont(arial);

    sf::Text Warnings1;
    Warnings1.setFont(arial);
    Warnings1.setCharacterSize(20);
    Warnings1.setString("You can not have more than 7 elements!");
    Warnings1.sf::Text::setFillColor(TextColor);
    Warnings1.setPosition({ 50, 173 });

    sf::Text Warnings2;
    Warnings2.setFont(arial);
    Warnings2.setCharacterSize(20);
    Warnings2.setString("It is empty!");
    Warnings2.sf::Text::setFillColor(TextColor);

    Doubly Example;
    Set(Example, Initialize());

    int Type = 0;
    int Done = 0;

    while (window.isOpen())
    {
        while (window.pollEvent(Events))
        {
            if (Done != 0)
            {
                switch (Done)
                {
                case 1:
                    Type = 0;
                    Done = 0;
                    Set(Example, Initialize());
                    break;

                case 2:
                    if (Example.isFull())
                    {
                        Type = 1;
                    }
                    else
                    {
                        Type = 0;
                        Done = 2;
                        std::string X = GetData(Events, window, btn1, btn3, btn4, btn5, btn6, btn2, Done);
                        std::cout << Done << "1" << std::endl;
                        if (Done != 0) break;
                        Done = 2;
                        int Y = GetLocation(Events, window, btn1, btn3, btn4, btn5, btn6, btn2, Example.GetSize(), Done);
                        std::cout << Done << "2" << std::endl;
                        if (Done != 0) break;
                        std::cout << Done << "3" << std::endl;
                        Add(Example, X, Y);
                    }
                    break;

                case 3:
                    if (Example.isEmpty())
                    {
                        Warnings2.setPosition({ 50, 323 });
                        Type = 2;
                    }
                    else
                    {
                        Type = 0;
                        Done = 3;
                        int X = GetLocation(Events, window, btn1, btn2, btn4, btn5, btn6, btn3, Example.GetSize() - 1, Done);
                        if (Done != 0) break;
                        Delete(Example, X);
                    }
                    break;

                case 4:
                    if (Example.isEmpty())
                    {
                        Warnings2.setPosition({ 50, 473 });
                        Type = 2;
                    }
                    else
                    {
                        Type = 0;
                        Done = 4;
                        std::string X = GetData(Events, window, btn1, btn2, btn3, btn5, btn6, btn4, Done);
                        if (Done != 0) break;
                        Done = 4;
                        int Y = GetLocation(Events, window, btn1, btn2, btn3, btn5, btn6, btn4, Example.GetSize() - 1, Done);
                        if (Done != 0) break;
                        Update(Example, X, Y);
                    }
                    break;

                case 5:
                    if (Example.isEmpty())
                    {
                        Warnings2.setPosition({ 50, 623 });
                        Type = 2;
                    }
                    else
                    {
                        Type = 0;
                        Done = 5;
                        std::string X = GetData(Events, window, btn1, btn2, btn3, btn4, btn6, btn5, Done);
                        if (Done != 0) break;
                        Search(Example, X);
                    }
                    break;
                case 6:
                    Done = 0;
                    return;
                    break;
                }
            }
            else
            {
                switch (Events.type)
                {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::MouseMoved:
                    if (btn1.isMouseOver(window))
                    {
                        btn1.setBackColor(sf::Color::White);
                    }
                    else if (btn2.isMouseOver(window))
                    {
                        btn2.setBackColor(sf::Color::White);
                    }
                    else if (btn3.isMouseOver(window))
                    {
                        btn3.setBackColor(sf::Color::White);
                    }
                    else if (btn4.isMouseOver(window))
                    {
                        btn4.setBackColor(sf::Color::White);
                    }
                    else if (btn5.isMouseOver(window))
                    {
                        btn5.setBackColor(sf::Color::White);
                    }
                    else if (btn6.isMouseOver(window))
                    {
                        btn6.setBackColor(sf::Color::White);
                    }
                    else
                    {
                        btn1.setBackColor(BoxColor);
                        btn2.setBackColor(BoxColor);
                        btn3.setBackColor(BoxColor);
                        btn4.setBackColor(BoxColor);
                        btn5.setBackColor(BoxColor);
                        btn6.setBackColor(sf::Color::Cyan);
                    }
                    break;

                case sf::Event::MouseButtonPressed:
                    if (btn1.isMouseOver(window))
                    {
                        Type = 0;
                        Set(Example, Initialize());
                    }
                    else if (btn2.isMouseOver(window))
                    {
                        if (Example.isFull())
                        {
                            Type = 1;
                        }
                        else
                        {
                            Type = 0;
                            Done = 2;
                            std::string X = GetData(Events, window, btn1, btn3, btn4, btn5, btn6, btn2, Done);
                            std::cout << Done << "5" << std::endl;
                            if (Done != 0) break;
                            Done = 2;
                            int Y = GetLocation(Events, window, btn1, btn3, btn4, btn5, btn6, btn2, Example.GetSize(), Done);
                            std::cout << Done << "6" << std::endl;
                            if (Done != 0) break;
                            Add(Example, X, Y);
                            Type = 0;
                        }
                    }
                    else if (btn3.isMouseOver(window))
                    {
                        if (Example.isEmpty())
                        {
                            Warnings2.setPosition({ 50, 283 });
                            Type = 2;
                        }
                        else
                        {
                            Type = 0;
                            Done = 3;
                            int X = GetLocation(Events, window, btn1, btn2, btn4, btn5, btn6, btn3, Example.GetSize() - 1, Done);
                            if (Done != 0) break;
                            Delete(Example, X);
                        }
                    }
                    else if (btn4.isMouseOver(window))
                    {
                        if (Example.isEmpty())
                        {
                            Warnings2.setPosition({ 50, 413 });
                            Type = 2;
                        }
                        else
                        {
                            Type = 0;
                            Done = 4;
                            std::string X = GetData(Events, window, btn1, btn2, btn3, btn5, btn6, btn4, Done);
                            if (Done != 0) break;
                            Done = 4;
                            int Y = GetLocation(Events, window, btn1, btn2, btn3, btn5, btn6, btn4, Example.GetSize() - 1, Done);
                            if (Done != 0) break;
                            Update(Example, X, Y);
                        }
                    }
                    else if (btn5.isMouseOver(window))
                    {
                        if (Example.isEmpty())
                        {
                            Warnings2.setPosition({ 50, 543 });
                            Type = 2;
                        }
                        else
                        {
                            Type = 0;
                            Done = 5;
                            std::string X = GetData(Events, window, btn1, btn2, btn3, btn4, btn6, btn5, Done);
                            if (Done != 0) break;
                            Search(Example, X);
                        }
                    }
                    else if (btn6.isMouseOver(window))
                    {
                        return;
                    }
                }
            }
        }
        window.clear(ScreenColor);
        Example.Print();
        btn1.drawto(window);
        btn2.drawto(window);
        btn3.drawto(window);
        btn4.drawto(window);
        btn5.drawto(window);
        btn6.drawto(window);
        if (Type == 1) window.draw(Warnings1);
        else if (Type == 2) window.draw(Warnings2);
        window.display();
    }
}