#include<iostream>
#include<SFML/Graphics.hpp>

void PrintArrow(int Num, sf::RenderWindow& window)
{
    if (Num < 1) return;
    sf::VertexArray triangle(sf::Triangles, 3);
    triangle[0].position = sf::Vector2f(350, 320);
    triangle[1].position = sf::Vector2f(350, 280);
    triangle[2].position = sf::Vector2f(370, 300);
    triangle[0].color = sf::Color::White;
    triangle[1].color = sf::Color::White;
    triangle[2].color = sf::Color::White;

    sf::Vertex line[] =
    {
        sf::Vertex(sf::Vector2f(330, 300)),
        sf::Vertex(sf::Vector2f(350, 300))
    };
    line[0].color = sf::Color::White;
    line[1].color = sf::Color::White;
    for (int i = 0; i < Num; i++)
    {
        triangle[0].position = sf::Vector2f((float)350 + i * 150, 320);
        triangle[1].position = sf::Vector2f((float)350 + i * 150, 280);
        triangle[2].position = sf::Vector2f((float)370 + i * 150, 300);
        line[0] = sf::Vertex(sf::Vector2f((float)330 + i * 150, 300));
        line[1] = sf::Vertex(sf::Vector2f((float)350 + i * 150, 300));
        window.draw(triangle);
        window.draw(line, 2, sf::Lines);
    }
}

void PrintDoubleArrow(int Num, sf::RenderWindow& window) 
{
    if (Num < 1) return;
    sf::VertexArray triangle1(sf::Triangles, 3);
    triangle1[0].position = sf::Vector2f(360, 320);
    triangle1[1].position = sf::Vector2f(360, 300);
    triangle1[2].position = sf::Vector2f(370, 310);
    triangle1[0].color = sf::Color::White;
    triangle1[1].color = sf::Color::White;
    triangle1[2].color = sf::Color::White;

    sf::VertexArray triangle2(sf::Triangles, 3);
    triangle2[0].position = sf::Vector2f(360, 300);
    triangle2[1].position = sf::Vector2f(360, 280);
    triangle2[2].position = sf::Vector2f(370, 290);
    triangle2[0].color = sf::Color::White;
    triangle2[1].color = sf::Color::White;
    triangle2[2].color = sf::Color::White;
    
    sf::Vertex line1[] =
    {
        sf::Vertex(sf::Vector2f(340, 310)),
        sf::Vertex(sf::Vector2f(360, 310))
    };
    line1[0].color = sf::Color::White;
    line1[1].color = sf::Color::White;

    sf::Vertex line2[] =
    {
        sf::Vertex(sf::Vector2f(340, 290)),
        sf::Vertex(sf::Vector2f(360, 290))
    };
    line2[0].color = sf::Color::White;
    line2[1].color = sf::Color::White;
    
    for (int i = 0; i < Num; i++)
    {
        triangle1[0].position = sf::Vector2f((float)360 + i * 150, 320);
        triangle1[1].position = sf::Vector2f((float)360 + i * 150, 300);
        triangle1[2].position = sf::Vector2f((float)370 + i * 150, 310);

        triangle2[0].position = sf::Vector2f((float)340 + i * 150, 300);
        triangle2[1].position = sf::Vector2f((float)340 + i * 150, 280);
        triangle2[2].position = sf::Vector2f((float)330 + i * 150, 290);
        
        window.draw(triangle1);
        window.draw(triangle2);

        line1[0] = sf::Vertex(sf::Vector2f((float)340 + i * 150, 310));
        line1[1] = sf::Vertex(sf::Vector2f((float)360 + i * 150, 310));

        line2[0] = sf::Vertex(sf::Vector2f((float)340 + i * 150, 290));
        line2[1] = sf::Vertex(sf::Vector2f((float)360 + i * 150, 290));

        window.draw(line1, 2, sf::Lines);
        window.draw(line2, 2, sf::Lines);
    }
}

void PrintBox(int Num, sf::RenderWindow& window)
{
    sf::Color OutColor(241, 70, 102);
    sf::Color BoxColor(255, 220, 195);

    sf::CircleShape Box(50.f);
    Box.setFillColor(BoxColor);
    Box.setFillColor(BoxColor);
    Box.setOutlineThickness(3);
    Box.setOutlineColor(OutColor);

    for (int i = 0; i < Num; i++)
    {
        Box.setPosition({ (float)225 + i * (150), 250 });
        window.draw(Box);
    }
}