#include<iostream>
#include<SFML/Graphics.hpp>
#include"StaticArray.h"
#include"Buttons.h"
#include"TextBox.h"
#include"InputData.h"
#include"Objects.h"

#define ENTER_KEY 13

void Set(std::string X[], std::vector<std::string> Y, int& n)
{
    for (int i = 0; i < Y.size(); i++)
        X[i] = Y[i];
    n = (int)Y.size();
}

void AddFirst(std::string X[], std::string Y, int& n)
{
    for (int i = n; i > 0; i--)
        X[i] = X[i - 1];
    X[0] = Y;
    n++;
}

void AddMiddle(std::string X[], std::string Y, int& n)
{
    for (int i = n; i > n / 2; i--)
        X[i] = X[i - 1];
    X[n / 2] = Y;
    n++;
}

void AddLast(std::string X[], std::string Y, int& n)
{
    X[n] = Y;
    n++;
}

void DeleteFirst(std::string X[], int& n)
{
    n--;
    for (int i = 0; i < n; i++)
        X[i] = X[i + 1];
}

void DeleteMiddle(std::string X[], int& n)
{
    n--;
    for (int i = n / 2; i < n; i++)
        X[i] = X[i + 1]; 
}

void DeleteLast(std::string X[], int& n)
{
    n--;
}

void Update(std::string X[], std::string Y, int Z, int n)
{
    X[Z] = Y;
}

int Search(std::string X[], std::string Y, int n)
{
    for (int i = 0; i < n; i++)
    if (X[i] == Y) return i;
    return -1;
}

void Print(sf::RenderWindow& window, std::string data[], int size, int Nprint)
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

std::string GetData(sf::Event Events, sf::RenderWindow& window, Button btn[], int Nbtn, int X, int& Done, std::string Example[], int n)
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

        PrintBox(7, window);
        Print(window, Example, n, 8);

        window.display();
    }
    Done = 0;
    return "";
}

int GetLocation(sf::Event Events, sf::RenderWindow& window, Button btn[], int Nbtn, int X, int Datasize, int& Done, std::string Example[], int n)
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

        PrintBox(7, window);
        Print(window, Example, n, 8);

        window.display();
    }
    Done = 0;
    return 0;
}

void StaticArrayClient(sf::Event Events, sf::RenderWindow& window)
{
    sf::Font arial;
    arial.loadFromFile("arial.ttf");

    sf::Color ScreenColor(238, 137, 128);
    sf::Color OutColor(241, 70, 102);
    sf::Color BoxColor(255, 220, 195);
    sf::Color TextColor(64, 140, 124);

    Button btn[11];
    for (int i = 0; i < 11; i++)
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
    btn[9].setString("Access");
    btn[10].setString("Search");

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

    std::string Example[7];
    int n = 4;
    Set(Example, Initialize(), n);

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
                    if (Path != nullptr) Set(Example, ReadFromFile(Path), n);
                    break;

                case 2:
                    Type = 0;
                    Done = 0;
                    Set(Example, Initialize(), n);
                    break;

                case 3:
                    if (n == 7)
                    {
                        Type = 1;
                        Done = 0;
                    }
                    else
                    {
                        Type = 0;
                        Done = 3;
                        std::string X = GetData(Events, window, btn, 11, 3, Done, Example, n);
                        if (Done != 0) break;
                        window.clear(ScreenColor);
                        btnHome.drawto(window);
                        for (int i = 0; i < 11; i++)
                            btn[i].drawto(window);
                        PrintBox(7, window);
                        Print(window, Example, n, 8);
                        window.display();
                        sf::sleep(sf::seconds(1));
                        for (int i = n; i >= 1; i--)
                        {
                            window.clear(ScreenColor);
                            btnHome.drawto(window);
                            for (int i = 0; i < 11; i++)
                                btn[i].drawto(window);
                            PrintBox(7, window);
                            Print(window, Example, n, i - 1);
                            window.display();
                            sf::sleep(sf::seconds(1));
                        }

                        AddFirst(Example, X, n);
                    }
                    break;

                case 4:
                    if (n == 7)
                    {
                        Type = 1;
                        Done = 0;
                    }
                    else
                    {
                        Type = 0;
                        Done = 4;
                        std::string X = GetData(Events, window, btn, 11, 4, Done, Example, n);
                        if (Done != 0) break;
                        AddLast(Example, X, n);
                    }
                    break;

                case 5:
                    if (n == 7)
                    {
                        Type = 1;
                        Done = 0;
                    }
                    else
                    {
                        Type = 0;
                        Done = 5;
                        std::string X = GetData(Events, window, btn, 11, 5, Done, Example, n);
                        if (Done != 0) break;
                        window.clear(ScreenColor);
                        btnHome.drawto(window);
                        for (int i = 0; i < 11; i++)
                            btn[i].drawto(window);
                        PrintBox(7, window);
                        Print(window, Example, n, 8);
                        window.display();
                        sf::sleep(sf::seconds(1));
                        for (int i = n; i > n / 2; i--)
                        {
                            window.clear(ScreenColor);
                            btnHome.drawto(window);
                            for (int i = 0; i < 11; i++)
                                btn[i].drawto(window);
                            PrintBox(7, window);
                            Print(window, Example, n, i - 1);
                            window.display();
                            sf::sleep(sf::seconds(1));
                        }
                        AddMiddle(Example, X, n);
                    }
                    break;

                case 6:
                    if (n == 0)
                    {
                        Type = 2;
                        Done = 0;
                    }
                    else
                    {
                        window.clear(ScreenColor);
                        btnHome.drawto(window);
                        for (int i = 0; i < 11; i++)
                            btn[i].drawto(window);
                        PrintBox(7, window);
                        Print(window, Example, n, 8);
                        window.display();
                        sf::sleep(sf::seconds(1));
                        Type = 0;
                        DeleteFirst(Example, n);
                        Done = 0;
                        for (int i = 0; i < n; i++)
                        {
                            window.clear(ScreenColor);
                            btnHome.drawto(window);
                            for (int i = 0; i < 11; i++)
                                btn[i].drawto(window);
                            PrintBox(7, window);
                            Print(window, Example, n, i + 1);
                            window.display();
                            sf::sleep(sf::seconds(1));
                        }
                    }
                    break;

                case 7:
                    if (n == 0)
                    {
                        Type = 2;
                        Done = 0;
                    }
                    else
                    {
                        Type = 0;
                        DeleteLast(Example, n);
                        Done = 0;
                    }
                    break;

                case 8:
                    if (n == 0)
                    {
                        Type = 2;
                        Done = 0;
                    }
                    else
                    {
                        window.clear(ScreenColor);
                        btnHome.drawto(window);
                        for (int i = 0; i < 11; i++)
                            btn[i].drawto(window);
                        PrintBox(7, window);
                        Print(window, Example, n, 8);
                        window.display();
                        sf::sleep(sf::seconds(1));
                        Type = 0;
                        DeleteMiddle(Example, n);
                        Done = 0;

                        for (int i = n / 2; i < n; i++)
                        {
                            window.clear(ScreenColor);
                            btnHome.drawto(window);
                            for (int i = 0; i < 11; i++)
                                btn[i].drawto(window);
                            PrintBox(7, window);
                            Print(window, Example, n, i + 1);
                            window.display();
                            sf::sleep(sf::seconds(1));
                        }
                    }
                    break;

                case 9:
                    if (n == 0)
                    {
                        Type = 2;
                        Done = 0;
                    }
                    else
                    {
                        Type = 0;
                        Done = 9;
                        std::string X = GetData(Events, window, btn, 11, 9, Done, Example, n);
                        if (Done != 0) break;
                        Done = 9;
                        int Y = GetLocation(Events, window, btn, 11, 9, n - 1, Done, Example, n);
                        if (Done != 0) break;
                        Update(Example, X, Y, n);
                    }
                    break;

                case 10:
                    if (n == 0)
                    {
                        Type = 2;
                        Done = 0;
                    }
                    else
                    {
                        Type = 0;
                        Done = 10;
                        int Y = GetLocation(Events, window, btn, 11, 10, n - 1, Done, Example, n);
                        if (Done != 0) break;
                        Answer.setString("The value is " + Example[Y]);
                    }
                    break;

                case 11:
                    if (n == 0)
                    {
                        Type = 2;
                        Done = 0;
                    }
                    else
                    {
                        Type = 0;
                        Done = 5;
                        std::string X = GetData(Events, window, btn, 11, 11, Done, Example, n);
                        if (Done != 0) break;
                        int Y = Search(Example, X, n);
                        if (Y == -1)
                        {
                            for (int i = 0; i < n; i++)
                            {
                                window.clear(ScreenColor);

                                btnHome.drawto(window);

                                PrintBox(7, window);
                                Print(window, Example, n, 8);

                                for (int j = 0; j < 11; j++)
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

                                PrintBox(7, window);
                                Print(window, Example, n, 8);

                                for (int j = 0; j < 11; j++)
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
                        for (int i = 0; i < 11; i++)
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
            for (int i = 0; i < 11; i++)
                if (btn[i].isMouseOver(window))
                    btn[i].setBackColor(sf::Color::White);
                else btn[i].setBackColor(BoxColor);
        }

        window.clear(ScreenColor);

        btnHome.drawto(window);

        PrintBox(7, window);
        Print(window, Example, n, 8);

        for (int i = 0; i < 11; i++)
            btn[i].drawto(window);

        window.draw(Answer);
        if (Type == 1) window.draw(Warnings1);
        else if (Type == 2) window.draw(Warnings2);
        
        window.display();
    }
}