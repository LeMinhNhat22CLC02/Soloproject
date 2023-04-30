#include<iostream>
#include<SFML/Graphics.hpp>
#include"Singly.h"
#include"Buttons.h"
#include"TextBox.h"
#include"InputData.h"

Singly::Singly() : head(nullptr), size(0) {}

Singly::~Singly()
{
    Node* temp;
    while (head != nullptr)
    {
        temp = head->next;
        delete head;
        head = temp;
    }
}

void Singly::Set(std::vector<std::string> X)
{
    size = (int)X.size();
    head = new Node;
    head->data = X[0];
    Node* current = head;
    for (int i = 1; i < size; i++) {
        current->next = new Node;
        current = current->next;
        current->data = X[i];
    }
    current->next = nullptr;
}

void Singly::AddFirst(std::string X)
{
    Node* temp = new Node;
    temp->data = X;
    temp->next = head;
    head = temp;
    size++;
}

void Singly::AddLast(std::string X)
{
    if (size == 0)
    {
        AddFirst(X);
        return;
    }
    Node* temp = head;
    int Location = size - 1;
    while (Location--)
    {
        temp = temp->next;
    }
    Node* Temp = new Node;
    Temp->data = X;
    Temp->next = temp->next;
    temp->next = Temp;
    size++;
}

void Singly::AddMiddle(std::string X)
{
    if (size == 0)
    {
        AddFirst(X);
        return;
    }
    Node* temp = head;
    int Location = size/2 - 1;
    while (Location--)
    {
        temp = temp->next;
    }
    Node* Temp = new Node;
    Temp->data = X;
    Temp->next = temp->next;
    temp->next = Temp;
    size++;
}

void Singly::DeleteFirst()
{
    head = head->next;
    size--;
}

void Singly::DeleteLast()
{
    if (size == 1)
    {
        DeleteFirst();
        return;
    }
    int Location = std::max(0, size - 2);
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

void Singly::DeleteMiddle()
{
    if (size == 1)
    {
        DeleteFirst();
        return;
    }
    int Location = std::max(0, size / 2 - 1);
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

void Singly::Update(std::string X, int Location)
{
    Node* temp = head;
    while (Location--)
    {
        temp = temp->next;
    }
    temp->data = X;
    return;
}

void Singly::Search(std::string X)
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

int Singly::GetSize()
{
    return size;
}

bool Singly::isFull()
{
    return size == 7;
}

bool Singly::isEmpty()
{
    return size == 0;
}

void Singly::Print()
{
    Node* Temp = head;
    while (Temp != nullptr)
    {
        std::cout << Temp->data << " ";
        Temp = Temp->next;
    }
    std::cout << std::endl;
}

void Set(Singly& X, std::vector<std::string> Y)
{
    X.Set(Y);
}

void AddFirst(Singly& X, std::string Y)
{
    X.AddFirst(Y);
}

void AddLast(Singly& X, std::string Y)
{
    X.AddLast(Y);
}

void AddMiddle(Singly& X, std::string Y)
{
    X.AddMiddle(Y);
}

void DeleteFirst(Singly& X)
{
    X.DeleteFirst();
}

void DeleteLast(Singly& X)
{
    X.DeleteLast();
}

void DeleteMiddle(Singly& X)
{
    X.DeleteMiddle();
}

void Update(Singly& X, std::string Y, int Z)
{
    X.Update(Y, Z);
}
void Search(Singly& X, std::string Y)
{
    X.Search(Y);
}

void SinglyClient(sf::Event Events, sf::RenderWindow& window)
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

    Button btnHome("Home", { 100, 100 }, 15, sf::Color::Cyan, TextColor, OutColor, 5);
    btnHome.setPos({ 1200, 0 });
    btnHome.setFont(arial);

    Singly Example;
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

        Example.Print();
        std::cout << Example.GetSize() << "\n";

        for (int i = 0; i < 10; i++)
            btn[i].drawto(window);

        if (Type == 1) window.draw(Warnings1);
        else if (Type == 2) window.draw(Warnings2);

        window.display();

    }
}