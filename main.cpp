#include <SFML/Graphics.hpp>

#include "Assets.h"
#include "Constants.h"
#include "World.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Platformer");

    Assets::loadAssets();

    World world("Content/Worlds/world.txt");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            world.handleEvents(event);
        }

        world.update();

        window.clear();
        world.draw(window);
        window.display();
    }

    return 0;
}
