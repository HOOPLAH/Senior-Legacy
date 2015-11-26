#include "Assets.h"

std::map<std::string, SpriteInfo> Assets::sprites;

void Assets::loadAssets()
{
    sprites["ammocrate"] = SpriteInfo("Content/Textures/ammocrate.png");
    sprites["grassblock"] = SpriteInfo("Content/Textures/grass_block.png");
    sprites["tilegrassblock"] = SpriteInfo("Content/Textures/grass_block_tileable.png");
    sprites["tallrock"] = SpriteInfo("Content/Textures/tall_rock.png");
    sprites["ladder"] = SpriteInfo("Content/Textures/ladder.png");
    sprites["cloud"] = SpriteInfo("Content/Textures/cloud.png");
    sprites["background"] = SpriteInfo("Content/Textures/background.png");
    sprites["blackhole"] = SpriteInfo("Content/Textures/blackhole.png");

    sprites["bluepeewee"] = SpriteInfo("Content/Textures/bluepeewee.png", 36, 6);
    sprites["bluepeewee"].mHitBox = sf::FloatRect(20.f, 10.f, 24.f, 44.f);
    sprites["bridge"] = SpriteInfo("Content/Textures/bridge.png");
    sprites["bridge"].mHitBox = sf::FloatRect(6.f, 37.f, 140.f, 6.f);
}
