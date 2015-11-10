#include "WorldObject.h"

WorldObject::WorldObject(SpriteInfo& info, sf::Vector2f pos) :
    SpriteObject(info, pos),
    ICollideable(info.mHitBox, info.mFrameDim, pos)
{
    //ctor
}

WorldObject::~WorldObject()
{
    //dtor
}

void WorldObject::update()
{
    SpriteObject::update();

    mOldPhysicsPosition = mPhysicsPosition;
    mPhysicsPosition += mVelocity;
}

void WorldObject::draw(sf::RenderTarget& target)
{
    SpriteObject::draw(target);

    mRenderPosition = mPhysicsPosition;
}
