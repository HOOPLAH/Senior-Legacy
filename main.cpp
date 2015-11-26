#include <SFML/Graphics.hpp>

#include "Assets.h"
#include "Constants.h"
#include "WorldManager.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Platformer");

    Assets::loadAssets();

    WorldManager worldMgr;

    sf::Clock clock;
    sf::Time accumulator = sf::Time::Zero;
    int ticks = 0;
    while (window.isOpen())
    {
        //update logic
        sf::Time dt = clock.restart();
        accumulator += dt;
        while (accumulator > UPDATE_STEP)
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();

                    worldMgr.handleEvents(event);
            }

            worldMgr.update(ticks);
            accumulator -= UPDATE_STEP;

            ticks++;
        }

        float alpha = accumulator.asSeconds()/UPDATE_STEP.asSeconds();

        window.clear();
        worldMgr.draw(window, alpha);
        window.display();
    }

    return 0;
}
