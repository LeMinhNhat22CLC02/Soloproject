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

void Queue::enqueue(std::string data)
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

std::string Queue::dequeue()
{
    std::string data = front->data;
    Node* temp = front;
    front = front->next;

    if (front == nullptr)
    {
        back = nullptr;
    }

    delete temp;
    Size--;
    return data;
}

std::string Queue::peek()
{
    return front->data;
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

int Queue::GetSize()
{
    return Size;
}

void Queue::Set(std::vector<std::string> X)
{
    front = nullptr;
    back = nullptr;
    for (int i = 0; i < X.size(); i++)
        enqueue(X[i]);
}

void Queue::Add(std::string X, int Y)
{
    std::vector<std::string> Temp;
    while (Y--)
    {
        Temp.push_back(front->data);
        dequeue();
    }
    Temp.push_back(X);
    while (!isEmpty())
    {
        Temp.push_back(front->data);
        dequeue();
    }
    for (int i = 0; i < Temp.size(); i++)
        enqueue(Temp[i]);
}

void Queue::Delete(int X)
{
    std::vector<std::string> Temp;
    while (X--)
    {
        Temp.push_back(front->data);
        dequeue();
    }
    dequeue();
    while (!isEmpty())
    {
        Temp.push_back(front->data);
        dequeue();
    }
    for (int i = 0; i < Temp.size(); i++)
        enqueue(Temp[i]);
}

void Queue::Update(std::string X, int Y)
{
    std::vector<std::string> Temp;
    while (Y--)
    {
        Temp.push_back(front->data);
        dequeue();
    }
    Temp.push_back(X);
    dequeue();
    while (!isEmpty())
    {
        Temp.push_back(front->data);
        dequeue();
    }
    for (int i = 0; i < Temp.size(); i++)
        enqueue(Temp[i]);
}

void Queue::Search(std::string X)
{
    Node* current = front;
    int Count = 0;

    while (current != nullptr)
    {
        if (current->data == X)
        {
            std::cout << Count << std::endl;
            return;
        }
        current = current->next;
        Count++;
    }
    return;
}

void Set(Queue& X, std::vector<std::string> Y)
{
    X.Set(Y);
}

void Add(Queue& X, std::string Y, int Z)
{
    X.Add(Y, Z);
}

void Delete(Queue& X, int Y)
{
    X.Delete(Y);
}

void Update(Queue& X, std::string Y, int Z)
{
    X.Update(Y, Z);
}

void Search(Queue& X, std::string Y)
{
    X.Search(Y);
}

void QueueClient(sf::Event Events, sf::RenderWindow& window)
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
                switch (Done)
                {
                case 1:
                    Type = 0;
                    Done = 0;
                    Set(Example, Initialize());
                    break;

                case 2:
                    if (Example.isFull())
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
                        int Y = GetLocation(Events, window, btn1, btn3, btn4, btn5, btn6, btn2, Example.GetSize(), Done);
                        std::cout << Done << "2" << std::endl;
                        if (Done != 0) break;
                        std::cout << Done << "3" << std::endl;
                        Add(Example, X, Y);
                    }
                    break;

                case 3:
                    if (Example.isEmpty())
                    {
                        Warnings2.setPosition({ 50, 323 });
                        Type = 2;
                    }
                    else
                    {
                        Type = 0;
                        Done = 3;
                        int X = GetLocation(Events, window, btn1, btn2, btn4, btn5, btn6, btn3, Example.GetSize() - 1, Done);
                        if (Done != 0) break;
                        Delete(Example, X);
                    }
                    break;

                case 4:
                    if (Example.isEmpty())
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
                        int Y = GetLocation(Events, window, btn1, btn2, btn3, btn5, btn6, btn4, Example.GetSize() - 1, Done);
                        if (Done != 0) break;
                        Update(Example, X, Y);
                    }
                    break;

                case 5:
                    if (Example.isEmpty())
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
                        Search(Example, X);
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
                        Set(Example, Initialize());
                    }
                    else if (btn2.isMouseOver(window))
                    {
                        if (Example.isFull())
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
                            int Y = GetLocation(Events, window, btn1, btn3, btn4, btn5, btn6, btn2, Example.GetSize(), Done);
                            std::cout << Done << "6" << std::endl;
                            if (Done != 0) break;
                            Add(Example, X, Y);
                            Type = 0;
                        }
                    }
                    else if (btn3.isMouseOver(window))
                    {
                        if (Example.isEmpty())
                        {
                            Warnings2.setPosition({ 50, 283 });
                            Type = 2;
                        }
                        else
                        {
                            Type = 0;
                            Done = 3;
                            int X = GetLocation(Events, window, btn1, btn2, btn4, btn5, btn6, btn3, Example.GetSize() - 1, Done);
                            if (Done != 0) break;
                            Delete(Example, X);
                        }
                    }
                    else if (btn4.isMouseOver(window))
                    {
                        if (Example.isEmpty())
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
                            int Y = GetLocation(Events, window, btn1, btn2, btn3, btn5, btn6, btn4, Example.GetSize() - 1, Done);
                            if (Done != 0) break;
                            Update(Example, X, Y);
                        }
                    }
                    else if (btn5.isMouseOver(window))
                    {
                        if (Example.isEmpty())
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
                            Search(Example, X);
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
        Example.Print();
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