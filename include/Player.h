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

        bool onContactBegin(std::weak_ptr<ICollideable> object, bool fromLeft, bool fromTop);

        void update();
        void draw(sf::RenderTarget& target);
        void handleEvents(sf::Event& event);

    private:
        int mRunSpeed;
        int mJumpSpeed;
        bool mGrounded;
        std::size_t mDirection;
};

#endif // PLAYER_H
