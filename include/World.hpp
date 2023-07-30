#ifndef INCLUDE_WORLD_HPP_
#define INCLUDE_WORLD_HPP_
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

#include "Globals.hpp"
#include "MoveableSprite.hpp"
#include "MoveableSpriteBar.hpp"
#include "MoveableSpriteBird.hpp"

class World{
private:
	std::vector<MoveableSprite*> objects;
	sf::Texture birdy_texture;
	sf::Texture upper_bar_texture;
	sf::Texture bottom_bar_texture;

public:
	World();
	std::vector<MoveableSprite*>& get_objects();
	void tick_update();
	bool check_lose();
	~World();
};



#endif
