#include<iostream>
#include<SFML/Graphics.hpp>
#include"DynamicArray.h"
#include"Buttons.h"
#include"TextBox.h"
#include"InputData.h"
#include"Objects.h"

#define ENTER_KEY 13

Dynamic::Dynamic()
{
    size = 0;
    capacity = 5;
    data.resize(5, "");
}

Dynamic::Dynamic(int cap)
{
    size = 0;
    capacity = cap;
    data.resize(cap, "");
}

std::string& Dynamic::operator[](int index)
{
    return data[index];
}

int Dynamic::GetSize()
{
    return size;
}

bool Dynamic::isFull()
{
    return size == 7;
}

bool Dynamic::isMax()
{
    return size == capacity;
}

bool Dynamic::isEmpty()
{
    return size == 0;
}

void Dynamic::Set(std::vector<std::string> X)
{
    for (int i = 0; i < (int)X.size(); i++)
        data[i] = X[i];
    size = (int)X.size();
    capacity = std::max(capacity, size);
}

void Dynamic::Print(sf::RenderWindow& window, int Nprint)
{
    sf::Font arial;
    arial.loadFromFile("arial.ttf");

    sf::Color TextColor(64, 140, 124);

    sf::Text Data;
    Data.setFont(arial);
    Data.setCharacterSize(15);
    Data.sf::Text::setFillColor(TextColor);
    Data.setStyle(sf::Text::Bold);

    for (int i = 0; i < size; i++)
    {
        Data.setString(data[i]);

        if (i >= Nprint) Data.setPosition({ (float)390 + i * (150), 292.5 });
        else Data.setPosition({ (float)240 + i * (150), 292.5 });

        window.draw(Data);
    }
}

void Dynamic::AddFirst(std::string X)
{   
    for (int i = size; i >= 1; i--)
        data[i] = data[static_cast<std::vector<std::string, std::allocator<std::string>>::size_type>(i) - 1];
    data[0] = X;
    size++;
}

void Dynamic::AddMiddle(std::string X)
{
    for (int i = size; i > size / 2; i--)
        data[i] = data[static_cast<std::vector<std::string, std::allocator<std::string>>::size_type>(i) - 1];
    data[static_cast<std::vector<std::string, std::allocator<std::string>>::size_type>(size / 2) ] = X;
    size++;
}

void Dynamic::AddLast(std::string X)
{
    data[size] = X;
    size++;
}

void Dynamic::DeleteFirst()
{
    size--;
    for (int i = 0; i < size; i++)
        data[i] = data[static_cast<std::vector<std::string, std::allocator<std::string>>::size_type>(i) + 1];
}

void Dynamic::DeleteMiddle()
{
    size--;
    for (int i = size / 2; i < size; i++)
        data[i] = data[static_cast<std::vector<std::string, std::allocator<std::string>>::size_type>(i) + 1];
}

void Dynamic::DeleteLast()
{
    size--;
}

void Dynamic::resize(int newSize)
{
    std::vector<std::string> Temp = data;
    data.resize(newSize, "");
    size = std::min(newSize, size);
    capacity = newSize;
    for (int i = 0; i < size; i++)
        data[i] = Temp[i];
}

void Dynamic::Update(std::string X, int Location)
{
    data[Location] = X;
}

int Dynamic::getCap()
{
    return capacity;
}

int Dynamic::Search(std::string X)
{
    for (int i = 0; i < size; i++)
    if (X == data[i]) return i;
    return -1;
}

void Dynamic::PrintAdd(int Num, Button btn[], Button btnHome, sf::RenderWindow& window)
{
    if (size == 0) return;

    sf::Color ScreenColor(238, 137, 128);
    
    for (int i = size - 1; i >= Num; i--)
    {
        window.clear(ScreenColor);
        btnHome.drawto(window);
        for (int i = 0; i < 12; i++)
            btn[i].drawto(window);
        PrintBox(capacity, window);
        Print(window, i);
        window.display();
        sf::sleep(sf::seconds(1));
    }
}

void Dynamic::PrintDelete(int Num, Button btn[], Button btnHome, sf::RenderWindow& window)
{
    if (size == 0) return;

    sf::Color ScreenColor(238, 137, 128);

    for (int i = Num; i < size; i++)
    {
        window.clear(ScreenColor);
        btnHome.drawto(window);
        for (int i = 0; i < 12; i++)
            btn[i].drawto(window);
        PrintBox(capacity, window);
        Print(window, i);
        window.display();
        sf::sleep(sf::seconds(1));
    }
}

std::string GetData(sf::Event Events, sf::RenderWindow& window, Button btn[], int Nbtn, int X, int& Done, Dynamic Example)
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

        PrintBox(Example.getCap(), window);
        Example.Print(window, 8);

        window.display();
    }
    Done = 0;
    return "";
}

int GetLocation(sf::Event Events, sf::RenderWindow& window, Button btn[], int Nbtn, int X, int Datasize, int& Done, Dynamic Example)
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

        PrintBox(Example.getCap(), window);
        Example.Print(window, 8);

        window.display();
    }
    Done = 0;
    return 0;
}

int GetSize(sf::Event Events, sf::RenderWindow& window, Button btn[], int Nbtn, int X, int Datasize, int& Done, Dynamic Example)
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
    Note1.setString("Input the new size then press enter key!");
    Note1.sf::Text::setFillColor(sf::Color::Cyan);
    Note1.setPosition({ 500, 50 });
    Note1.setStyle(sf::Text::Bold);

    sf::Text Warnings1;
    Warnings1.setFont(arial);
    Warnings1.setCharacterSize(20);
    Warnings1.setString("The size is can be larger than 7. Please re-enter!");
    Warnings1.sf::Text::setFillColor(sf::Color::Cyan);
    Warnings1.setPosition({ 500, 50 });
    Warnings1.setStyle(sf::Text::Bold);

    sf::Text Warnings2;
    Warnings2.setFont(arial);
    Warnings2.setCharacterSize(20);
    Warnings2.setString("The size must be a positive number. Please re - enter!");
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

        PrintBox(Example.getCap(), window);
        Example.Print(window, 8);

        window.display();
    }
    Done = 0;
    return 0;
}

void Set(Dynamic& X, std::vector<std::string> Y)
{
    X.Set(Y);
}

void AddFirst(Dynamic& X, std::string Y)
{
    X.AddFirst(Y);
}

void AddMiddle(Dynamic& X, std::string Y)
{
    X.AddMiddle(Y);
}

void AddLast(Dynamic& X, std::string Y)
{
    X.AddLast(Y);
}

void DeleteFirst(Dynamic& X)
{
    X.DeleteFirst();
}

void DeleteMiddle(Dynamic& X)
{
    X.DeleteMiddle();
}

void DeleteLast(Dynamic& X)
{
    X.DeleteLast();
}

void Update(Dynamic& X, std::string Y, int Z)
{
    X.Update(Y, Z);
}

int Search(Dynamic& X, std::string Y)
{
    return X.Search(Y);
}

void DynamicArrayClient(sf::Event Events, sf::RenderWindow& window)
{
    sf::Font arial;
    arial.loadFromFile("arial.ttf");

    sf::Color ScreenColor(238, 137, 128);
    sf::Color OutColor(241, 70, 102);
    sf::Color BoxColor(255, 220, 195);
    sf::Color TextColor(64, 140, 124);

    Button btn[12];
    for (int i = 0; i < 12; i++)
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
    btn[9].setString("Allocate");
    btn[10].setString("Access");
    btn[11].setString("Search");

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

    sf::Text Warnings3;
    Warnings3.setFont(arial);
    Warnings3.setCharacterSize(20);
    Warnings3.setString("You reach the max size. Please allocate a larger size!");
    Warnings3.sf::Text::setFillColor(sf::Color::Cyan);
    Warnings3.setPosition({ 500, 50 });
    Warnings3.setStyle(sf::Text::Bold);

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

    Dynamic Example;
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
                    if (Example.isMax())
                    {
                        Type = 3;
                        Done = 0;
                    }
                    else
                    if (Example.isFull())
                    {
                        Type = 1;
                        Done = 0;
                    }
                    else
                    {
                        Type = 0;
                        Done = 3;
                        std::string X = GetData(Events, window, btn, 12, 3, Done, Example);
                        if (Done != 0) break;
                        window.clear(ScreenColor);
                        btnHome.drawto(window);
                        for (int i = 0; i < 12; i++)
                            btn[i].drawto(window);
                        PrintBox(Example.getCap(), window);
                        Example.Print(window, 8);
                        window.display();
                        sf::sleep(sf::seconds(1));
                        Example.PrintAdd(0, btn, btnHome, window);
                        AddFirst(Example, X);
                    }
                    break;

                case 4:
                    if (Example.isMax())
                    {
                        Type = 3;
                        Done = 0;
                    }
                    else
                    if (Example.isFull())
                    {
                        Type = 1;
                        Done = 0;
                    }
                    else
                    {
                        Type = 0;
                        Done = 4;
                        std::string X = GetData(Events, window, btn, 12, 4, Done, Example);
                        if (Done != 0) break;
                        AddLast(Example, X);
                    }
                    break;

                case 5:
                    if (Example.isMax())
                    {
                        Type = 3;
                        Done = 0;
                    }
                    else
                    if (Example.isFull())
                    {
                        Type = 1;
                        Done = 0;
                    }
                    else
                    {
                        Type = 0;
                        Done = 5;
                        std::string X = GetData(Events, window, btn, 12, 5, Done, Example);
                        if (Done != 0) break;
                        window.clear(ScreenColor);
                        btnHome.drawto(window);
                        for (int i = 0; i < 12; i++)
                            btn[i].drawto(window);
                        PrintBox(Example.getCap(), window);
                        Example.Print(window, 8);
                        window.display();
                        sf::sleep(sf::seconds(1));
                        Example.PrintAdd(Example.GetSize() / 2, btn, btnHome, window);
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
                        window.clear(ScreenColor);
                        btnHome.drawto(window);
                        for (int i = 0; i < 12; i++)
                            btn[i].drawto(window);
                        PrintBox(Example.getCap(), window);
                        Example.Print(window, 8);
                        Type = 0;
                        DeleteFirst(Example);
                        Example.PrintDelete(0, btn, btnHome, window);
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
                        window.clear(ScreenColor);
                        btnHome.drawto(window);
                        for (int i = 0; i < 12; i++)
                            btn[i].drawto(window);
                        PrintBox(Example.getCap(), window);
                        Example.Print(window, 8);
                        Type = 0;
                        DeleteMiddle(Example);
                        Example.PrintDelete(Example.GetSize() / 2, btn, btnHome, window);
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
                        std::string X = GetData(Events, window, btn, 12, 9, Done, Example);
                        if (Done != 0) break;
                        Done = 9;
                        int Y = GetLocation(Events, window, btn, 12, 9, Example.GetSize() - 1, Done, Example);
                        if (Done != 0) break;
                        Update(Example, X, Y);
                    }
                    break;

                case 10: {
                    Type = 0;
                    Done = 10;
                    int X = GetSize(Events, window, btn, 12, 10, 7, Done, Example);
                    if (Done != 0) break;
                    Example.resize(X);
                }
                    break;

                case 11:
                    if (Example.isEmpty())
                    {
                        Type = 2;
                        Done = 0;
                    }
                    else
                    {
                        Type = 0;
                        Done = 10;
                        int Y = GetLocation(Events, window, btn, 12, 11, Example.GetSize() - 1, Done, Example);
                        if (Done != 0) break;
                        Answer.setString("The value is " + Example[Y]);
                    }
                    break;

                case 12:
                    if (Example.isEmpty())
                    {
                        Type = 2;
                        Done = 0;
                    }
                    else
                    {
                        Type = 0;
                        Done = 5;
                        std::string X = GetData(Events, window, btn, 12, 12, Done, Example);
                        if (Done != 0) break;
                        int Y = Search(Example, X); 
                        if (Y == -1)
                        {
                            for (int i = 0; i < Example.GetSize(); i++)
                            {
                                window.clear(ScreenColor);

                                btnHome.drawto(window);

                                PrintBox(Example.getCap(), window);
                                Example.Print(window, 8);

                                for (int j = 0; j < 12; j++)
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

                                PrintBox(Example.getCap(), window);
                                Example.Print(window, 8);

                                for (int j = 0; j < 12; j++)
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
                        for (int i = 0; i < 12; i++)
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
            for (int i = 0; i < 12; i++)
                if (btn[i].isMouseOver(window))
                    btn[i].setBackColor(sf::Color::White);
                else btn[i].setBackColor(BoxColor);
        }

        window.clear(ScreenColor);

        btnHome.drawto(window);

        PrintBox(Example.getCap(), window);
        Example.Print(window, 8);

        for (int i = 0; i < 12; i++)
            btn[i].drawto(window);

        window.draw(Answer);
        if (Type == 1) window.draw(Warnings1);
        else if (Type == 2) window.draw(Warnings2);
        else if (Type == 3) window.draw(Warnings3);

        window.display();
    }
}