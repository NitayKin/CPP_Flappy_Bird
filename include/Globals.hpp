#ifndef INCLUDE_GLOBALS_HPP_
#define INCLUDE_GLOBALS_HPP_

#include <SFML/Graphics.hpp>

#define BACKGROUND_HEIGHT 720.0f
#define BACKGROUND_WIDTH 1024.0f

#define GRAV_CONST 9.84f

#define BAR_HEIGHT 165.0f
#define BAR_WIDTH 53.0f

#define BARS_FIT_BACKGROUND (BACKGROUND_HEIGHT/BAR_HEIGHT)

#define GAP_BETWEEN_BARS ((BAR_HEIGHT*1.5f)/BAR_HEIGHT)

extern uint64_t g_score;
extern int g_command_from_python;


bool check_collision(const sf::Sprite*,const sf::Sprite*);

#endif /* INCLUDE_GLOBALS_HPP_ */
