#ifndef WORLDOBJECT_H
#define WORLDOBJECT_H

#include "SpriteObject.h"
#include "ICollideable.h"

class WorldObject : public SpriteObject, public ICollideable
{
    public:
        WorldObject(SpriteInfo& info, sf::Vector2f pos, bool _static = false);
        ~WorldObject();

        void update();
        void draw(sf::RenderTarget& target);

    private:
};

#endif // WORLDOBJECT_H
