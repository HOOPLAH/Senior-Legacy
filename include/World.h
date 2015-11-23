#ifndef WORLD_H
#define WORLD_H

#include <memory>

#include <SFML/Graphics.hpp>

#include "ICollideable.h"
#include "Player.h"
#include "WorldObject.h"

class World
{
    public:
        World(std::string path);
        ~World();

        void update();
        void draw(sf::RenderTarget& target);
        void handleEvents(sf::Event& event);

        bool checkCollision(std::weak_ptr<ICollideable> a, std::weak_ptr<ICollideable> b);
        void resolveCollision(std::weak_ptr<ICollideable> a, std::weak_ptr<ICollideable> b);

    private:
        void loadWorld(std::string path);

        sf::Vector2f mGravity;

        std::shared_ptr<Player> mPlayer;
        std::vector<std::shared_ptr<WorldObject>> mWorldObjects;
        std::vector<std::weak_ptr<ICollideable>> mCollideables;

        sf::Sprite mBackground;
};

#endif // WORLD_H
