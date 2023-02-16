#include "SFMLProject.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Rectangle");

    sf::RectangleShape rect(sf::Vector2f(50.0f, 50.0f));

    rect.setFillColor(sf::Color::Red);
    rect.setPosition(400.0f, 300.0f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        {
            rect.move(0.0f, -5.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            rect.move(0.0f, 5.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {
            rect.move(-5.0f, 0.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            rect.move(5.0f, 0.0f);
        }

        window.clear();
        window.draw(rect);
        window.display();
    }

    return 0;
}
