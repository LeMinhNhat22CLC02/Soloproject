#include<iostream>
#include<SFML/Graphics.hpp>
#include"StaticArray.h"
#include"Buttons.h"
#include"TextBox.h"
#include"InputData.h"

void Set(std::string X[], std::vector<std::string> Y, int &n)
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

    Button btn1("Initialize", { 100, 100 }, 15, BoxColor, TextColor, OutColor);
    btn1.setPos({ 50, 50 });
    btn1.setFont(arial);

    Button btn2("Add", { 100, 100 }, 15, BoxColor, TextColor, OutColor);
    btn2.setPos({ 50, 200 });
    btn2.setFont(arial);

    Button btn3("Delete", { 100, 100 }, 15, BoxColor, TextColor, OutColor);
    btn3.setPos({ 50, 350 });
    btn3.setFont(arial);

    Button btn4("Update", { 100, 100 }, 15, BoxColor, TextColor, OutColor);
    btn4.setPos({ 50, 500 });
    btn4.setFont(arial);

    Button btn5("Search", { 100, 100 }, 15, BoxColor, TextColor, OutColor);
    btn5.setPos({ 50, 650 });
    btn5.setFont(arial);

    Button btn6("Home", { 100, 100 }, 15, sf::Color::Cyan, TextColor, OutColor);
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
                    if (n == 7)
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
                        int Y = GetLocation(Events, window, btn1, btn3, btn4, btn5, btn6, btn2, n, Done);
                        std::cout << Done << "2" << std::endl;
                        if (Done != 0) break;
                        std::cout << Done << "3" << std::endl;
                        Add(Example, X, Y, n);
                    }
                    break;

                case 3:
                    if (n == 0)
                    {
                        Warnings2.setPosition({ 50, 323 });
                        Type = 2;
                    }
                    else
                    {
                        Type = 0;
                        Done = 3;
                        int X = GetLocation(Events, window, btn1, btn2, btn4, btn5, btn6, btn3, n - 1, Done);
                        if (Done != 0) break;
                        Delete(Example, X, n);
                    }
                    break;

                case 4:
                    if (n == 0)
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
                        int Y = GetLocation(Events, window, btn1, btn2, btn3, btn5, btn6, btn4, n - 1, Done);
                        if (Done != 0) break;
                        Update(Example, X, Y, n);
                    }
                    break;

                case 5:
                    if (n == 0)
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
                        Search(Example, X, n);
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
                        Set(Example, Initialize(), n);
                    }
                    else if (btn2.isMouseOver(window))
                    {
                        if (n == 7)
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
                            int Y = GetLocation(Events, window, btn1, btn3, btn4, btn5, btn6, btn2, n, Done);
                            std::cout << Done << "6" << std::endl;
                            if (Done != 0) break;
                            Add(Example, X, Y, n);
                            Type = 0;
                        }
                    }
                    else if (btn3.isMouseOver(window))
                    {
                        if (n == 0)
                        {
                            Warnings2.setPosition({ 50, 283 });
                            Type = 2;
                        }
                        else
                        {
                            Type = 0;
                            Done = 3;
                            int X = GetLocation(Events, window, btn1, btn2, btn4, btn5, btn6, btn3, n - 1, Done);
                            if (Done != 0) break;
                            Delete(Example, X, n);
                        }
                    }
                    else if (btn4.isMouseOver(window))
                    {
                        if (n == 0)
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
                            int Y = GetLocation(Events, window, btn1, btn2, btn3, btn5, btn6, btn4, n - 1, Done);
                            if (Done != 0) break;
                            Update(Example, X, Y, n);
                        }
                    }
                    else if (btn5.isMouseOver(window))
                    {
                        if (n == 0)
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
                            Search(Example, X, n);
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