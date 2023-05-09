#include<iostream>
#include<SFML/Graphics.hpp>
#include"Singly.h"
#include"Buttons.h"
#include"TextBox.h"
#include"InputData.h"
#include"Objects.h"

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

void Singly::AddFirst(std::string X, sf::RenderWindow& window)
{
    PrintArrow(size - 1, window);
    PrintBox(size, window);
    Print(window, 8);
    window.display();

    sf::Font arial;
    arial.loadFromFile("arial.ttf");

    sf::Color TextColor(64, 140, 124);
    sf::Color OutColor(241, 70, 102);
    sf::Color BoxColor(255, 220, 195);

    sf::Text Data;
    Data.setFont(arial);
    Data.setCharacterSize(15);
    Data.sf::Text::setFillColor(TextColor);
    Data.setStyle(sf::Text::Bold);
    Data.setString(X);
    Data.setPosition({ 240, 112.5 });

    sf::CircleShape Box(50.f);
    Box.setFillColor(BoxColor);
    Box.setFillColor(BoxColor);
    Box.setOutlineThickness(3);
    Box.setOutlineColor(OutColor);
    Box.setPosition({ 225 , 70 });

    sf::Text Head;
    Head.setFont(arial);
    Head.setCharacterSize(20);
    Head.setString("Head/");
    Head.sf::Text::setFillColor(sf::Color::Cyan);
    Head.setStyle(sf::Text::Bold);

    sf::Text Tail;
    Tail.setFont(arial);
    Tail.setCharacterSize(20);
    Tail.setPosition({ 240, 372.5 });
    Tail.sf::Text::setFillColor(sf::Color::Cyan);
    Tail.setStyle(sf::Text::Bold);

    if (size > 0)
    {
        if (size == 1)
        {
            Tail.setString("Tail/Head/");
            Tail.setPosition({ 225, 372.5 });
            window.draw(Tail);
        }
        else
        {
            Head.setPosition({ (float)240 + (size - 1) * 150, 372.5 });
            Tail.setPosition({ 240, 372.5 });
            Tail.setString("Tail/");
            window.draw(Head);
            window.draw(Tail);
        }
    }
    PrintArrow(size - 1, window);
    PrintBox(size, window);
    Print(window, 8);
    window.draw(Box);
    window.draw(Data);

    window.display();
    sf::sleep(sf::seconds(1));

    PrintArrow(size - 1, window);
    PrintBox(size, window);
    Print(window, 8);
    window.draw(Box);
    window.draw(Data);
    ArrowPointAt(0, window);
    if (size > 1) window.draw(Head);
    window.draw(Tail);

    window.display();
    sf::sleep(sf::seconds(1));

    Node* temp = new Node;
    temp->data = X;
    temp->next = head;
    head = temp;
    size++;
}

void Singly::AddLast(std::string X, sf::RenderWindow& window)
{
    if (size == 0)
    {
        AddFirst(X, window);
        return;
    }
    sf::Font arial;
    arial.loadFromFile("arial.ttf");

    sf::Color TextColor(64, 140, 124);
    sf::Color OutColor(241, 70, 102);
    sf::Color BoxColor(255, 220, 195);

    sf::Text Data;
    Data.setFont(arial);
    Data.setCharacterSize(15);
    Data.sf::Text::setFillColor(TextColor);
    Data.setStyle(sf::Text::Bold);
    Data.setString(X);
    Data.setPosition({ (float)240 + 150 * (size - 1), 112.5 });

    sf::CircleShape Box(50.f);
    Box.setFillColor(BoxColor);
    Box.setFillColor(BoxColor);
    Box.setOutlineThickness(3);
    Box.setOutlineColor(OutColor);
    Box.setPosition({ (float)225 + 150 * (size - 1), 70 });

    sf::Text Head;
    Head.setFont(arial);
    Head.setCharacterSize(20);
    Head.setString("Head/");
    Head.sf::Text::setFillColor(sf::Color::Cyan);
    Head.setStyle(sf::Text::Bold);

    sf::Text Tail;
    Tail.setFont(arial);
    Tail.setCharacterSize(20);
    Tail.setPosition({ 240, 372.5 });
    Tail.sf::Text::setFillColor(sf::Color::Cyan);
    Tail.setStyle(sf::Text::Bold);

    if (size > 0)
    {
        if (size == 1)
        {
            Tail.setString("Tail/Head/");
            Tail.setPosition({ 225, 372.5 });
            window.draw(Tail);
        }
        else
        {
            Head.setPosition({ (float)240 + (size - 1) * 150, 372.5 });
            Tail.setPosition({ 240, 372.5 });
            Tail.setString("Tail/");
            window.draw(Head);
            window.draw(Tail);
        }
    }
    PrintArrow(size - 1, window);
    PrintBox(size, window);
    Print(window, 8);
    window.draw(Box);
    window.draw(Data);

    window.display();
    sf::sleep(sf::seconds(1));

    PrintArrow(size - 2, window);
    PrintBox(size, window);
    Print(window, 8);
    window.draw(Box);
    window.draw(Data);
    ArrowPointAt(size - 1, window);
    ArrowPoint(size - 1, window);
    if (size > 1) window.draw(Head);
    window.draw(Tail);

    window.display();
    sf::sleep(sf::seconds(1));

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

void Singly::AddMiddle(std::string X, sf::RenderWindow& window)
{
    if (size == 0)
    {
        AddFirst(X, window);
        return;
    }
    if (size == 1)
    {
        AddLast(X, window);
        return;
    }
    sf::Font arial;
    arial.loadFromFile("arial.ttf");

    sf::Color TextColor(64, 140, 124);
    sf::Color OutColor(241, 70, 102);
    sf::Color BoxColor(255, 220, 195);

    sf::Text Data;
    Data.setFont(arial);
    Data.setCharacterSize(15);
    Data.sf::Text::setFillColor(TextColor);
    Data.setStyle(sf::Text::Bold);
    Data.setString(X);
    Data.setPosition({ (float)240 + 75 * size - (size%2) * 75, 112.5});

    sf::CircleShape Box(50.f);
    Box.setFillColor(BoxColor);
    Box.setFillColor(BoxColor);
    Box.setOutlineThickness(3);
    Box.setOutlineColor(OutColor);
    Box.setPosition({ (float)225 + 75 * size - (size % 2) * 75, 70 });

    sf::Text Head;
    Head.setFont(arial);
    Head.setCharacterSize(20);
    Head.setString("Head/");
    Head.sf::Text::setFillColor(sf::Color::Cyan);
    Head.setStyle(sf::Text::Bold);

    sf::Text Tail;
    Tail.setFont(arial);
    Tail.setCharacterSize(20);
    Tail.setPosition({ 240, 372.5 });
    Tail.sf::Text::setFillColor(sf::Color::Cyan);
    Tail.setStyle(sf::Text::Bold);

    if (size > 0)
    {
        if (size == 1)
        {
            Tail.setString("Tail/Head/");
            Tail.setPosition({ 225, 372.5 });
            window.draw(Tail);
        }
        else
        {
            Head.setPosition({ (float)240 + (size - 1) * 150, 372.5 });
            Tail.setPosition({ 240, 372.5 });
            Tail.setString("Tail/");
            window.draw(Head);
            window.draw(Tail);
        }
    }
    PrintArrow(size - 1, window);
    PrintBox(size, window);
    Print(window, 8);
    window.draw(Box);
    window.draw(Data);

    window.display();
    sf::sleep(sf::seconds(1));

    PrintArrow(size - 1, size / 2 - 1, 8, window);
    PrintBox(size, window);
    Print(window, 8);
    window.draw(Box);
    window.draw(Data);
    ArrowPointAt(size / 2, window);
    ArrowPoint(size / 2, window);
    if (size > 1) window.draw(Head);
    window.draw(Tail);

    window.display();
    sf::sleep(sf::seconds(1));

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

void Singly::DeleteFirst(sf::RenderWindow& window)
{
    head = head->next;
    size--;
}

void Singly::DeleteLast(sf::RenderWindow& window)
{
    if (size == 1)
    {
        DeleteFirst(window);
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

void Singly::DeleteMiddle(sf::RenderWindow& window)
{
    if (size == 1)
    {
        DeleteFirst(window);
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

void Set(Singly& X, std::vector<std::string> Y)
{
    X.Set(Y);
}

void AddFirst(Singly& X, std::string Y, sf::RenderWindow& window)
{
    X.AddFirst(Y, window);
}

void AddLast(Singly& X, std::string Y, sf::RenderWindow& window)
{
    X.AddLast(Y, window);
}

void AddMiddle(Singly& X, std::string Y, sf::RenderWindow& window)
{
    X.AddMiddle(Y, window);
}

void DeleteFirst(Singly& X, sf::RenderWindow& window)
{
    X.DeleteFirst(window);
}

void DeleteLast(Singly& X, sf::RenderWindow& window)
{
    X.DeleteLast(window);
}

void DeleteMiddle(Singly& X, sf::RenderWindow& window)
{
    X.DeleteMiddle(window);
}

void Update(Singly& X, std::string Y, int Z)
{
    X.Update(Y, Z);
}

int Search(Singly& X, std::string Y)
{
    return X.Search(Y);
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

    sf::Text Head;
    Head.setFont(arial);
    Head.setCharacterSize(20);
    Head.setString("Head/");
    Head.sf::Text::setFillColor(sf::Color::Cyan);
    Head.setStyle(sf::Text::Bold);

    sf::Text Tail;
    Tail.setFont(arial);
    Tail.setCharacterSize(20);
    Tail.setPosition({ 240, 372.5 });
    Tail.sf::Text::setFillColor(sf::Color::Cyan);
    Tail.setStyle(sf::Text::Bold);
    
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
                        std::string X = GetData(Events, window, btn, 10, 3, Done);
                        if (Done != 0) break;
                        AddFirst(Example, X, window);
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
                        AddLast(Example, X, window);
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
                        AddMiddle(Example, X, window);
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
                        DeleteFirst(Example, window);
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
                        DeleteLast(Example, window);
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
                        DeleteMiddle(Example, window);
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
                                        Tail.setString("Tail/Head/");
                                        Tail.setPosition({ 225, 372.5 });
                                        window.draw(Tail);
                                    }
                                    else
                                    {
                                        Head.setPosition({ (float)240 + (Example.GetSize() - 1) * 150, 372.5 });
                                        Tail.setPosition({ 240, 372.5 });
                                        Tail.setString("Tail/");
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
                                        Tail.setString("Tail/Head/");
                                        Tail.setPosition({ 225, 372.5 });
                                        window.draw(Tail);
                                    }
                                    else
                                    {
                                        Head.setPosition({ (float)240 + (Example.GetSize() - 1) * 150, 372.5 });
                                        Tail.setPosition({ 240, 372.5 });
                                        Tail.setString("Tail/");
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
                Tail.setString("Tail/Head/");
                Tail.setPosition({ 225, 372.5 });
                window.draw(Tail);
            }
            else
            {
                Head.setPosition({ (float)240 + (Example.GetSize() - 1) * 150, 372.5 });
                Tail.setPosition({ 240, 372.5 });
                Tail.setString("Tail/");
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