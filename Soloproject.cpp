#include <iostream>
#include <SFML/Graphics.hpp>

#include "TextBox.h"
#include "Buttons.h"

#include "StaticArray.h"
#include "DynamicArray.h"
#include "Singly.h"
#include "Doubly.h"
#include "Circular.h"
#include "Stack.h"
#include "Queue.h"

int main()
{
    sf::RenderWindow window;

    sf::Vector2i centerWidow((sf::VideoMode::getDesktopMode().width / 2) - 650, (sf::VideoMode::getDesktopMode().height / 2) - 400);

    window.create(sf::VideoMode(1300, 800), "Data Structure Visualization", sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(centerWidow);
    window.setKeyRepeatEnabled(true);

    sf::Font arial;
    arial.loadFromFile("arial.ttf");

    sf::Color ScreenColor(238, 137, 128);
    sf::Color OutColor(241, 70, 102);
    sf::Color BoxColor(255, 220, 195);
    sf::Color TextColor(64, 140, 124);

    Button btn1("Static array", { 300, 100 }, 30, BoxColor, TextColor, OutColor, 5);
    btn1.setPos({ 300, 125 });
    btn1.setFont(arial);

    Button btn2("Dynamic array", { 300, 100 }, 30, BoxColor, TextColor, OutColor, 5);
    btn2.setPos({ 700, 125 });
    btn2.setFont(arial);

    Button btn3("Singly linked list", { 300, 100 }, 30, BoxColor, TextColor, OutColor, 5);
    btn3.setPos({ 100, 350 });
    btn3.setFont(arial);

    Button btn4("Doubly linked list", { 300, 100 }, 30, BoxColor, TextColor, OutColor, 5);
    btn4.setPos({ 500, 350 });
    btn4.setFont(arial);

    Button btn5("Circular linked list", { 300, 100 }, 30, BoxColor, TextColor, OutColor, 5);
    btn5.setPos({ 900, 350 });
    btn5.setFont(arial);

    Button btn6("Stack", { 300, 100 }, 30, BoxColor, TextColor, OutColor, 5);
    btn6.setPos({ 300, 575 });
    btn6.setFont(arial);

    Button btn7("Queue", { 300, 100 }, 30, BoxColor, TextColor, OutColor, 5);
    btn7.setPos({ 700, 575 });
    btn7.setFont(arial);

    while (window.isOpen())
    {
        sf::Event Events;

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
                else if (btn6.isMouseOver(window))
                {
                    btn6.setBackColor(sf::Color::White);
                }
                else if (btn7.isMouseOver(window))
                {
                    btn7.setBackColor(sf::Color::White);
                }
                else
                {
                    btn1.setBackColor(BoxColor);
                    btn2.setBackColor(BoxColor);
                    btn3.setBackColor(BoxColor);
                    btn4.setBackColor(BoxColor);
                    btn5.setBackColor(BoxColor);
                    btn6.setBackColor(BoxColor);
                    btn7.setBackColor(BoxColor);
                }
                break;
            case sf::Event::MouseButtonPressed:
                if (btn1.isMouseOver(window))
                {
                    StaticArrayClient(Events, window);
                }
                else if (btn2.isMouseOver(window))
                {
                    DynamicArrayClient(Events, window);
                }
                else if (btn3.isMouseOver(window))
                {
                    SinglyClient(Events, window);
                }
                else if (btn4.isMouseOver(window))
                {
                    DoublyClient(Events, window);
                }
                else if (btn5.isMouseOver(window))
                {
                    CircularClient(Events, window);
                }
                else if (btn6.isMouseOver(window))
                {
                    StackClient(Events, window);
                }
                else if (btn7.isMouseOver(window))
                {
                    QueueClient(Events, window);
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
        btn7.drawto(window);
        window.display();
    }
    return 0;
}