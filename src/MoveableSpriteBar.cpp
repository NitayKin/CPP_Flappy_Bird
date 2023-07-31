#include "MoveableSpriteBar.hpp"

MoveableSpriteBar::MoveableSpriteBar(sf::Texture& Texture, float mass) :
    MoveableSprite(Texture),
    mass(mass),
    velocity(-GRAV_CONST * mass, 0.0f)
{
}


void MoveableSpriteBar::tick_update()
{
	if(abs(velocity.x) < abs(-GRAV_CONST * mass * 3))
		velocity = velocity + sf::Vector2f(velocity.x*0.0002f,0);
	this->move(velocity);
}

MoveableSpriteBar::~MoveableSpriteBar()
{
}
