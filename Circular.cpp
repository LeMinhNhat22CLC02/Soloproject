#include<iostream>
#include<SFML/Graphics.hpp>
#include"Circular.h"
#include"Buttons.h"
#include"TextBox.h"
#include"InputData.h"
#include"Objects.h"

Circular::Circular()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

void Circular::Set(std::vector<std::string> X)
{
    for (int i = 0; i < X.size(); i++)
        AddFirst(X[i]);
}

void Circular::AddLast(std::string X) {
    Node* newNode = new Node();
    newNode->data = X;
    if (head == nullptr) 
    {
        head = newNode;
        tail = newNode;
        newNode->next = head;
        size++;
    }
    else 
    {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
        size++;
    }
}

void Circular::AddMiddle(std::string X)
{
    Node* newNode = new Node();
    newNode->data = X;
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        newNode->next = head;
        size++;
        return;
    }
    if (size == 1)
    {
        AddLast(X);
        return;
    }
    Node* temp = head;
    for (int i = 1; i < size / 2 && temp != tail; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    size++;
}

void Circular::AddFirst(std::string X)
{
    Node* newNode = new Node();
    newNode->data = X;
    if (head == nullptr) 
    {
        head = newNode;
        tail = newNode;
        newNode->next = head;
    }
    else 
    {
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
    size++;
}

void Circular::Delete()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

void Circular::DeleteFirst()
{
    if (size == 1)
    {
        Delete();
        return;
    }
    Node* toRemove = head;
    tail->next = head->next;
    head = head->next;
    delete toRemove;
    size--;
}

void Circular::DeleteMiddle()
{
    if (size == 1)
    {
        Delete();
        return;
    }
    int Location = size / 2 - 1;
    Node* temp = head;
    while (Location--)
    {
        temp = temp->next;
    }
    Node* toRemove = temp->next;
    temp->next = toRemove->next;
    delete toRemove;
    size--;
}

void Circular::DeleteLast()
{
    if (size == 1)
    {
        Delete();
        return;
    }
    int Location = size - 2;
    Node* temp = head;
    while (Location--)
    {
        temp = temp->next;
    }
    Node* toRemove = temp->next;
    temp->next = toRemove->next;
    delete toRemove;
    size--;
}

void Circular::Update(std::string X, int Location)
{
    Node* temp = head;
    while (Location--)
    {
        temp = temp->next;
    }
    temp->data = X;
    return;
}

void Circular::Search(std::string X)
{
    Node* temp = head;
    int count = 0;
    while (temp != nullptr)
    {
        if (temp->data == X)
        {
            std::cout << count << std::endl;
            return;
        }
        count++;
        temp = temp->next;
    }
    std::cout << -1 << std::endl;
}

void Circular::Print() {
    if (head == nullptr) return;
    Node* temp = head;
    do {
        std::cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    std::cout << std::endl;
}

bool Circular::isFull()
{
    return size == 7;
}

bool Circular::isEmpty()
{
    return size == 0;
}

int Circular::GetSize()
{
    return size;
}

void Set(Circular& X, std::vector<std::string> Y)
{
    X.Set(Y);
}

void AddFirst(Circular& X, std::string Y)
{
    X.AddFirst(Y);
}

void AddLast(Circular& X, std::string Y)
{
    X.AddLast(Y);
}

void AddMiddle(Circular& X, std::string Y)
{
    X.AddMiddle(Y);
}

void DeleteFirst(Circular& X)
{
    X.DeleteFirst();
}

void DeleteLast(Circular& X)
{
    X.DeleteLast();
}

void DeleteMiddle(Circular& X)
{
    X.DeleteMiddle();
}

void Update(Circular& X, std::string Y, int Z)
{
    X.Update(Y, Z);
}
void Search(Circular& X, std::string Y)
{
    X.Search(Y);
}

void CircularClient(sf::Event Events, sf::RenderWindow& window)
{
    sf::Font arial;
    arial.loadFromFile("arial.ttf");

    sf::Color ScreenColor(238, 137, 128);
    sf::Color OutColor(241, 70, 102);
    sf::Color BoxColor(255, 220, 195);
    sf::Color TextColor(64, 140, 124);

    Button btn[10];
    for (int i = 0; i < 10; i++)
    {
        btn[i] = Button("", { 160, 40 }, 15, BoxColor, TextColor, OutColor, 3);
        btn[i].setPos({ 10, (float)10 + i * 56 });
        btn[i].setFont(arial);
    }
    btn[0].setString("Init from file");
    btn[1].setString("Randomized data");
    btn[2].setString("Insert to the first");
    btn[3].setString("Insert to the last");
    btn[4].setString("Insert to the middle");
    btn[5].setString("Delete at the first");
    btn[6].setString("Delete at the last");
    btn[7].setString("Delete at the middle");
    btn[8].setString("Update");
    btn[9].setString("Search");

    sf::Text Warnings1;
    Warnings1.setFont(arial);
    Warnings1.setCharacterSize(20);
    Warnings1.setString("You can not have more than 7 elements!");
    Warnings1.sf::Text::setFillColor(sf::Color::Cyan);
    Warnings1.setPosition({ 500, 50 });
    Warnings1.setStyle(sf::Text::Bold);

    sf::Text Warnings2;
    Warnings2.setFont(arial);
    Warnings2.setCharacterSize(20);
    Warnings2.setString("It is empty!");
    Warnings2.sf::Text::setFillColor(sf::Color::Cyan);
    Warnings2.setPosition({ 500, 50 });
    Warnings2.setStyle(sf::Text::Bold);

    Button btnHome("Home", { 100, 50 }, 15, sf::Color::Cyan, TextColor, OutColor, 5);
    btnHome.setPos({ 1200, 0 });
    btnHome.setFont(arial);

    Circular Example;
    Set(Example, Initialize());

    int Type = 0;
    int Done = 0;

    while (window.isOpen())
    {

        while (window.pollEvent(Events))
        {
            if (Done != 0)
            {
                const char* Path = nullptr;
                switch (Done)
                {
                case 1:
                    Type = 0;
                    Done = 0;
                    Path = FindPath();
                    if (Path != nullptr) Set(Example, ReadFromFile(Path));
                    break;

                case 2:
                    Type = 0;
                    Done = 0;
                    Set(Example, Initialize());
                    break;

                case 3:
                    if (Example.isFull())
                    {
                        Type = 1;
                        Done = 0;
                    }
                    else
                    {
                        Type = 0;
                        Done = 3;
                        std::string X = GetData(Events, window, btn, 10, 3, Done);
                        if (Done != 0) break;
                        AddFirst(Example, X);
                    }
                    break;

                case 4:
                    if (Example.isFull())
                    {
                        Type = 1;
                        Done = 0;
                    }
                    else
                    {
                        Type = 0;
                        Done = 4;
                        std::string X = GetData(Events, window, btn, 10, 4, Done);
                        if (Done != 0) break;
                        AddLast(Example, X);
                    }
                    break;

                case 5:
                    if (Example.isFull())
                    {
                        Type = 1;
                        Done = 0;
                    }
                    else
                    {
                        Type = 0;
                        Done = 5;
                        std::string X = GetData(Events, window, btn, 10, 5, Done);
                        if (Done != 0) break;
                        AddMiddle(Example, X);
                    }
                    break;

                case 6:
                    if (Example.isEmpty())
                    {
                        Type = 2;
                        Done = 0;
                    }
                    else
                    {
                        Type = 0;
                        DeleteFirst(Example);
                        Done = 0;
                    }
                    break;

                case 7:
                    if (Example.isEmpty())
                    {
                        Type = 2;
                        Done = 0;
                    }
                    else
                    {
                        Type = 0;
                        DeleteLast(Example);
                        Done = 0;
                    }
                    break;

                case 8:
                    if (Example.isEmpty())
                    {
                        Type = 2;
                        Done = 0;
                    }
                    else
                    {
                        Type = 0;
                        DeleteMiddle(Example);
                        Done = 0;
                    }
                    break;

                case 9:
                    if (Example.isEmpty())
                    {
                        Type = 2;
                        Done = 0;
                    }
                    else
                    {
                        Type = 0;
                        Done = 9;
                        std::string X = GetData(Events, window, btn, 10, 9, Done);
                        if (Done != 0) break;
                        Done = 9;
                        int Y = GetLocation(Events, window, btn, 10, 9, Example.GetSize() - 1, Done);
                        if (Done != 0) break;
                        Update(Example, X, Y);
                    }
                    break;

                case 10:
                    if (Example.isEmpty())
                    {
                        Type = 2;
                        Done = 0;
                    }
                    else
                    {
                        Type = 0;
                        Done = 5;
                        std::string X = GetData(Events, window, btn, 10, 10, Done);
                        if (Done != 0) break;
                        Search(Example, X);
                    }
                    break;

                case -1:
                    return;
                }
            }
            else
            {
                switch (Events.type)
                {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::MouseButtonPressed:
                    if (btnHome.isMouseOver(window))
                    {
                        return;
                    }
                    else
                    {
                        for (int i = 0; i < 10; i++)
                            if (btn[i].isMouseOver(window))
                            {
                                Done = i + 1;
                                break;
                            }
                    }
                }
            }
        }

        if (btnHome.isMouseOver(window))
        {
            btnHome.setBackColor(sf::Color::White);
        }
        else
        {
            btnHome.setBackColor(sf::Color::Cyan);
            for (int i = 0; i < 10; i++)
                if (btn[i].isMouseOver(window))
                    btn[i].setBackColor(sf::Color::White);
                else btn[i].setBackColor(BoxColor);
        }

        window.clear(ScreenColor);

        btnHome.drawto(window);
        PrintArrow(Example.GetSize(), window);
        Example.Print();

        for (int i = 0; i < 10; i++)
            btn[i].drawto(window);

        if (Type == 1) window.draw(Warnings1);
        else if (Type == 2) window.draw(Warnings2);

        window.display();

    }
}