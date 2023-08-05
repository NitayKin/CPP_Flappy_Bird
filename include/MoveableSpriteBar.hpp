#ifndef MoveableSpriteBar_Guard
#define MoveableSpriteBar_Guard

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Globals.hpp"
#include "MoveableSprite.hpp"

class MoveableSpriteBar : public MoveableSprite
{
public:
	sf::Vector2f velocity;
	float mass;

	MoveableSpriteBar(sf::Texture&,float);
	virtual void tick_update();
	~MoveableSpriteBar();
};
#endif
