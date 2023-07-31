#include "Globals.hpp"

uint64_t score = 0;

bool check_collision(const sf::Sprite* object1,const sf::Sprite* object2)
{
    sf::FloatRect bounds1 = object1->getGlobalBounds();
    sf::FloatRect bounds2 = object2->getGlobalBounds();

    return bounds1.intersects(bounds2);
}
