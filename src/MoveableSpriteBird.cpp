#include "MoveableSpriteBird.hpp"

MoveableSpriteBird::MoveableSpriteBird(sf::Texture& Texture, float mass) :
	MoveableSprite(Texture),
    mass(mass),
    velocity(0.0f, 0.0f)
{
}


void MoveableSpriteBird::tick_update()
{
	sf::Vector2f current_acceleration = {0,GRAV_CONST * this->mass};
	if (g_command_from_python)
		velocity = sf::Vector2f(0,-150.0f*this->mass);
	velocity+=current_acceleration;
	this->move(velocity);
}

MoveableSpriteBird::~MoveableSpriteBird()
{
}
