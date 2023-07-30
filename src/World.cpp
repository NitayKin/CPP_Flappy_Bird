#include "World.hpp"


World::World()
{
	if (!birdy_texture.loadFromFile("assets/birdy.png"))
	{
		std::cout << "Failed to load birdy.png" << std::endl;
	}
	if (!upper_bar_texture.loadFromFile("assets/upper_bar.png"))
	{
		std::cout << "Failed to load upper_bar.png" << std::endl;
	}
	if (!bottom_bar_texture.loadFromFile("assets/bottom_bar.png"))
	{
		std::cout << "Failed to load bottom_bar.png" << std::endl;
	}

	MoveableSpriteBird* birdy_sprite = new MoveableSpriteBird(birdy_texture,0.1f);
	birdy_sprite->scale(sf::Vector2f(0.1,0.1));
	MoveableSpriteBar* upper_bar_sprite = new MoveableSpriteBar(upper_bar_texture,1.0f);
	MoveableSpriteBar* bottom_bar_sprite = new MoveableSpriteBar(bottom_bar_texture,1.0f);

	upper_bar_sprite->setPosition(sf::Vector2f(BACKGROUND_WIDTH-BAR_WIDTH,0.0f));
	bottom_bar_sprite->setPosition(sf::Vector2f(BACKGROUND_WIDTH-BAR_WIDTH,BACKGROUND_HEIGHT-BAR_HEIGHT));
	objects.push_back(birdy_sprite);
	objects.push_back(upper_bar_sprite);
	objects.push_back(bottom_bar_sprite);
}

std::vector<MoveableSprite*>& World::get_objects()
{
	return objects;
}

void World::tick_update()
{
	for(auto sprite : objects)
		sprite->tick_update();
}

bool World::check_lose()
{
	//check for bar collision
	MoveableSprite* birdy = objects[0];
	for( auto obj = objects.begin() + 1; obj!=objects.end();++obj){
		if(check_collision(birdy,*obj))
			return true;
	}

	//check for off-world collision
    sf::FloatRect windowBounds(0.f, 0.f, BACKGROUND_WIDTH,BACKGROUND_HEIGHT);
    return (!windowBounds.intersects(birdy->getGlobalBounds()));
}

World::~World()
{
}
