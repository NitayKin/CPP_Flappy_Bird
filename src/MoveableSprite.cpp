#include <SFML/Graphics.hpp>
#include "MoveableSprite.hpp"

void MoveableSprite::tick_update()
{
	sf::Vector2f grav_force = {0,-9.81 * this->mass};
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		this->acceleration += {20,0};

}

MoveableSprite::MoveableSprite(sf::Texture Texture) : sf::Sprite(Texture)
{
	this->acceleration = {0,0};
	this->velocity = {5.0f,5.0f};
	this->net_force = {0,0};
}
