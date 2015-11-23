#include "Player.h"

#include "Direction.h"

Player::Player(SpriteInfo& info, sf::Vector2f pos) :
    SpriteObject(info, pos),
    ICollideable(info.mHitBox, info.mFrameDim, pos)
{
    mRunSpeed = 3.f;
    mJumpSpeed = 6.f;
    mGrounded = false;
    mDirection = Direction::STILL_LEFT;
}

Player::~Player()
{
    //dtor
}

void Player::update()
{
    SpriteObject::update();

    mOldPhysicsPosition = mPhysicsPosition;
    mPhysicsPosition += mVelocity;

    // animations
    if (!mGrounded) // above ground
    {
        if (mDirection == Direction::LEFT)
            setFrameLoop(33, 33);
        else if (mDirection == Direction::STILL_LEFT)
            setFrameLoop(35, 35);

        else if (mDirection == Direction::RIGHT)
            setFrameLoop(30, 30);
        else if (mDirection == Direction::STILL_RIGHT)
            setFrameLoop(32, 32);
    }
    else if (mGrounded) // walking on ground
    {
        if (mDirection == Direction::LEFT)
            setFrameLoop(12, 17);
        else if (mDirection == Direction::STILL_LEFT)
            setFrameLoop(0, 5);

        else if (mDirection == Direction::RIGHT)
            setFrameLoop(18, 23);
        else if (mDirection == Direction::STILL_RIGHT)
            setFrameLoop(6, 11);
    }
}

void Player::draw(sf::RenderTarget& target)
{
    SpriteObject::draw(target);

    mRenderPosition = mPhysicsPosition;
}

void Player::handleEvents(sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Space && mGrounded)
        {
            mVelocity.y = -mJumpSpeed;
            mGrounded = false;
        }
        if (event.key.code == sf::Keyboard::A)
        {
            mVelocity.x = -mRunSpeed;
            mDirection = Direction::LEFT;
        }
        else if (event.key.code == sf::Keyboard::D)
        {
            mVelocity.x = mRunSpeed;
            mDirection = Direction::RIGHT;
        }
    }
    else if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == sf::Keyboard::W)
        {
            //mVelocity.y = 0.f;
        }
        if (event.key.code == sf::Keyboard::A)
        {
            mVelocity.x = 0.f;
            mDirection = Direction::STILL_LEFT;
        }
        else if (event.key.code == sf::Keyboard::D)
        {
            mVelocity.x = 0.f;
            mDirection = Direction::STILL_RIGHT;
        }
    }
}

bool Player::onContactBegin(std::weak_ptr<ICollideable> object, bool fromLeft, bool fromTop)
{
    mGrounded = true;
}
