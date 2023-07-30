#ifndef INCLUDE_MOVEABLESPRITE_HPP_
#define INCLUDE_MOVEABLESPRITE_HPP_

#include <SFML/Graphics.hpp>

class MoveableSprite : public sf::Sprite {
public:
	MoveableSprite(sf::Texture& texture):sf::Sprite(texture){};
    virtual void tick_update() = 0;
    virtual ~MoveableSprite() = default;
};


#endif
