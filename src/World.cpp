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

	upper_bar_sprite->setPosition(sf::Vector2f(BACKGROUND_WIDTH,0.0f));
	bottom_bar_sprite->setPosition(sf::Vector2f(BACKGROUND_WIDTH,BACKGROUND_HEIGHT-BAR_HEIGHT));
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
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> distribution_bar_height(0.4f, 2.f);
    float scale_top_bar= distribution_bar_height(gen);
    std::uniform_real_distribution<float> distribution_gap_height(0.75f, 1.f);
    float scale_gap_height = distribution_gap_height(gen);
    float scale_bottom_bar= BARS_FIT_BACKGROUND - (scale_top_bar + GAP_BETWEEN_BARS*scale_gap_height);
	for(auto sprite : objects)
		sprite->tick_update();
	for( auto obj = objects.begin() + 1; obj!=objects.end();++obj){
		sf::FloatRect obj_bounds = (*obj)->getGlobalBounds();
		sf::FloatRect window_bounds(0.f, 0.f, BACKGROUND_WIDTH,BACKGROUND_HEIGHT);
		sf::FloatRect intersec_bar_bounds(-BAR_WIDTH, 0.f, BAR_WIDTH,BAR_HEIGHT);
		if (!window_bounds.intersects(obj_bounds)){
			if(intersec_bar_bounds.intersects(obj_bounds)){
				g_score++;
				(*obj)->setPosition(sf::Vector2f(BACKGROUND_WIDTH-BAR_WIDTH,0.0f));
				(*obj)->setScale(1, 1); //return to base
				(*obj)->scale(sf::Vector2f(1,scale_top_bar));
			}
			else{
				(*obj)->setPosition(sf::Vector2f(BACKGROUND_WIDTH-BAR_WIDTH,BACKGROUND_HEIGHT-BAR_HEIGHT*scale_bottom_bar));
				(*obj)->setScale(1, 1); //return to base
				(*obj)->scale(sf::Vector2f(1,scale_bottom_bar));
			}
		}
	}
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
