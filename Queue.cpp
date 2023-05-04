#include<iostream>
#include<SFML/Graphics.hpp>
#include"Queue.h"
#include"Buttons.h"
#include"TextBox.h"
#include"InputData.h"

Queue::Queue()
{
    front = nullptr;
    back = nullptr;
    Size = 0;
}

Queue::~Queue()
{
    while (front != nullptr)
    {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}

void Queue::Add(std::string data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->next = nullptr;

    if (front == nullptr)
    {
        front = temp;
        back = temp;
    }
    else
    {
        back->next = temp;
        back = temp;
    }
    Size++;
}

void Queue::Remove()
{
    std::string data = front->data;
    Node* temp = front;
    front = front->next;
    if (front == nullptr) back = nullptr;
    delete temp;
    Size--;
}

bool Queue::isFull()
{
    return Size == 7;
}

bool Queue::isEmpty()
{
    return front == nullptr;
}

void Queue::Print()
{
    Node* current = front;

    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
    return;
}

void Queue::Set(std::vector<std::string> X)
{
    front = nullptr;
    back = nullptr;
    for (int i = 0; i < X.size(); i++)
        Add(X[i]);
}

int Queue::GetSize() 
{
    return Size;
}

void Set(Queue& X, std::vector<std::string> Y)
{
    X.Set(Y);
}

void Add(Queue& X, std::string Y)
{
    X.Add(Y);
}

void Remove(Queue& X)
{
    X.Remove();
}

void QueueClient(sf::Event Events, sf::RenderWindow& window)
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
    btn[2].setString("Add");
    btn[3].setString("Remove");
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

    Queue Example;
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
                        Add(Example, X);
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
                        Remove(Example);
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

        Example.Print();

        for (int i = 0; i < 5; i++)
            btn[i].drawto(window);

        if (Type == 1) window.draw(Warnings1);
        else if (Type == 2) window.draw(Warnings2);

        window.display();

    }
}