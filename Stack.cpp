#include<iostream>
#include<SFML/Graphics.hpp>
#include"Stack.h"
#include"Buttons.h"
#include"TextBox.h"
#include"InputData.h"
#include"Objects.h"

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

void Stack::Push(std::string X, sf::RenderWindow& window)
{
    data.push_back(X);
    PrintArrow((int)data.size() - 2, window);
    PrintBox((int)data.size(), window);
    Print(window);
}

void Stack::Pop(sf::RenderWindow& window)
{
    PrintArrow((int)data.size() - 2, window);
    PrintBox((int)data.size(), window);
    Print(window);
    data.pop_back();
}

void Stack::Print(sf::RenderWindow& window)
{
    sf::Font arial;
    arial.loadFromFile("arial.ttf");

    sf::Color TextColor(64, 140, 124);

    sf::Text Data;
    Data.setFont(arial);
    Data.setCharacterSize(15);
    Data.sf::Text::setFillColor(TextColor);
    Data.setStyle(sf::Text::Bold);

    for (int i = 0; i < (int)data.size(); i++)
    {
        Data.setString(data[i]);
        Data.setPosition({ (float)240 + i * (150), 292.5 });
        window.draw(Data);
    }
}

int Stack::GetSize()
{
    return (int)data.size();
}

void Set(Stack& X, std::vector<std::string> Y)
{
    X.Set(Y);
}

void Push(Stack& X, std::string Y, sf::RenderWindow& window)
{
    X.Push(Y, window);
}

void Pop(Stack& X, sf::RenderWindow& window)
{
    X.Pop(window);
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
    
    Button btnHome("Home", { 100, 50 }, 15, sf::Color::Cyan, TextColor, OutColor, 5);
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
                        std::string X = GetData(Events, window, btn, 5, 3, Done);
                        if (Done != 0) break;
                        Push(Example, X, window);
                        Head.setPosition({ (float)240 + std::max(0, Example.GetSize() - 2) * 150, 372.5 });
                        Tail.setPosition({ 240, 372.5 });
                        window.draw(Head);
                        window.draw(Tail);
                        window.display();
                        sf::sleep(sf::seconds(1));
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
                        window.clear(ScreenColor);
                        if (Example.GetSize() > 0)
                        {
                            Head.setPosition({ (float)240 + (Example.GetSize() - 1) * 150, 372.5 });
                            Tail.setPosition({ 240, 372.5 });
                            window.draw(Head);
                            window.draw(Tail);
                        }
                        btnHome.drawto(window);
                        for (int i = 0; i < 5; i++)
                            btn[i].drawto(window);
                        Pop(Example, window);
                        window.display();
                        sf::sleep(sf::seconds(1));
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
        PrintBox(Example.GetSize(), window);
        PrintArrow(Example.GetSize() - 1, window);
        Example.Print(window);

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

        for (int i = 0; i < 5; i++)
            btn[i].drawto(window);

        if (Type == 1) window.draw(Warnings1);
        else if (Type == 2) window.draw(Warnings2);

        window.display();

    }
}