#include<iostream>
#include<SFML/Graphics.hpp>
#include"Stack.h"
#include"Buttons.h"
#include"TextBox.h"
#include"InputData.h"

Stack::Stack() {
    Size = 7;
}

void Stack::Set(std::vector<std::string> X)
{
    data = X;
}

bool Stack::isEmpty()
{
    return (data.size() == 0);
}

bool Stack::isFull()
{
    return (data.size() == Size);
}

void Stack::Push(std::string X)
{
    data.push_back(X);
    Size++;
}

void Stack::Pop()
{
    data.pop_back();
    Size--;
}

void Stack::Print(sf::RenderWindow& window)
{
    sf::Font arial;
    arial.loadFromFile("arial.ttf");

    sf::Color OutColor(241, 70, 102);
    sf::Color BoxColor(255, 220, 195);
    sf::Color TextColor(64, 140, 124);

    sf::Text Data;
    Data.setFont(arial);
    Data.setCharacterSize(15);
    Data.sf::Text::setFillColor(TextColor);
    Data.setStyle(sf::Text::Bold);

    sf::RectangleShape Box;
    Box.setSize({ 100, 100 });
    Box.setFillColor(BoxColor);
    Box.setOutlineThickness(5);
    Box.setOutlineColor(OutColor);

    for (int i = 0; i < (int)data.size(); i++)
    {
        Data.setString(data[i]);
        Data.setPosition({ (float)225 + i * (150), 250 });
        Box.setPosition({ (float)225 + i * (150), 250 });

        window.draw(Box);
        window.draw(Data);
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

int Stack::GetSize()
{
    return (int)data.size();
}

void Set(Stack& X, std::vector<std::string> Y)
{
    X.Set(Y);
}

void Push(Stack& X, std::string Y)
{
    X.Push(Y);
}

void Pop(Stack& X)
{
    X.Pop();
}

void StackClient(sf::Event Events, sf::RenderWindow& window)
{
    sf::Font arial;
    arial.loadFromFile("arial.ttf");

    sf::Color ScreenColor(238, 137, 128);
    sf::Color OutColor(241, 70, 102);
    sf::Color BoxColor(255, 220, 195);
    sf::Color TextColor(64, 140, 124);

    Button btn[10];
    for (int i = 0; i < 5; i++)
    {
        btn[i] = Button("", { 160, 40 }, 15, BoxColor, TextColor, OutColor, 3);
        btn[i].setPos({ 10, (float)10 + i * 56 });
        btn[i].setFont(arial);
    }
    btn[0].setString("Init from file");
    btn[1].setString("Randomized data");
    btn[2].setString("Push");
    btn[3].setString("Pop");
    btn[4].setString("Clear");

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

    Stack Example;
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
                        std::string X = GetData(Events, window, btn, 5, 3, Done);
                        if (Done != 0) break;
                        Push(Example, X);
                    }
                    break;

                case 4:
                    if (Example.isEmpty())
                    {
                        Type = 2;
                        Done = 0;
                    }
                    else
                    {
                        Pop(Example);
                        Type = 0;
                        Done = 0;
                    }
                    break;

                case 5:
                    Example.Set({});
                    Done = 0;
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
                        for (int i = 0; i < 5; i++)
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
            for (int i = 0; i < 5; i++)
                if (btn[i].isMouseOver(window))
                    btn[i].setBackColor(sf::Color::White);
                else btn[i].setBackColor(BoxColor);
        }

        window.clear(ScreenColor);

        btnHome.drawto(window);

        Example.Print(window);

        for (int i = 0; i < 5; i++)
            btn[i].drawto(window);

        if (Type == 1) window.draw(Warnings1);
        else if (Type == 2) window.draw(Warnings2);

        window.display();

    }
}