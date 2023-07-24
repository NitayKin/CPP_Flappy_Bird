#include <SFML/Graphics.hpp>

class MoveableCircleShape : sf::CircleShape
{
private:
	int speed;
public:
	void move_circle();
};
