#include "MoveableSpriteBar.hpp"

MoveableSpriteBar::MoveableSpriteBar(sf::Texture& Texture, float mass) :
    MoveableSprite(Texture),
    mass(mass),
    velocity(0.0f, 0.0f)
{
}


void MoveableSpriteBar::tick_update()
{
	sf::Vector2f current_acceleration = {-9.81f * this->mass,0};
	velocity=current_acceleration;
	this->move(velocity);
}

MoveableSpriteBar::~MoveableSpriteBar()
{
}
