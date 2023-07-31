#ifndef INCLUDE_GLOBALS_HPP_
#define INCLUDE_GLOBALS_HPP_

#include <SFML/Graphics.hpp>

#define BACKGROUND_HEIGHT 720.0f
#define BACKGROUND_WIDTH 1024.0f

#define GRAV_CONST 9.84f

#define BAR_HEIGHT 165.0f
#define BAR_WIDTH 53.0f

extern uint64_t score;


bool check_collision(const sf::Sprite*,const sf::Sprite*);

#endif /* INCLUDE_GLOBALS_HPP_ */
