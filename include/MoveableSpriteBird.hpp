#ifndef MoveableSpriteBird_Guard
#define MoveableSpriteBird_Guard

#include <SFML/Graphics.hpp>
#include <iostream>
#include "MoveableSprite.hpp"

class MoveableSpriteBird : public MoveableSprite
{
private:
	sf::Vector2f velocity;
	float mass;

public:
	MoveableSpriteBird(sf::Texture&,float);
	virtual void tick_update();
	~MoveableSpriteBird();
};



#endif
