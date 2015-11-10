#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

#include "SpriteObject.h"
#include "ICollideable.h"

class Player : public SpriteObject, public ICollideable
{
    public:
        Player(SpriteInfo& info, sf::Vector2f pos);
        ~Player();

        void update();
        void draw(sf::RenderTarget& target);
        void handleEvents(sf::Event& event);

    private:
};

#endif // PLAYER_H
