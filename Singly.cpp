#include<iostream>
#include<SFML/Graphics.hpp>
#include"Singly.h"
#include"Buttons.h"
#include"TextBox.h"
#include"InputData.h"
#include"Objects.h"

#define ENTER_KEY 13

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
    if (size == 1)
    {
        AddLast(X);
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

void Singly::DeleteMiddle()
{
    if (size == 1)
    {
        DeleteFirst();
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

int Singly::Search(std::string X)
{
    Node* temp = head;
    int count = 0;
    while (temp != nullptr)
    {
        if (temp->data == X) return count;
        count++;
        temp = temp->next;
    }
    return -1;
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

void Singly::Print(sf::RenderWindow& window, int Nprint)
{
    sf::Font arial;
    arial.loadFromFile("arial.ttf");

    sf::Color TextColor(64, 140, 124);

    sf::Text Data;
    Data.setFont(arial);
    Data.setCharacterSize(15);
    Data.sf::Text::setFillColor(TextColor);
    Data.setStyle(sf::Text::Bold);

    int i = 0;
    Node* Temp = head;
    while (Temp != nullptr)
    {
        Data.setString(Temp->data);

        if (i >= Nprint) Data.setPosition({ (float)390 + i * (150), 292.5 });
        else Data.setPosition({ (float)240 + i * (150), 292.5 });

        window.draw(Data);
        i++;
        Temp = Temp->next;
    }
}


void Singly::ScreenAdd(sf::RenderWindow& window, Button btn[], Button btnHome, std::string X, int Choosen)
{
    if (size == 0) return;
    sf::Font arial;
    arial.loadFromFile("arial.ttf");

    sf::Color ScreenColor(238, 137, 128);
    sf::Color TextColor(64, 140, 124);
    sf::Color OutColor(241, 70, 102);
    sf::Color BoxColor(255, 220, 195);

    sf::Text Data;
    Data.setFont(arial);
    Data.setCharacterSize(15);
    Data.sf::Text::setFillColor(TextColor);
    Data.setStyle(sf::Text::Bold);
    Data.setString(X);
    Data.setPosition({(float) 240 + Choosen * 150, 112.5 });

    sf::CircleShape Box(50.f);
    Box.setFillColor(BoxColor);
    Box.setFillColor(BoxColor);
    Box.setOutlineThickness(3);
    Box.setOutlineColor(OutColor);
    Box.setPosition({(float) 225 + Choosen * 150, 70 });

    sf::Text Tail;
    Tail.setFont(arial);
    Tail.setCharacterSize(20);
    Tail.setString("Tail/");
    Tail.sf::Text::setFillColor(sf::Color::Cyan);
    Tail.setStyle(sf::Text::Bold);

    sf::Text Head;
    Head.setFont(arial);
    Head.setCharacterSize(20);
    Head.setPosition({ 240, 372.5 });
    Head.sf::Text::setFillColor(sf::Color::Cyan);
    Head.setStyle(sf::Text::Bold);

    window.clear(ScreenColor);

    btnHome.drawto(window);
    for (int i = 0; i < 10; i++)
        btn[i].drawto(window);
    PrintArrow(size - 1, window);
    PrintBox(size, window);
    Print(window, 8);
    if (size == 1)
    {
        Head.setString("Head/Tail/");
        Head.setPosition({ 225, 372.5 });
        window.draw(Head);
    }
    else
    {
        Tail.setPosition({ (float)240 + (size - 1) * 150, 372.5 });
        Head.setPosition({ 240, 372.5 });
        Head.setString("Head/");
        window.draw(Head);
        window.draw(Tail);
    }

    window.display();
    sf::sleep(sf::seconds(1));

    window.clear(ScreenColor);

    btnHome.drawto(window);
    for (int i = 0; i < 10; i++)
        btn[i].drawto(window);
    PrintArrow(size - 1, window);
    PrintBox(size, window);
    Print(window, 8);
    if (size != 1) window.draw(Tail);
    window.draw(Head);
    window.draw(Box);
    window.draw(Data);

    window.display();
    sf::sleep(sf::seconds(1));

    window.clear(ScreenColor);

    btnHome.drawto(window);
    for (int i = 0; i < 10; i++)
        btn[i].drawto(window);
    PrintArrow(size - 1, Choosen - 1, 8, window);
    PrintBox(size, window);
    Print(window, 8);
    ArrowPointAt(Choosen, window);
    if (Choosen != 0) ArrowPoint(Choosen, window);
    if (size > 1) window.draw(Tail);
    window.draw(Head);
    window.draw(Box);
    window.draw(Data);

    window.display();
    sf::sleep(sf::seconds(1));
}

void Singly::ScreenAddForLast(sf::RenderWindow& window, Button btn[], Button btnHome, std::string X)
{
    if (size == 0) return;
    sf::Font arial;
    arial.loadFromFile("arial.ttf");

    sf::Color ScreenColor(238, 137, 128);
    sf::Color TextColor(64, 140, 124);
    sf::Color OutColor(241, 70, 102);
    sf::Color BoxColor(255, 220, 195);

    sf::Text Data;
    Data.setFont(arial);
    Data.setCharacterSize(15);
    Data.sf::Text::setFillColor(TextColor);
    Data.setStyle(sf::Text::Bold);
    Data.setString(X);
    Data.setPosition({ (float)90 + size * 150, 112.5 });

    sf::CircleShape Box(50.f);
    Box.setFillColor(BoxColor);
    Box.setFillColor(BoxColor);
    Box.setOutlineThickness(3);
    Box.setOutlineColor(OutColor);
    Box.setPosition({ (float)75 + size * 150, 70 });

    sf::Text Tail;
    Tail.setFont(arial);
    Tail.setCharacterSize(20);
    Tail.setString("Tail/");
    Tail.sf::Text::setFillColor(sf::Color::Cyan);
    Tail.setStyle(sf::Text::Bold);

    sf::Text Head;
    Head.setFont(arial);
    Head.setCharacterSize(20);
    Head.setPosition({ 240, 372.5 });
    Head.sf::Text::setFillColor(sf::Color::Cyan);
    Head.setStyle(sf::Text::Bold);

    window.clear(ScreenColor);

    btnHome.drawto(window);
    for (int i = 0; i < 10; i++)
        btn[i].drawto(window);
    PrintArrow(size - 1, window);
    PrintBox(size, window);
    Print(window, 8);
    if (size == 1)
    {
        Head.setString("Head/Tail/");
        Head.setPosition({ 225, 372.5 });
        window.draw(Head);
    }
    else
    {
        Tail.setPosition({ (float)240 + (size - 1) * 150, 372.5 });
        Head.setPosition({ 240, 372.5 });
        Head.setString("Head/");
        window.draw(Head);
        window.draw(Tail);
    }

    window.display();
    sf::sleep(sf::seconds(1));

    window.clear(ScreenColor);

    btnHome.drawto(window);
    for (int i = 0; i < 10; i++)
        btn[i].drawto(window);
    PrintArrow(size - 1, window);
    PrintBox(size, window);
    Print(window, 8);
    if (size != 1) window.draw(Tail);
    window.draw(Head);
    window.draw(Box);
    window.draw(Data);

    window.display();
    sf::sleep(sf::seconds(1));

    window.clear(ScreenColor);

    btnHome.drawto(window);
    for (int i = 0; i < 10; i++)
        btn[i].drawto(window);
    PrintArrow(size - 1, size - 1, 8, window);
    PrintBox(size, window);
    Print(window, 8);
    ArrowPointUpAt(size - 1, window);
    if (size > 1) window.draw(Tail);
    window.draw(Head);
    window.draw(Box);
    window.draw(Data);

    window.display();
    sf::sleep(sf::seconds(1));
}

void Singly::BeforeDelete(sf::RenderWindow& window, Button btn[], Button btnHome, int Choosen)
{
    if (size == 1) return;

    sf::Font arial;
    arial.loadFromFile("arial.ttf");

    sf::Text Head;
    Head.setFont(arial);
    Head.setCharacterSize(20);
    Head.setPosition({ 240, 372.5 });
    Head.sf::Text::setFillColor(sf::Color::Cyan);
    Head.setStyle(sf::Text::Bold);

    PrintBox(size, window);
    PrintArrow(size - 1, Choosen, Choosen - 1, window);
    Print(window, 8);

    btnHome.drawto(window);
    for (int i = 0; i < 10; i++)
        btn[i].drawto(window);

    if (size == 1)
    {
        Head.setString("Head/Tail/");
        Head.setPosition({ 225, 372.5 });
        window.draw(Head);
    }
    else
    {
        sf::Text Tail;
        Tail.setFont(arial);
        Tail.setCharacterSize(20);
        Tail.setString("Tail/");
        Tail.sf::Text::setFillColor(sf::Color::Cyan);
        Tail.setStyle(sf::Text::Bold);
        Tail.setPosition({ (float)240 + (size - 1) * 150, 372.5 });

        Head.setPosition({ 240, 372.5 });
        Head.setString("Head/");
        window.draw(Head);
        window.draw(Tail);
    }

    window.display();
    sf::sleep(sf::seconds(1));
}

void Singly::AfterDelete(sf::RenderWindow& window, Button btn[], Button btnHome, int Choosen)
{
    if (size == 0) return;
    sf::Font arial;
    arial.loadFromFile("arial.ttf");

    sf::Text Head;
    Head.setFont(arial);
    Head.setCharacterSize(20);
    Head.setPosition({ 240, 372.5 });
    Head.sf::Text::setFillColor(sf::Color::Cyan);
    Head.setStyle(sf::Text::Bold);

    if (size == 1)
    {
        btnHome.drawto(window);

        Head.setString("Head/Tail/");
        Head.setPosition({(float)375 - Choosen * 150, 372.5 });
        window.draw(Head);

        PrintBox(2, Choosen, window);
        Print(window, Choosen);

        for (int j = 0; j < 10; j++)
            btn[j].drawto(window);

        window.display();
        sf::sleep(sf::seconds(1));
        return;
    }

    PrintBox(size + 1, Choosen, window); 
    if (0 < Choosen) PrintArrow(size, Choosen, Choosen - 1, window);
    else PrintArrow(size, Choosen, 8, window);
    Print(window, Choosen);

    sf::Text Tail;
    Tail.setFont(arial);
    Tail.setCharacterSize(20);
    Tail.setString("Tail/");
    Tail.sf::Text::setFillColor(sf::Color::Cyan);
    Tail.setStyle(sf::Text::Bold);
    Tail.setPosition({ (float)240 + size * 150, 372.5 });
    Head.setPosition({ (float)240 + (Choosen == 0) * 150, 372.5});
    Head.setString("Head/");
    window.draw(Head);
    window.draw(Tail);

    btnHome.drawto(window);
    for (int j = 0; j < 10; j++)
        btn[j].drawto(window);

    window.display();
    sf::sleep(sf::seconds(1));
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

int Search(Singly& X, std::string Y)
{
    return X.Search(Y);
}

std::string GetData(sf::Event Events, sf::RenderWindow& window, Button btn[], int Nbtn, int X, int& Done, Singly& Example)
{
    X--;

    sf::Font arial;
    arial.loadFromFile("arial.ttf");

    sf::Color ScreenColor(238, 137, 128);
    sf::Color OutColor(241, 70, 102);
    sf::Color BoxColor(255, 220, 195);
    sf::Color TextColor(64, 140, 124);

    sf::Text Note1;
    Note1.setFont(arial);
    Note1.setCharacterSize(20);
    Note1.setString("Input your data then press enter key!");
    Note1.sf::Text::setFillColor(sf::Color::Cyan);
    Note1.setPosition({ 500, 50 });
    Note1.setStyle(sf::Text::Bold);

    Textbox Textbox1(15, TextColor, true);
    Textbox1.setFont(arial);
    Textbox1.setLimit(false);
    Textbox1.setPosition(btn[X].getPosition());

    sf::RectangleShape Box;
    Box.setSize({ 160, 40 });
    Box.setFillColor(BoxColor);
    Box.setPosition(btn[X].getPosition());
    Box.setOutlineThickness(3);
    Box.setOutlineColor(OutColor);

    sf::Text Tail;
    Tail.setFont(arial);
    Tail.setCharacterSize(20);
    Tail.setString("Tail/");
    Tail.sf::Text::setFillColor(sf::Color::Cyan);
    Tail.setStyle(sf::Text::Bold);

    sf::Text Head;
    Head.setFont(arial);
    Head.setCharacterSize(20);
    Head.setPosition({ 240, 372.5 });
    Head.sf::Text::setFillColor(sf::Color::Cyan);
    Head.setStyle(sf::Text::Bold);

    Button btnHome("Home", { 100, 50 }, 15, sf::Color::Cyan, TextColor, OutColor, 5);
    btnHome.setPos({ 1200, 0 });
    btnHome.setFont(arial);

    while (window.isOpen())
    {
        while (window.pollEvent(Events))
        {
            switch (Events.type)
            {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::MouseButtonPressed:
                if (btnHome.isMouseOver(window))
                {
                    Done = -1;
                    return "";
                }
                else
                {
                    for (int i = 0; i < Nbtn; i++)
                        if (btn[i].isMouseOver(window))
                        {
                            Done = i + 1;
                            return "";
                        }
                }
                break;

            case sf::Event::TextEntered:
                Done = 0;
                if (Events.text.unicode == ENTER_KEY) return Textbox1.getText();
                Textbox1.typeOn(Events);
                break;
            }
        }

        if (btnHome.isMouseOver(window))
        {
            btnHome.setBackColor(sf::Color::White);
        }
        else
        {
            btnHome.setBackColor(sf::Color::Cyan);
            for (int i = 0; i < Nbtn; i++)
                if (btn[i].isMouseOver(window))
                    btn[i].setBackColor(sf::Color::White);
                else btn[i].setBackColor(BoxColor);
        }

        window.clear(ScreenColor);

        for (int i = 0; i < Nbtn; i++)
            btn[i].drawto(window);
        btnHome.drawto(window);
        window.draw(Box);
        Textbox1.drawto(window);
        window.draw(Note1);

        PrintBox(Example.GetSize(), window);
        PrintArrow(Example.GetSize() - 1, window);
        Example.Print(window, 8);

        if (Example.GetSize() > 0)
        {
            if (Example.GetSize() == 1)
            {
                Head.setString("Head/Tail/");
                Head.setPosition({ 225, 372.5 });
                window.draw(Head);
            }
            else
            {
                Tail.setPosition({ (float)240 + (Example.GetSize() - 1) * 150, 372.5 });
                Head.setPosition({ 240, 372.5 });
                Head.setString("Head/");
                window.draw(Head);
                window.draw(Tail);
            }
        }

        window.display();
    }
    Done = 0;
    return "";
}

int GetLocation(sf::Event Events, sf::RenderWindow& window, Button btn[], int Nbtn, int X, int Datasize, int& Done, Singly& Example)
{
    X--;

    sf::Font arial;
    arial.loadFromFile("arial.ttf");

    sf::Color ScreenColor(238, 137, 128);
    sf::Color OutColor(241, 70, 102);
    sf::Color BoxColor(255, 220, 195);
    sf::Color TextColor(64, 140, 124);

    sf::Text Note1;
    Note1.setFont(arial);
    Note1.setCharacterSize(20);
    Note1.setString("Input the location then press enter key!");
    Note1.sf::Text::setFillColor(sf::Color::Cyan);
    Note1.setPosition({ 500, 50 });
    Note1.setStyle(sf::Text::Bold);

    sf::Text Warnings1;
    Warnings1.setFont(arial);
    Warnings1.setCharacterSize(20);
    Warnings1.setString("Location exceed size. Please re-enter!");
    Warnings1.sf::Text::setFillColor(sf::Color::Cyan);
    Warnings1.setPosition({ 500, 50 });
    Warnings1.setStyle(sf::Text::Bold);

    sf::Text Warnings2;
    Warnings2.setFont(arial);
    Warnings2.setCharacterSize(20);
    Warnings2.setString("The location must be a positive number. Please re - enter!");
    Warnings2.sf::Text::setFillColor(sf::Color::Cyan);
    Warnings2.setPosition({ 500, 50 });
    Warnings2.setStyle(sf::Text::Bold);

    Textbox Textbox1(15, TextColor, true);
    Textbox1.setFont(arial);
    Textbox1.setLimit(false);
    Textbox1.setPosition(btn[X].getPosition());

    sf::RectangleShape Box;
    Box.setSize({ 160, 40 });
    Box.setFillColor(BoxColor);
    Box.setOutlineThickness(3);
    Box.setOutlineColor(OutColor);
    Box.setPosition(btn[X].getPosition());

    sf::Text Tail;
    Tail.setFont(arial);
    Tail.setCharacterSize(20);
    Tail.setString("Tail/");
    Tail.sf::Text::setFillColor(sf::Color::Cyan);
    Tail.setStyle(sf::Text::Bold);

    sf::Text Head;
    Head.setFont(arial);
    Head.setCharacterSize(20);
    Head.setPosition({ 240, 372.5 });
    Head.sf::Text::setFillColor(sf::Color::Cyan);
    Head.setStyle(sf::Text::Bold);

    Button btnHome("Home", { 100, 50 }, 15, sf::Color::Cyan, TextColor, OutColor, 5);
    btnHome.setPos({ 1200, 0 });
    btnHome.setFont(arial);

    int Type = 0;

    while (window.isOpen())
    {
        while (window.pollEvent(Events))
        {
            switch (Events.type)
            {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::MouseButtonPressed:
                if (btnHome.isMouseOver(window))
                {
                    Done = -1;
                    return 0;
                }
                else
                {
                    for (int i = 0; i < Nbtn; i++)
                        if (btn[i].isMouseOver(window))
                        {
                            Done = i + 1;
                            return 0;
                        }
                }
                break;

            case sf::Event::TextEntered:
                if (Events.text.unicode == ENTER_KEY)
                {
                    Done = 0;
                    Type = WhatType(Textbox1.getText(), Datasize);
                    if (Type == 0) return std::stoi(Textbox1.getText());
                    Textbox1.Clear();
                }
                Textbox1.typeOn(Events);
                break;
            }
        }

        if (btnHome.isMouseOver(window))
        {
            btnHome.setBackColor(sf::Color::White);
        }
        else
        {
            btnHome.setBackColor(sf::Color::Cyan);
            for (int i = 0; i < Nbtn; i++)
                if (btn[i].isMouseOver(window))
                    btn[i].setBackColor(sf::Color::White);
                else btn[i].setBackColor(BoxColor);
        }

        window.clear(ScreenColor);

        for (int i = 0; i < Nbtn; i++)
            btn[i].drawto(window);
        btnHome.drawto(window);
        window.draw(Box);
        Textbox1.drawto(window);
        if (Type == 0) window.draw(Note1);
        else if (Type == 1) window.draw(Warnings1);
        else window.draw(Warnings2);

        PrintBox(Example.GetSize(), window);
        PrintArrow(Example.GetSize() - 1, window);
        Example.Print(window, 8);

        if (Example.GetSize() > 0)
        {
            if (Example.GetSize() == 1)
            {
                Head.setString("Head/Tail/");
                Head.setPosition({ 225, 372.5 });
                window.draw(Head);
            }
            else
            {
                Tail.setPosition({ (float)240 + (Example.GetSize() - 1) * 150, 372.5 });
                Head.setPosition({ 240, 372.5 });
                Head.setString("Head/");
                window.draw(Head);
                window.draw(Tail);
            }
        }

        window.display();
    }
    Done = 0;
    return 0;
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

    sf::Text Tail;
    Tail.setFont(arial);
    Tail.setCharacterSize(20);
    Tail.setString("Tail/");
    Tail.sf::Text::setFillColor(sf::Color::Cyan);
    Tail.setStyle(sf::Text::Bold);

    sf::Text Head;
    Head.setFont(arial);
    Head.setCharacterSize(20);
    Head.setPosition({ 240, 372.5 });
    Head.sf::Text::setFillColor(sf::Color::Cyan);
    Head.setStyle(sf::Text::Bold);
    
    sf::Text Answer;
    Answer.setFont(arial);
    Answer.setCharacterSize(20);
    Answer.setString("");
    Answer.sf::Text::setFillColor(sf::Color::Cyan);
    Answer.setPosition({ 500, 50 });
    Answer.setStyle(sf::Text::Bold);

    Button btnHome("Home", { 100, 50 }, 15, sf::Color::Cyan, TextColor, OutColor, 5);
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
                        std::string X = GetData(Events, window, btn, 10, 3, Done, Example);
                        if (Done != 0) break;
                        Example.ScreenAdd(window, btn, btnHome, X, 0);
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
                        std::string X = GetData(Events, window, btn, 10, 4, Done, Example);
                        if (Done != 0) break;
                        Example.ScreenAddForLast(window, btn, btnHome, X);
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
                        std::string X = GetData(Events, window, btn, 10, 5, Done, Example);
                        if (Done != 0) break;
                        Example.ScreenAdd(window, btn, btnHome, X, Example.GetSize() / 2);
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
                        Done = 0;
                        Type = 0;
                        window.clear(ScreenColor);
                        Example.BeforeDelete(window, btn, btnHome, 0);
                        DeleteFirst(Example);
                        window.clear(ScreenColor);
                        Example.AfterDelete(window, btn, btnHome, 0);
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
                        Done = 0;
                        Type = 0;
                        window.clear(ScreenColor);
                        Example.BeforeDelete(window, btn, btnHome, Example.GetSize() - 1);
                        DeleteLast(Example);
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
                        Done = 0;
                        Type = 0;
                        window.clear(ScreenColor);
                        Example.BeforeDelete(window, btn, btnHome, Example.GetSize() / 2);
                        DeleteMiddle(Example);
                        window.clear(ScreenColor);
                        Example.AfterDelete(window, btn, btnHome, (Example.GetSize() + 1) / 2);
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
                        std::string X = GetData(Events, window, btn, 10, 9, Done, Example);
                        if (Done != 0) break;
                        Done = 9;
                        int Y = GetLocation(Events, window, btn, 10, 9, Example.GetSize() - 1, Done, Example);
                        if (Done != 0) break; 
                        for (int i = 0; i <= Y; i++)
                        {
                            window.clear(ScreenColor);

                            btnHome.drawto(window);

                            PrintBox(Example.GetSize(), window);
                            PrintArrow(Example.GetSize() - 1, window);
                            Example.Print(window, 8);

                            if (Example.GetSize() > 0)
                            {
                                if (Example.GetSize() == 1)
                                {
                                    Head.setString("Head/Tail/");
                                    Head.setPosition({ 225, 372.5 });
                                    window.draw(Head);
                                }
                                else
                                {
                                    Tail.setPosition({ (float)240 + (Example.GetSize() - 1) * 150, 372.5 });
                                    Head.setPosition({ 240, 372.5 });
                                    Head.setString("Head/");
                                    window.draw(Head);
                                    window.draw(Tail);
                                }
                            }

                            for (int j = 0; j < 10; j++)
                                btn[j].drawto(window);
                            ArrowPointAt(i, window);
                            window.display();
                            sf::sleep(sf::seconds(1));
                        }
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
                        std::string X = GetData(Events, window, btn, 10, 10, Done, Example);
                        if (Done != 0) break;
                        int Y = Search(Example, X);
                        if (Y == -1)
                        {
                            for (int i = 0; i < Example.GetSize(); i++)
                            {
                                window.clear(ScreenColor);

                                btnHome.drawto(window);

                                PrintBox(Example.GetSize(), window);
                                PrintArrow(Example.GetSize() - 1, window);
                                Example.Print(window, 8);

                                if (Example.GetSize() > 0)
                                {
                                    if (Example.GetSize() == 1)
                                    {
                                        Head.setString("Head/Tail/");
                                        Head.setPosition({ 225, 372.5 });
                                        window.draw(Head);
                                    }
                                    else
                                    {
                                        Tail.setPosition({ (float)240 + (Example.GetSize() - 1) * 150, 372.5 });
                                        Head.setPosition({ 240, 372.5 });
                                        Head.setString("Head/");
                                        window.draw(Head);
                                        window.draw(Tail);
                                    }
                                }

                                for (int j = 0; j < 10; j++)
                                    btn[j].drawto(window);
                                ArrowPointAt(i, window);
                                window.display();
                                sf::sleep(sf::seconds(1));
                            }
                        }
                        else
                        {
                            for (int i = 0; i <= Y; i++)
                            {
                                window.clear(ScreenColor);

                                btnHome.drawto(window);

                                PrintBox(Example.GetSize(), window);
                                PrintArrow(Example.GetSize() - 1, window);
                                Example.Print(window, 8);

                                if (Example.GetSize() > 0)
                                {
                                    if (Example.GetSize() == 1)
                                    {
                                        Head.setString("Head/Tail/");
                                        Head.setPosition({ 225, 372.5 });
                                        window.draw(Head);
                                    }
                                    else
                                    {
                                        Tail.setPosition({ (float)240 + (Example.GetSize() - 1) * 150, 372.5 });
                                        Head.setPosition({ 240, 372.5 });
                                        Head.setString("Head/");
                                        window.draw(Head);
                                        window.draw(Tail);
                                    }
                                }

                                for (int j = 0; j < 10; j++)
                                    btn[j].drawto(window);
                                ArrowPointAt(i, window);
                                window.display();
                                sf::sleep(sf::seconds(1));
                            }
                        }
                        if (Y == -1) Answer.setString("Can't find " + X);
                        else Answer.setString(X + " at " + std::to_string(Y));
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
                            Answer.setString("");
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
        
        PrintBox(Example.GetSize(), window);
        PrintArrow(Example.GetSize() - 1, window);
        Example.Print(window, 8);

        if (Example.GetSize() > 0)
        {
            if (Example.GetSize() == 1)
            {
                Head.setString("Head/Tail/");
                Head.setPosition({ 225, 372.5 });
                window.draw(Head);
            }
            else
            {
                Tail.setPosition({ (float)240 + (Example.GetSize() - 1) * 150, 372.5 });
                Head.setPosition({ 240, 372.5 });
                Head.setString("Head/");
                window.draw(Head);
                window.draw(Tail);
            }
        }

        for (int i = 0; i < 10; i++)
            btn[i].drawto(window);

        window.draw(Answer);
        if (Type == 1) window.draw(Warnings1);
        else if (Type == 2) window.draw(Warnings2);

        window.display();
    }
}