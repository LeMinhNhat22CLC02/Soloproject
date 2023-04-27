#include<iostream>
#include<SFML/Graphics.hpp>
#include"StaticArray.h"
#include"Buttons.h"
#include"TextBox.h"
#include"InputData.h"

void Set(std::string X[], std::vector<std::string> Y, int& n)
{
    for (int i = 0; i < Y.size(); i++)
        X[i] = Y[i];
    n = (int)Y.size();
}

void Add(std::string X[], std::string Y, int Z, int& n)
{
    for (int i = n; i >= Z; i--)
        X[i] = X[i - 1];
    X[Z] = Y;
    n++;
}

void Delete(std::string X[], int Y, int& n)
{
    for (int i = Y; i < n; i++)
        X[i] = X[i + 1];
    X[n - 1] = "";
    n--;
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

void Search(std::string X[], std::string Y, int n)
{
    for (int i = 0; i < n; i++)
        if (X[i] == Y)
        {
            std::cout << i << std::endl;
        }
    std::cout << -1 << std::endl;
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

    Button btnHome("Home", { 100, 100 }, 15, sf::Color::Cyan, TextColor, OutColor, 5);
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
                switch (Done)
                {
                case 1:
                    Type = 0;
                    Done = 0;
                    Set(Example, Initialize(), n);
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
                        std::string X = GetData(Events, window, btn, 11, 3, Done);
                        if (Done != 0) break;
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
                        std::string X = GetData(Events, window, btn, 11, 4, Done);
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
                        std::string X = GetData(Events, window, btn, 11, 5, Done);
                        if (Done != 0) break;
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
                        Type = 0;
                        DeleteFirst(Example, n);
                        Done = 0;
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
                        Type = 0;
                        DeleteMiddle(Example, n);
                        Done = 0;
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
                        std::string X = GetData(Events, window, btn, 11, 9, Done);
                        if (Done != 0) break;
                        Done = 9;
                        int Y = GetLocation(Events, window, btn, 11, 9, n - 1, Done);
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
                        int Y = GetLocation(Events, window, btn, 11, 10, n - 1, Done);
                        if (Done != 0) break;
                        std::cout << Example[Y];
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
                        std::string X = GetData(Events, window, btn, 11, 11, Done);
                        if (Done != 0) break;
                        Search(Example, X, n);
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
                                Done = i + 1;
                                break;
                            }
                        switch (Done)
                        {
                        case 1:
                            Type = 0;
                            Done = 0;
                            Set(Example, Initialize(), n);
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
                                std::string X = GetData(Events, window, btn, 11, 3, Done);
                                if (Done != 0) break;
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
                                std::string X = GetData(Events, window, btn, 11, 4, Done);
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
                                std::string X = GetData(Events, window, btn, 11, 5, Done);
                                if (Done != 0) break;
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
                                Type = 0;
                                DeleteFirst(Example, n);
                                Done = 0;
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
                                Type = 0;
                                DeleteMiddle(Example, n);
                                Done = 0;
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
                                std::string X = GetData(Events, window, btn, 11, 9, Done);
                                if (Done != 0) break;
                                Done = 9;
                                int Y = GetLocation(Events, window, btn, 11, 9, n - 1, Done);
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
                                int Y = GetLocation(Events, window, btn, 11, 10, n - 1, Done);
                                if (Done != 0) break;
                                std::cout << Example[Y];
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
                                std::string X = GetData(Events, window, btn, 11, 11, Done);
                                if (Done != 0) break;
                                Search(Example, X, n);
                            }
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

        for (int i = 0; i < n; i++)
            std::cout << Example[i] << " "; std::cout << "\n";

        for (int i = 0; i < 11; i++)
            btn[i].drawto(window);
        
        if (Type == 1) window.draw(Warnings1);
        else if (Type == 2) window.draw(Warnings2);
        
        window.display();
    }
}