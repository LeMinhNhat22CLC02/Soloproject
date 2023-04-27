#include<iostream>
#include<SFML/Graphics.hpp>
#include"Buttons.h"
#include"TextBox.h"
#include<string>

#define ENTER_KEY 13

std::vector<std::string> Initialize()
{
    srand(time(NULL));
    std::vector<std::string> Temp;

    Temp.push_back(std::to_string(rand() % 100) + (char)('a' + rand() % 26) + (char)('A' + rand() % 26));
    Temp.push_back((char)('A' + rand() % 26) + std::to_string(rand() % 100) + (char)('a' + rand() % 26));
    Temp.push_back(std::to_string(rand() % 100) + (char)('A' + rand() % 26) + (char)('a' + rand() % 26));
    Temp.push_back((char)('a' + rand() % 26) + std::to_string(rand() % 100) + (char)('A' + rand() % 26));

    return Temp;
}

int WhatType(std::string X, int Datasize)
{
    for (int i = 0; i < X.size(); i++)
        if ('0' > X[i] || '9' < X[i]) return 2;
    if (X.size() > 3) return 1;
    int Temp = 0;
    for (int i = 0; i < X.size(); i++)
        Temp = Temp * 10 + (int)(X[i] - '0');
    return (Temp > Datasize);
}

std::string GetData(sf::Event Events, sf::RenderWindow& window, Button btn1, Button btn2, Button btn3, Button btn4, Button btn5, Button btnX, int& Done)
{
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
    Note1.sf::Text::setFillColor(TextColor);
    Note1.setPosition({ btnX.getPosition().x, btnX.getPosition().y - 27 });

    Textbox Textbox1(15, TextColor, true);
    Textbox1.setFont(arial);
    Textbox1.setLimit(false);
    Textbox1.setPosition(btnX.getPosition());

    sf::RectangleShape Box;
    Box.setSize({ 100, 100 });
    Box.setFillColor(BoxColor);
    Box.setPosition(btnX.getPosition());
    Box.setOutlineThickness(5);
    Box.setOutlineColor(OutColor);

    while (window.isOpen())
    {
        while (window.pollEvent(Events))
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
                else
                {
                    btn1.setBackColor(BoxColor);
                    btn2.setBackColor(BoxColor);
                    btn3.setBackColor(BoxColor);
                    btn4.setBackColor(BoxColor);
                    btn5.setBackColor(sf::Color::Cyan);
                }
                break;

            case sf::Event::MouseButtonPressed:
                if (btn1.isMouseOver(window))
                {
                    Done = 1;
                    return "";
                }
                else if (btn2.isMouseOver(window))
                {
                    Done = 2 + (Done < 3);
                    return "";
                }
                else if (btn3.isMouseOver(window))
                {
                    Done = 3 + (Done < 4);
                    return "";
                }
                else if (btn4.isMouseOver(window))
                {
                    Done = 4 + (Done < 5);
                    return "";
                }
                else if (btn5.isMouseOver(window))
                {
                    Done = 6;
                    return "";
                }
                break;

            case sf::Event::TextEntered:
                Done = 0;
                if (Events.text.unicode == ENTER_KEY) return Textbox1.getText();
                Textbox1.typeOn(Events);
                break;
            }
        }

        window.clear(ScreenColor);
        btn1.drawto(window);
        btn2.drawto(window);
        btn3.drawto(window);
        btn4.drawto(window);
        btn5.drawto(window);

        window.draw(Box);
        Textbox1.drawto(window);
        window.draw(Note1);

        window.display();
    }
    Done = 0;
    return "";
}

int GetLocation(sf::Event Events, sf::RenderWindow& window, Button btn1, Button btn2, Button btn3, Button btn4, Button btn5, Button btnX, int Datasize, int& Done)
{
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
    Note1.sf::Text::setFillColor(TextColor);
    Note1.setPosition({ btnX.getPosition().x, btnX.getPosition().y - 27 });

    sf::Text Warnings1;
    Warnings1.setFont(arial);
    Warnings1.setCharacterSize(20);
    Warnings1.setString("Location exceed size. Please re-enter!");
    Warnings1.sf::Text::setFillColor(TextColor);
    Warnings1.setPosition({ btnX.getPosition().x, btnX.getPosition().y - 27 });

    sf::Text Warnings2;
    Warnings2.setFont(arial);
    Warnings2.setCharacterSize(20);
    Warnings2.setString("The location must be a positive number. Please re - enter!");
    Warnings2.sf::Text::setFillColor(TextColor);
    Warnings2.setPosition({ btnX.getPosition().x, btnX.getPosition().y - 27 });

    Textbox Textbox1(15, TextColor, true);
    Textbox1.setFont(arial);
    Textbox1.setLimit(false);
    Textbox1.setPosition(btnX.getPosition());

    sf::RectangleShape Box;
    Box.setSize({ 100, 100 });
    Box.setFillColor(BoxColor);
    Box.setOutlineThickness(5);
    Box.setOutlineColor(OutColor);
    Box.setPosition(btnX.getPosition());

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
                else
                {
                    btn1.setBackColor(BoxColor);
                    btn2.setBackColor(BoxColor);
                    btn3.setBackColor(BoxColor);
                    btn4.setBackColor(BoxColor);
                    btn5.setBackColor(sf::Color::Cyan);
                }
                break;

            case sf::Event::MouseButtonPressed:
                if (btn1.isMouseOver(window))
                {
                    Done = 1;
                    return 0;
                }
                else if (btn2.isMouseOver(window))
                {
                    Done = 2 + (Done < 3);
                    return 0;
                }
                else if (btn3.isMouseOver(window))
                {
                    Done = 3 + (Done < 4);
                    return 0;
                }
                else if (btn4.isMouseOver(window))
                {
                    Done = 4 + (Done < 5);
                    return 0;
                }
                else if (btn5.isMouseOver(window))
                {
                    Done = 6;
                    return 0;
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

        window.clear(ScreenColor);
        btn1.drawto(window);
        btn2.drawto(window);
        btn3.drawto(window);
        btn4.drawto(window);
        btn5.drawto(window);

        window.draw(Box);
        Textbox1.drawto(window);
        if (Type == 0) window.draw(Note1);
        else if (Type == 1) window.draw(Warnings1);
        else window.draw(Warnings2);

        window.display();
    }
    Done = 0;
    return 0;
}

std::string GetData(sf::Event Events, sf::RenderWindow& window, Button btn[], int Nbtn, int X, int& Done)
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
    Note1.sf::Text::setFillColor(TextColor);
    Note1.setPosition({ 500, 50 });

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

    Button btnHome("Home", { 100, 100 }, 15, sf::Color::Cyan, TextColor, OutColor, 5);
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

            case sf::Event::MouseMoved:
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

        window.clear(ScreenColor);

        for (int i = 0; i < Nbtn; i++)
            btn[i].drawto(window);
        btnHome.drawto(window);
        window.draw(Box);
        Textbox1.drawto(window);
        window.draw(Note1);

        window.display();
    }
    Done = 0;
    return "";
}

int GetLocation(sf::Event Events, sf::RenderWindow& window, Button btn[], int Nbtn, int X, int Datasize, int& Done)
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
    Note1.sf::Text::setFillColor(TextColor);
    Note1.setPosition({ 500, 50 });

    sf::Text Warnings1;
    Warnings1.setFont(arial);
    Warnings1.setCharacterSize(20);
    Warnings1.setString("Location exceed size. Please re-enter!");
    Warnings1.sf::Text::setFillColor(TextColor);
    Warnings1.setPosition({ 500, 50 });

    sf::Text Warnings2;
    Warnings2.setFont(arial);
    Warnings2.setCharacterSize(20);
    Warnings2.setString("The location must be a positive number. Please re - enter!");
    Warnings2.sf::Text::setFillColor(TextColor);
    Warnings2.setPosition({ 500, 50 });

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

    Button btnHome("Home", { 100, 100 }, 15, sf::Color::Cyan, TextColor, OutColor, 5);
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

            case sf::Event::MouseMoved:
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

        window.clear(ScreenColor);

        for (int i = 0; i < Nbtn; i++)
            btn[i].drawto(window);
        btnHome.drawto(window);
        window.draw(Box);
        Textbox1.drawto(window);
        if (Type == 0) window.draw(Note1);
        else if (Type == 1) window.draw(Warnings1);
        else window.draw(Warnings2);

        window.display();
    }
    Done = 0;
    return 0;
}